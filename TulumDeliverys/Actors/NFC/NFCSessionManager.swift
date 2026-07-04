//
//  NFCSessionManager.swift
//  SoftPOS

import Foundation
import CoreNFC
import CryptoKit

/// The NFC Core Layer responsible for:
/// 1. Polling for ISO-14443 Type A/B cards.
/// 2. Exchanging APDUs (SELECT, GPO, READ RECORD).
/// 3. Parsing TLV responses to extract EMV data.
/// 4. Forwarding the raw cryptogram and PAN to the orchestration layer.
actor NFCSessionManager: NSObject {
    
    // MARK: - Singleton
    static let shared = NFCSessionManager()
    private override init() { super.init() }
    
    // MARK: - Public Types
    enum NFCError: Error {
        case unsupportedTag
        case nfcUnavailable
        case apduFailed(sw1: UInt8, sw2: UInt8)
        case missingData(String)
        case userCancelled
        case sessionTimeout
        case invalidAPDU
    }
    
    struct EMVCardData: Sendable {
        let pan: String              // Masked for logging, full for transport
        let expiry: String           // YYMM
        let applicationLabel: String // e.g., "VISA CREDIT"
        let aid: String              // Application ID (hex)
        let afl: [UInt8]             // Application File Locator (for internal use)
        let cdol1: Data              // Card Risk Management Data Object List
        let cryptogram: Data         // 9F26 - Application Cryptogram (mock or real)
        let unpredictableNumber: Data // 9F37 - The UDN we provided
        let issuerAppData: Data      // 9F10 - Issuer Application Data (optional)
    }
    
    // MARK: - Private State
    private var session: NFCTagReaderSession?
    private var continuation: CheckedContinuation<EMVCardData, Error>?
    
    // MARK: - Public Interface
    
    /// Starts the NFC reader session and reads the payment card data.
    /// Returns an `EMVCardData` containing all necessary tags for the Cloud Kernel.
    func readPaymentCard() async throws -> EMVCardData {
        guard NFCTagReaderSession.readingAvailable else {
            throw NFCError.nfcUnavailable
        }
        
        return try await withCheckedThrowingContinuation { continuation in
            self.continuation = continuation
            let session = NFCTagReaderSession(pollingOption: [.iso14443, .iso18092],
                                              delegate: self)
            self.session = session
            session?.alertMessage = NSLocalizedString("Hold your card near the phone to pay.", comment: "")
            session?.begin()
        }
    }
    //iso14443: Detects ISO 7816-compatible tags, including MIFARE tags (e.g., MIFARE Ultralight, Classic, DESFire).
    //iso15693: Detects ISO 15693 tags (commonly used for access control, inventory, and smart posters).
    //iso18092: Detects FeliCa tags (popular in Japan, often used in transit cards like Suica, or loyalty systems).
    //pace: Detects tags using Password Authenticated Connection Establishment (often required for secure electronic passport reading/ePassports)
    
    // MARK: - Internal APDU Helpers
    
    private func buildAPDU(cla: UInt8, ins: UInt8, p1: UInt8, p2: UInt8, data: Data = Data(), le: UInt8? = nil) -> Data {
        var command = Data([cla, ins, p1, p2])
        if !data.isEmpty {
            command.append(UInt8(data.count))
            command.append(contentsOf: data)
        } else if let le = le {
            command.append(le)
        }
        if let le = le, !data.isEmpty {
            command.append(le)
        }
        return command
    }
    
    /// Sends an APDU and validates the SW1/SW2 response.

    private func sendAPDU(_ apduData: Data, to tag: NFCISO7816Tag) async throws -> Data {
        // 1. Convert raw Data into a proper NFCISO7816APDU object.
        guard let apdu = NFCISO7816APDU(data: apduData) else {
            throw NFCError.invalidAPDU
        }
        // 2. Send the APDU using the strongly-typed object.
        return try await withCheckedThrowingContinuation { continuation in
            tag.sendCommand(apdu: apdu) { responseData, sw1, sw2, error in
                if let error = error {
                    continuation.resume(throwing: error)
                    return
                }
                if sw1 == 0x90 && sw2 == 0x00 {
                    continuation.resume(returning: responseData)
                } else {
                    continuation.resume(throwing: NFCError.apduFailed(sw1: sw1, sw2: sw2))
                }
            }
        }
    }
    
    // MARK: - Private Actor-Isolated Handlers
    
    private func handleDidBecomeActive(session: NFCTagReaderSession) {
        print("📡 NFC Session Active. Waiting for tap...")
    }
    
    private func handleDidInvalidate(session: NFCTagReaderSession, error: Error) {
        // Only resume if we haven't already finished successfully.
        guard let continuation = continuation else { return }
        
        if let nfcError = error as? NFCReaderError,
           nfcError.code == .readerSessionInvalidationErrorUserCanceled {
            continuation.resume(throwing: NFCError.userCancelled)
        } else {
            continuation.resume(throwing: error)
        }
        self.continuation = nil
        self.session = nil
    }
    
    private func handleDidDetect(session: NFCTagReaderSession, tags: [NFCTag]) {
        guard let tag = tags.first else {
            session.invalidate(errorMessage: "No card detected. Try again.")
            return
        }
        
        switch tag {
        case .iso7816(let iso7816Tag):
            session.connect(to: tag) { [weak self] error in
                if let error = error {
                    session.invalidate(errorMessage: "Connection failed: \(error.localizedDescription)")
                    Task { await self?.continuation?.resume(throwing: error) }
                    Task { await self?.setContinuation(nil) }
                    return
                }
                Task { [weak self] in
                    await self?.processISO7816Tag(iso7816Tag, session: session)
                }
            }
            
        default:
            session.invalidate(errorMessage: "Unsupported card type. Please use a contactless credit/debit card.")
            continuation?.resume(throwing: NFCError.unsupportedTag)
            continuation = nil
        }
    }
    
    private func setContinuation(_ continuation: CheckedContinuation<EMVCardData, Error>?) {
        self.continuation = continuation
    }
    
    // MARK: - EMV Processing Pipeline
    
    private func processISO7816Tag(_ tag: NFCISO7816Tag, session: NFCTagReaderSession) async {
        do {
            // Step 1: SELECT PPSE
            let selectPPSE = Data([0x00, 0xA4, 0x04, 0x00, 0x0E, 0x32, 0x50, 0x41,
                                   0x59, 0x2E, 0x53, 0x59, 0x53, 0x2E, 0x44, 0x44,
                                   0x46, 0x30, 0x31, 0x00])
            let ppseResponse = try await sendAPDU(selectPPSE, to: tag)
            print("✅ SELECT PPSE Response: \(ppseResponse.hexString)")
            
            // Step 2: Parse AID
            guard let aidData = TLV.firstValue(for: "4F", in: ppseResponse) else {
                throw NFCError.missingData("AID not found in PPSE response")
            }
            let aid = aidData.hexString
            print("🔑 Found AID: \(aid)")
            
            // Step 3: SELECT AID
            let selectAID = buildAPDU(cla: 0x00, ins: 0xA4, p1: 0x04, p2: 0x00, data: aidData)
            let aidResponse = try await sendAPDU(selectAID, to: tag)
            print("✅ SELECT AID Response: \(aidResponse.hexString)")
            
            // Step 4: Extract CDOL1 and PDOL
            let pdolData = TLV.firstValue(for: "9F38", in: aidResponse) ?? Data()
            let cdol1Data = TLV.firstValue(for: "8C", in: aidResponse) ?? Data()
            print("📋 PDOL: \(pdolData.hexString)")
            print("📋 CDOL1: \(cdol1Data.hexString)")
            
            // Step 5: Build GPO
            let gpoPayload: Data
            if pdolData.isEmpty {
                gpoPayload = Data([0x83, 0x00])
            } else {
                let terminalTransactionData = Data([0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
                var tlv83 = Data([0x83, 0x08])
                tlv83.append(terminalTransactionData)
                gpoPayload = tlv83
            }
            
            let gpoCommand = buildAPDU(cla: 0x80, ins: 0xA8, p1: 0x00, p2: 0x00, data: gpoPayload, le: 0x00)
            let gpoResponse = try await sendAPDU(gpoCommand, to: tag)
            print("✅ GPO Response: \(gpoResponse.hexString)")
            
            // Step 6: Extract AFL
            guard let aflData = TLV.firstValue(for: "94", in: gpoResponse) else {
                throw NFCError.missingData("AFL not found in GPO response")
            }
            let afl = [UInt8](aflData)
            print("📂 AFL: \(afl.map { String(format: "%02X", $0) }.joined())")
            
            // Step 7: READ RECORD
            var pan: String = ""
            var expiry: String = ""
            var appLabel: String = ""
            var issuerAppData: Data = Data()
            
            for i in stride(from: 0, to: afl.count, by: 4) {
                let sfi = afl[i] >> 3
                let startRec = afl[i+1]
                let endRec = afl[i+2]
                
                for recNum in startRec...endRec {
                    let p1 = (sfi << 3) | 0x04
                    let recordCommand = buildAPDU(cla: 0x00, ins: 0xB2, p1: recNum, p2: p1, le: 0x00)
                    let recordData = try await sendAPDU(recordCommand, to: tag)
                    print("📄 Read Record \(recNum) SFI \(sfi): \(recordData.hexString)")
                    
                    let tlvs = TLV.parse(recordData)
                    for tlv in tlvs {
                        switch tlv.tag {
                        case "5A":
                            pan = tlv.value.hexString
                            print("💳 PAN: \(pan)")
                        case "5F24":
                            expiry = tlv.value.hexString
                            print("📅 Expiry: \(expiry)")
                        case "50":
                            if let label = String(data: tlv.value, encoding: .utf8) {
                                appLabel = label
                                print("🏷️ App Label: \(label)")
                            }
                        case "9F10":
                            issuerAppData = tlv.value
                            print("🏦 Issuer Data: \(issuerAppData.hexString)")
                        default:
                            break
                        }
                    }
                }
            }
            
            // Step 8: Generate Unpredictable Number & Mock Cryptogram
            let unpredictableNumber = Data((0..<4).map { _ in UInt8.random(in: 0...255) })
            print("🎲 Unpredictable Number: \(unpredictableNumber.hexString)")
            let mockCryptogram = Data([0x9F, 0x26] + (0..<8).map { _ in UInt8.random(in: 0...255) })
            
            // Step 9: Build final data
            let cardData = EMVCardData(
                pan: pan,
                expiry: expiry,
                applicationLabel: appLabel.isEmpty ? "Unknown Card" : appLabel,
                aid: aid,
                afl: afl,
                cdol1: cdol1Data,
                cryptogram: mockCryptogram,
                unpredictableNumber: unpredictableNumber,
                issuerAppData: issuerAppData
            )
            
            session.alertMessage = "✅ Payment read successful!"
            session.invalidate()
            continuation?.resume(returning: cardData)
            continuation = nil
            
        } catch {
            print("❌ EMV Processing Error: \(error)")
            session.invalidate(errorMessage: "Processing failed: \(error.localizedDescription)")
            continuation?.resume(throwing: error)
            continuation = nil
        }
    }
}

// MARK: - NFCTagReaderSessionDelegate (Nonisolated)

extension NFCSessionManager: NFCTagReaderSessionDelegate {
    
    nonisolated func tagReaderSessionDidBecomeActive(_ session: NFCTagReaderSession) {
        Task { await self.handleDidBecomeActive(session: session) }
    }
    
    nonisolated func tagReaderSession(_ session: NFCTagReaderSession, didInvalidateWithError error: Error) {
        Task { await self.handleDidInvalidate(session: session, error: error) }
    }
    
    nonisolated func tagReaderSession(_ session: NFCTagReaderSession, didDetect tags: [NFCTag]) {
        Task { await self.handleDidDetect(session: session, tags: tags) }
    }
}

// MARK: - Data Extensions

extension Data {
    var hexString: String {
        return map { String(format: "%02X", $0) }.joined()
    }
}

//This is the main workhorse. APDU sequence required to read a contactless EMV card.

//
//  NFCSessionManagerLegacy.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 05/07/26.
//
// Core/NFC/NFCSessionManagerLegacy.swift
import Foundation
import CoreNFC

final class NFCSessionManagerLegacy: NSObject, NFCTagReaderSessionDelegate {
    static let shared = NFCSessionManagerLegacy()
    private override init() { super.init() }
    
    private var session: NFCTagReaderSession?
    private var continuation: CheckedContinuation<EMVCardData, Error>?
    
    func readPaymentCard() async throws -> EMVCardData {
        guard NFCTagReaderSession.readingAvailable else {
            throw NFCSessionManager.NFCError.nfcUnavailable
        }
        
        return try await withCheckedThrowingContinuation { continuation in
            
            self.continuation = continuation
            
            DispatchQueue.main.async { [weak self] in
                guard let self = self else {
                    return
                }
                let session = NFCTagReaderSession(pollingOption: [.iso14443],
                                                  delegate: self,
                                                  queue: .main)
                self.session = session
                session?.alertMessage = "Hold your card near the phone to pay."
                session?.begin()
            }
        }
    }
    
    // MARK: - NFCTagReaderSessionDelegate
    
    func tagReaderSessionDidBecomeActive(_ session: NFCTagReaderSession) {
        print("📡 NFC Session Active")
    }
    
    func tagReaderSession(_ session: NFCTagReaderSession, didInvalidateWithError error: Error) {
        guard let continuation = continuation else { return }
        
        if let nfcError = error as? NFCReaderError,
           nfcError.code == .readerSessionInvalidationErrorUserCanceled {
            continuation.resume(throwing: NFCSessionManager.NFCError.userCancelled)
        } else {
            continuation.resume(throwing: error)
        }
        self.continuation = nil
        self.session = nil
    }
    
    func tagReaderSession(_ session: NFCTagReaderSession, didDetect tags: [NFCTag]) {
        guard let tag = tags.first else {
            session.invalidate(errorMessage: "No card detected")
            return
        }
        
        session.alertMessage = "✅ Card detected!"
        session.invalidate()
        
        let testData = EMVCardData(
            pan: "4111111111111111",
            expiry: "2601",
            applicationLabel: "Test Card",
            aid: "A0000000031010",
            afl: [],
            cdol1: Data(),
            cryptogram: Data([0x9F, 0x26] + (0..<8).map { _ in UInt8.random(in: 0...255) }),
            unpredictableNumber: Data([0x00, 0x01, 0x02, 0x03]),
            issuerAppData: Data()
        )
        
        continuation?.resume(returning: testData)
        continuation = nil
    }
}

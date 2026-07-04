//
//  ZViewModelBad.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 26/06/26.
//

import Foundation
import SwiftUI

@Observable
final class SoftPOSVM {
    
    // MARK: - Dependencies
    private let securityManager: SecurityManager
    private let nfcManager: NFCSessionManager
       
    // MARK: - UI State
    private(set) var statusMessage = "Ready to Tap"
    private(set) var isProcessing = false
    
    init(securityManager: SecurityManager, nfcManager: NFCSessionManager) {
        //TODO: will change type to protocol & move to repository layer
        self.securityManager = securityManager
        self.nfcManager = nfcManager
    }
    
    // MARK: - Full Payment Flow (Phase 1 + 2 Integrated)
    func startPaymentFlow() async {
        
        guard !isProcessing else { return }
        isProcessing = true
        statusMessage = "📡 Hold your card near the top of the phone..."
        
        do {
            // Step 1: Read the card via CoreNFC (Phase 2)
            let cardData = try await nfcManager.readPaymentCard()
            
            // Step 2: Mask the PAN for UI safety
            let maskedPan = String(cardData.pan.prefix(6)) + "******" + String(cardData.pan.suffix(4))
            statusMessage = "💳 Card Read: \(maskedPan)\n⏳ Encrypting & Sending..."
            
            // Step 3: Build the P2PE Transaction Payload
            let transaction = TransactionPayload(
                transactionId: UUID().uuidString,
                amount: "12.99",
                currency: "USD",
                pan: cardData.pan,
                expiry: cardData.expiry,
                cryptogram: cardData.cryptogram.hexString,
                unpredictableNumber: cardData.unpredictableNumber.hexString,
                aid: cardData.aid,
                issuerAppData: cardData.issuerAppData.hexString
            )
            
            // Step 4: Send through the Secure Transport Layer (Phase 1)
            // This automatically attaches OAuth2, Certificate Pinning, and TSM Attestation.
            let endpoint = "https://mock.paycloud.com/v1/softpos/process"
            let responseData = try await securityManager.sendSecurePayload(transaction, to: endpoint)
            
            // Step 5: Parse the mock response
            if let json = try? JSONSerialization.jsonObject(with: responseData) as? [String: Any],
               let status = json["status"] as? String {
                if status == "APPROVED" {
                    statusMessage = "✅ Transaction Approved!\nReference: \(json["reference"] ?? "N/A")"
                } else {
                    statusMessage = "❌ Transaction Declined: \(json["reason"] ?? "Unknown")"
                }
            } else {
                statusMessage = "✅ Transaction Complete (Mock)"
            }
            
        } catch NFCSessionManager.NFCError.userCancelled {
            statusMessage = "❌ Cancelled by user."
        } catch {
            statusMessage = "❌ Error: \(error.localizedDescription)"
        }
        
        isProcessing = false
    }
}

//The app prompts you to tap a card.
//It reads the EMV data (PAN, expiry, cryptogram).
//It packages that data into a payload.
//It attaches OAuth2 Bearer tokens, Certificate Pinning, and a Secure Enclave attestation signature.
//It "sends" it to the mock cloud and shows an approval.

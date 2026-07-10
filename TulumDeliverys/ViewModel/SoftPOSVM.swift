//
//  ZViewModelBad.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 26/06/26.
//

import Foundation
import SwiftUI
import PayCloudTSMSDK

@Observable
final class SoftPOSVM {
    
    // MARK: - Dependencies
    private let orchestrator: TransactionOrchestrator
       
    // MARK: - UI State
    private(set) var statusMessage = "Ready to Tap"
    private(set) var isProcessing = false
    private(set) var isApproved: Bool = false
    private(set) var isDeclined: Bool = false
    private(set) var showError: Bool = false
    private(set) var errorMessage: String = ""
    //Sec Apple TSM
    private(set) var tsmStatus = "TSM: Not Started"
    private(set) var isProvisioning = false
    
    // MARK: - State Observation
    private var stateObservationTask: Task<Void, Never>?
    
    init(orchestrator: TransactionOrchestrator = TransactionOrchestrator()) {
        self.orchestrator = orchestrator
        startObservingState()
    }
    
    deinit {
        stateObservationTask?.cancel()
    }
    
    // MARK: - Observing State Stream
    private func startObservingState() {
        stateObservationTask = Task { [weak self] in
            for await state in await self?.orchestrator.stateStream() ?? AsyncStream { _ in } {
                // Update UI state on the main actor (SwiftUI requires main thread)
                await MainActor.run {
                    self?.updateUI(for: state)
                }
            }
        }
    }
    
    @MainActor
    private func updateUI(for state: TransactionState) {
        statusMessage = state.displayMessage
        isProcessing = state.isProcessing
        
        switch state {
        case .approved:
            isApproved = true
            isDeclined = false
            showError = false
        case .declined:
            isApproved = false
            isDeclined = true
            showError = false
        case .error(let msg):
            isApproved = false
            isDeclined = false
            showError = true
            errorMessage = msg
        case .cancelled, .idle:
            isApproved = false
            isDeclined = false
            showError = false
        default:
            // No terminal state change
            break
        }
    }
    
    func addCardSDK() {
       
        Task {
            do {
                let billingAddress = BillingAddress(
                    line1: "123 Main St",
                    city: "San Francisco",
                    state: "CA",
                    postalCode: "94105",
                    country: "USA"
                )
                
                let response = try await PayCloudSDK.shared.addCard(
                    encryptedCardData: "base64_encrypted_blob",
                    cardholderName: "John Doe",
                    billingAddress: billingAddress,
                    pushToken: "apns_token_here" // optional async flow
                )
                print("Card added with ID: \(response.cardId)")
            } catch {
                print("Error: \(error)")
            }
        }
    }
    
    func observeCredentials(){
        Task {
            for await credentials in PayCloudSDK.shared.currentCredentials {
                print("Updated credentials: \(credentials)")
            }
        }
    }
    // MARK: - Full Payment Flow
   func startPaymentFlow() {
       Task {
           await orchestrator.startTransaction()
       }
   }
   
   func resetPaymentFlow() {
       Task {
           await orchestrator.reset()
       }
       // Reset UI flags immediately (optimistic)
       isApproved = false
       isDeclined = false
       showError = false
       errorMessage = ""
   }
    
    func performTSMProvisioning() async {
         isProvisioning = true
         tsmStatus = "⏳ Starting TSM flow..."
         
         let tsm = TSMProvisioningService.shared
         
         guard tsm.isSupported else {
             tsmStatus = "❌ AppAttest not supported on this device."
             isProvisioning = false
             return
         }
         
         do {
             // 1. Check if we have a key, generate if needed
             tsmStatus = "🔑 Generating attestation key..."
             let keyId = try await tsm.getOrCreateAttestationKey()
             print("Key ID: \(keyId)")
             // 2. Perform the full provisioning flow
             tsmStatus = "🔒 Attesting with backend challenge..."
             let token = try await tsm.performFullProvisioningFlow()
             
             tsmStatus = "✅ Provisioning successful!\nToken: \(token.prefix(16))..."
             // Optional: Present Apple's Wallet UI in production
             // let addPassVC = PKAddPaymentPassViewController(...)
         } catch {
             tsmStatus = "❌ TSM Error: \(error.localizedDescription)"
         }
         
         isProvisioning = false
     }
    
}

//The app prompts you to tap a card.
//It reads the EMV data (PAN, expiry, cryptogram).
//It packages that data into a payload.
//It attaches OAuth2 Bearer tokens, Certificate Pinning, and a Secure Enclave attestation signature.
//It "sends" it to the mock cloud and shows an approval.

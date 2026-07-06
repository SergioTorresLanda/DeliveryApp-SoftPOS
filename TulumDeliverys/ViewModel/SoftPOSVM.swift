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
    private let orchestrator: TransactionOrchestrator
       
    // MARK: - UI State
    private(set) var statusMessage = "Ready to Tap"
    private(set) var isProcessing = false
    private(set) var isApproved: Bool = false
    private(set) var isDeclined: Bool = false
    private(set) var showError: Bool = false
    private(set) var errorMessage: String = ""
    
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
    
}

//The app prompts you to tap a card.
//It reads the EMV data (PAN, expiry, cryptogram).
//It packages that data into a payload.
//It attaches OAuth2 Bearer tokens, Certificate Pinning, and a Secure Enclave attestation signature.
//It "sends" it to the mock cloud and shows an approval.

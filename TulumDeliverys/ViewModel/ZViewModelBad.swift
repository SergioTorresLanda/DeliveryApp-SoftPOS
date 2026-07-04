//
//  ZViewModelBad.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 26/06/26.
//

import Foundation
import Combine

class NFCPaymentSessionManager: ObservableObject {
    @Published var sessionState: String = "Idle"
    
    private var nfcPollingTask: Task<Void, Never>?
    private let secureElement: MockSecureElementService
    
    init(secureElement: MockSecureElementService) {
        self.secureElement = secureElement
    }
    
    func startTapToPhoneSession() {
        sessionState = "Looking for Card..."
        
        // Start listening to the continuous hardware NFC stream
        nfcPollingTask = Task { [weak self] in
            for await tapPayload in await secureElement.nfcTagStream() {
                
                // Log payload for QA debugging
                print("DEBUG - Card Tapped. Payload: \(tapPayload)")
                //Authenteti
                // Process the transaction
                let result = await secureElement.processPayment(payload: tapPayload, authToken: "")
                    // Update the UI with the result
                self?.sessionState = result.isSuccessful ? "Approved" : "Declined"
            }
        }
    }
    
    deinit {
        // Clean up the hardware session when this view goes away
        print("NFC Manager Deallocated")
        nfcPollingTask?.cancel()
    }
}


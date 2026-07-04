//
//  MockSecureElementService.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 26/06/26.
//
// import EMVCore
// import Wallet

// 1. Define the interface so we can swap the Real service for the Mock
protocol SecureElementServiceProtocol: Actor {
    func nfcTagStream() -> AsyncStream<String>
    func processPayment(payload: String, authToken: String) async -> PaymentResult
}

struct PaymentResult { let isSuccessful: Bool }

// 2. Build the Mock
actor MockSecureElementService: SecureElementServiceProtocol {
    
    // We store the continuation so our Unit Tests can push data into the stream at will
    private var streamContinuation: AsyncStream<String>.Continuation?
    
    func nfcTagStream() -> AsyncStream<String> {
        // Create an AsyncStream and steal its continuation
        return AsyncStream { continuation in
            self.streamContinuation = continuation
        }
    }
    
    // 3. TEST HELPER: Call this from your XCTest to simulate a user tapping their phone
    func simulateHardwareTap(payload: String) {
        streamContinuation?.yield(payload)
    }
    
    func processPayment(payload: String, authToken: String) async -> PaymentResult {
        // Return a mocked successful response
        return PaymentResult(isSuccessful: true)
    }
}

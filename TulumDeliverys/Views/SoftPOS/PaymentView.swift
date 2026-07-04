//
//  PaymentView.swift
//
//

import SwiftUI

struct PaymentView: View {
    @State private var statusMessage = "Ready to Tap"
    private let securityManager = SecurityManager.shared
    
    var body: some View {
        VStack(spacing: 30) {
            Text("PayCloud Terminal")
                .font(.largeTitle)
            Text(statusMessage)
                .font(.headline)
                .padding()
            
            Button("Simulate Secure Transaction") {
                Task {
                    await performMockTransaction()
                }
            }
            .buttonStyle(.borderedProminent)
        }
        .padding()
    }
    
    private func performMockTransaction() async {
        statusMessage = "Initializing Security..."
        
        do {
            // 1. Build a mock P2PE payload.
            let mockPayload: [String: String] = [
                "transaction_id": UUID().uuidString,
                "amount": "12.99",
                "currency": "USD",
                // In Phase 2, this would be the raw APDU cryptogram.
                "mock_cryptogram": "9F26123456789ABCDEF"
            ]
            
            // 2. Send it through the secure, pinned, attested channel.
            statusMessage = "Encrypting & Sending..."
            let endpoint = "https://mock.paycloud.com/v1/softpos/process"
            let responseData = try await securityManager.sendSecurePayload(mockPayload, to: endpoint)
            
            // 3. Process the mock response.
            if let responseString = String(data: responseData, encoding: .utf8) {
                statusMessage = "✅ Approved: \(responseString)"
            } else {
                statusMessage = "✅ Transaction Complete"
            }
            
        } catch {
            statusMessage = "❌ Error: \(error.localizedDescription)"
        }
    }
}

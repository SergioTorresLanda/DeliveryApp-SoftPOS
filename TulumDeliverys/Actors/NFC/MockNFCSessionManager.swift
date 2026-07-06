//
//  MockNFCSessionManager.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 05/07/26.
//

// Core/NFC/MockNFCSessionManager.swift
import Foundation

/// A deterministic mock of the NFC hardware layer.
/// Useful for UI development, testing, and when running on the Simulator.
final class MockNFCSessionManager: NFCSessionProtocol {
    
    enum MockBehavior {
        case success
        case decline
        case timeout
        case userCancelled
    }
    
    // Make it configurable for different test scenarios
    var behavior: MockBehavior = .success
    var simulatedDelay: UInt64 = 1_000_000_000 // 1 second
    
    init(behavior: MockBehavior = .success, delay: UInt64 = 1_000_000_000) {
        self.behavior = behavior
        self.simulatedDelay = delay
    }
    
    func readPaymentCard() async throws -> NFCSessionManager.EMVCardData {
        // Simulate the hardware delay
        try await Task.sleep(nanoseconds: simulatedDelay)
        
        switch behavior {
        case .success:
            print("✅ Mock NFC: Card read successfully.")
            return NFCSessionManager.EMVCardData(
                pan: "4111111111111111",
                expiry: "2601",
                applicationLabel: "VISA CREDIT",
                aid: "A0000000031010",
                afl: [0x01, 0x02, 0x03, 0x04],
                cdol1: Data([0x8C, 0x02, 0x9F, 0x37]),
                cryptogram: Data([0x9F, 0x26] + (0..<8).map { $0 }), // Deterministic: 00 01 02 03 04 05 06 07
                unpredictableNumber: Data([0xAA, 0xBB, 0xCC, 0xDD]),
                issuerAppData: Data([0x9F, 0x10, 0x04, 0xDE, 0xAD, 0xBE, 0xEF])
            )
            
        case .decline:
            // Simulate a decline response from the cloud (we can handle this later)
            throw NFCSessionManager.NFCError.apduFailed(sw1: 0x69, sw2: 0x85)
            
        case .timeout:
            throw NFCSessionManager.NFCError.sessionTimeout
            
        case .userCancelled:
            throw NFCSessionManager.NFCError.userCancelled
        }
    }
}

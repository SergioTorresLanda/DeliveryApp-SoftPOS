//
//  TSMProvisioningService.swift
//
import Foundation
import DeviceCheck
import Security
import CryptoKit
/// A Swift 6 actor that manages Apple's Trusted Service Manager (TSM) integration.
/// Uses DCAppAttestService to generate and attest device keys for Apple Wallet provisioning.
actor TSMProvisioningService {
    
    // MARK: - Singleton
    static let shared = TSMProvisioningService()
    private init() {}
    
    // MARK: - Dependencies
    private let attestService = DCAppAttestService.shared
    private let keychain = KeychainManager()
    
    // MARK: - Error Types
    enum TSMError: Error, Sendable {
        case unsupportedDevice               // Device does not support AppAttest
        case keyGenerationFailed(reason: String)
        case attestationFailed(reason: String)
        case keyNotFound
        case invalidChallenge
        case backendValidationFailed
    }
    
    // MARK: - Key Storage Constants
    private let attestKeyAccount = "com.paycloud.tsm.attestationKeyId"
    
    // MARK: - Public Interface
    
    /// Checks if AppAttest is available on this device.
    nonisolated var isSupported: Bool {
        return DCAppAttestService.shared.isSupported
    }
    
    /// Generates a new attestation key in the Secure Enclave.
    /// Returns the key identifier (keyId) to be used for attestation.
    func generateAttestationKey() async throws -> String {
        guard attestService.isSupported else {
            throw TSMError.unsupportedDevice
        }
        
        return try await withCheckedThrowingContinuation { continuation in
            attestService.generateKey { keyId, error in
                if let error = error {
                    continuation.resume(throwing: TSMError.keyGenerationFailed(reason: error.localizedDescription))
                    return
                }
                guard let keyId = keyId else {
                    continuation.resume(throwing: TSMError.keyGenerationFailed(reason: "No key ID returned"))
                    return
                }
                
                // Store the keyId securely for future use
                Task {
                    try? await self.keychain.save(data: keyId.data(using: .utf8)!, forAccount: self.attestKeyAccount)
                }
                
                continuation.resume(returning: keyId)
            }
        }
    }
    
    /// Retrieves the stored key ID from the Keychain, or generates a new one if none exists.
    func getOrCreateAttestationKey() async throws -> String {
        if let keyIdData = await keychain.retrieve(forAccount: attestKeyAccount),
           let keyId = String(data: keyIdData, encoding: .utf8) {
            return keyId
        }
        // No key found, generate a new one
        return try await generateAttestationKey()
    }
    
    /// Performs the attestation flow with a given challenge (nonce) from the backend.
    /// - Parameters:
    ///   - keyId: The key identifier returned from generateKey().
    ///   - challenge: A server-provided nonce (Data) to include in the attestation.
    /// - Returns: The attestation object (Data) to send to the backend for validation.
    func attestKey(keyId: String, challenge: Data) async throws -> Data {
        guard attestService.isSupported else {
            throw TSMError.unsupportedDevice
        }
      
        // DCAppAttest requires a SHA-256 hash of the client data (challenge).
        let clientDataHash = SHA256.hash(data: challenge)
        // If you need it as Data:
       // let hashData = Data(clientDataHash)
        // If you need it as a hex string (common for payment payloads):
        return try await withCheckedThrowingContinuation { continuation in
            attestService.attestKey(keyId, clientDataHash: Data(clientDataHash)) { attestation, error in
                if let error = error {
                    continuation.resume(throwing: TSMError.attestationFailed(reason: error.localizedDescription))
                    return
                }
                guard let attestation = attestation else {
                    continuation.resume(throwing: TSMError.attestationFailed(reason: "No attestation object returned"))
                    return
                }
                continuation.resume(returning: attestation)
            }
        }
    }
    
    /// Full provisioning flow: Generates key, attests with a mock challenge, and simulates backend validation.
    /// This is a convenience method for the demo. In production, the challenge comes from your backend.
    func performFullProvisioningFlow() async throws -> String {
        // 1. Ensure we have a key
        let keyId = try await getOrCreateAttestationKey()
        print("🔑 TSM Key ID: \(keyId)")
        
        // 2. Get a challenge from the backend (mock)
        let challenge = try await fetchChallengeFromBackend()
        print("📨 Received challenge from backend: \(challenge.hexString.prefix(16))...")
        
        // 3. Attest the key with the challenge
        let attestation = try await attestKey(keyId: keyId, challenge: challenge)
        print("🔒 Attestation generated: \(attestation.hexString.prefix(32))...")
        
        // 4. Send the attestation to the backend for validation
        let provisioningToken = try await sendAttestationToBackend(attestation, keyId: keyId)
        print("✅ Provisioning token received: \(provisioningToken.prefix(20))...")
        
        return provisioningToken
    }
    
    // MARK: - Mock Backend Interaction (To be replaced with real network calls)
    
    private func fetchChallengeFromBackend() async throws -> Data {
        // Simulate network delay
        try await Task.sleep(nanoseconds: 800_000_000) // 800ms
        
        // Generate a random 32-byte challenge (simulating a server nonce)
        return Data((0..<32).map { _ in UInt8.random(in: 0...255) })
    }
    
    private func sendAttestationToBackend(_ attestation: Data, keyId: String) async throws -> String {
        // Simulate network delay
        try await Task.sleep(nanoseconds: 1_200_000_000) // 1.2s
        
        // In production, backend would validate the Apple certificate chain here.
        // For demo, we just return a mock provisioning token.
        let token = "mock_provisioning_token_\(UUID().uuidString)"
        
        // Simulate success (in production, throw on validation failure)
        return token
    }
    
    // MARK: - Cleanup
    
    /// Deletes the stored attestation key (useful for testing).
    func deleteAttestationKey() async throws {
        try await keychain.delete(forAccount: attestKeyAccount)
    }
}

//Generate key → Fetch challenge → Attest → Validate → Provisioning token.

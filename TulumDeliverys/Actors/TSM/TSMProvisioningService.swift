//
//  TSMProvisioningService.swift
//
import Foundation
import DeviceCheck
import CryptoKit

actor TSMProvisioningService {
    
    static let shared = TSMProvisioningService()
    private init() {}
    
    private let attestService = DCAppAttestService.shared
    private let keychain = KeychainManager()
    
    enum TSMError: Error, Sendable {
        case unsupportedDevice
        case keyGenerationFailed(reason: String)
        case attestationFailed(reason: String)
        case keyNotFound
        case invalidChallenge
        case backendValidationFailed
    }
    
    private let attestKeyAccount = "com.paycloud.tsm.attestationKeyId"
    
    nonisolated var isSupported: Bool {
        return DCAppAttestService.shared.isSupported
    }
    
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
                
                Task {
                    try? await self.keychain.save(data: keyId.data(using: .utf8)!, forAccount: self.attestKeyAccount)
                }
                
                continuation.resume(returning: keyId)
            }
        }
    }
    
    func getOrCreateAttestationKey() async throws -> String {
        if let keyIdData = await keychain.retrieve(forAccount: attestKeyAccount),
           let keyId = String(data: keyIdData, encoding: .utf8) {
            return keyId
        }
        return try await generateAttestationKey()
    }
    
    func attestKey(keyId: String, challenge: Data) async throws -> Data {
        guard attestService.isSupported else {
            throw TSMError.unsupportedDevice
        }
        
        let clientDataHash = SHA256.hash(data: challenge)
        
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
    
    func performFullProvisioningFlow() async throws -> String {
        let keyId = try await getOrCreateAttestationKey()
        print("🔑 TSM Key ID: \(keyId)")
        
        let challenge = try await fetchChallengeFromBackend()
        print("📨 Received challenge: \(challenge.hexString.prefix(16))...")
        
        let attestation = try await attestKey(keyId: keyId, challenge: challenge)
        print("🔒 Attestation: \(attestation.hexString.prefix(32))...")
        
        let provisioningToken = try await sendAttestationToBackend(attestation, keyId: keyId)
        print("✅ Provisioning token: \(provisioningToken.prefix(20))...")
        
        return provisioningToken
    }
    
    private func fetchChallengeFromBackend() async throws -> Data {
        try await Task.sleep(nanoseconds: 800_000_000)
        return Data((0..<32).map { _ in UInt8.random(in: 0...255) })
    }
    
    private func sendAttestationToBackend(_ attestation: Data, keyId: String) async throws -> String {
        try await Task.sleep(nanoseconds: 1_200_000_000)
        return "mock_provisioning_token_\(UUID().uuidString)"
    }
    
    func deleteAttestationKey() async throws {
        try await keychain.delete(forAccount: attestKeyAccount)
    }
}

//
//  SecurityManager.swift
//  The main actor that orchestrates OAuth, tokens, and the TSM attestation signature.
//   Device Attestation (TSM): We generate a Secure Enclave private key using SecKeyCreateRandomKey with .accessControl(.biometryAny) flags, and we mock generating a DCAppAttestService assertion to attach to our headers.

// Core/Security/SecurityManager.swift
import Foundation
import Security
import CryptoKit
import LocalAuthentication

/// Responsibilities:
/// 1. OAuth2 token lifecycle (fetch, refresh, store).
/// 2. Certificate Pinning via a custom URLSession.
/// 3. Device Attestation (mocking Apple's TSM flow) using the Secure Enclave.
actor SecurityManager {
    
    // MARK: - Singleton
    static let shared = SecurityManager()
    private let keychain = KeychainManager()
    
    // The URLSession configured with our pinning delegate.
    // We use .ephemeral to avoid caching any sensitive P2PE payloads.
    private lazy var pinnedSession: URLSession = {
        let delegate = CertificatePinningDelegate()
        let configuration = URLSessionConfiguration.ephemeral
        // WARNING: We do NOT allow arbitrary loads. SSL is mandatory.
        return URLSession(configuration: configuration,
                          delegate: delegate,
                          delegateQueue: nil)
    }()
    
    // MARK: - OAuth2 State (Mocked)
    private var _accessToken: String?
    private var _refreshToken: String?
    private var _expiresAt: Date?
    
    // MARK: - Secure Enclave Attestation (TSM Simulation)
    private let attestationKeyTag = "com.paycloud.device.attestation.key"
    private var _attestationPublicKey: SecKey?
    
    // MARK: - Initialization
    private init() {
        // On cold start, attempt to load tokens from Keychain.
        Task {
            await loadTokensFromKeychain()
            await loadOrCreateAttestationKey()
        }
    }
    
    // MARK: - Public Interface
    
    /// Returns a fully configured URLRequest with:
    /// - Bearer Token (OAuth2)
    /// - Device Attestation header (simulating TSM)
    /// - Standard Content-Type
    func authenticatedRequest(for url: URL, method: String = "POST") async throws -> URLRequest {
        var request = URLRequest(url: url)
        request.httpMethod = method
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        
        // 1. Attach OAuth2 Bearer token
        let token = try await getValidAccessToken()
        request.setValue("Bearer \(token)", forHTTPHeaderField: "Authorization")
        
        // 2. Attach Device Attestation (TSM-style proof)
        let attestationProof = try await generateAttestationProof()
        request.setValue(attestationProof, forHTTPHeaderField: "X-Device-Attestation")
        
        return request
    }
    
    /// Sends a JSON payload through the pinned session.
    /// This simulates the "Secure Transport & P2PE Middleware" layer.
    func sendSecurePayload<T: Encodable>(_ payload: T, to endpoint: String) async throws -> Data {
        guard let url = URL(string: endpoint) else {
            throw URLError(.badURL)
        }
        
        var request = try await authenticatedRequest(for: url)
        let jsonData = try JSONEncoder().encode(payload)
        request.httpBody = jsonData
        
        // Use the pinned session
        let (data, response) = try await pinnedSession.data(for: request)
        
        guard let httpResponse = response as? HTTPURLResponse,
              (200...299).contains(httpResponse.statusCode) else {
            throw URLError(.badServerResponse)
        }
        
        // OWASP M2: Ensure no sensitive data is logged.
        // We log only the status code, not the raw payload.
        print("✅ Secure payload sent successfully. Status: \(httpResponse.statusCode)")
        return data
    }
    
    // MARK: - Private OAuth2 Logic
    private func loadTokensFromKeychain() async {
        // Add 'await' before retrieving from the KeychainManager actor
        if let accessData = await keychain.retrieve(forAccount: "oauth_access_token"),
           let token = String(data: accessData, encoding: .utf8) {
            _accessToken = token
        }
        if let refreshData = await keychain.retrieve(forAccount: "oauth_refresh_token"),
           let token = String(data: refreshData, encoding: .utf8) {
            _refreshToken = token
        }
        if _accessToken != nil {
            _expiresAt = Date().addingTimeInterval(3600)
        }
    }
    
    private func getValidAccessToken() async throws -> String {
        // If we have a token and it hasn't expired, return it.
        if let token = _accessToken,
           let expires = _expiresAt,
           expires > Date().addingTimeInterval(60) { // Refresh 1 minute early
            return token
        }
        
        // Otherwise, refresh or fetch a new one (Mock).
        return try await refreshOrFetchToken()
    }
    
    private func refreshOrFetchToken() async throws -> String {
        // MOCK: Simulate a network call to the OAuth2 token endpoint.
        // In reality, we'd use a client_credentials flow.
        print("🔄 Mock OAuth2: Fetching new token...")
        
        // Simulate async network delay
        try await Task.sleep(nanoseconds: 500_000_000)
        
        // Generate a mock JWT-like token.
        let mockToken = "mock_oauth2_jwt_\(UUID().uuidString)"
        let mockRefresh = "mock_refresh_\(UUID().uuidString)"
        
        // Store in Keychain
        try await keychain.save(data: mockToken.data(using: .utf8)!, forAccount: "oauth_access_token")
        try await keychain.save(data: mockRefresh.data(using: .utf8)!, forAccount: "oauth_refresh_token")
        
        _accessToken = mockToken
        _refreshToken = mockRefresh
        _expiresAt = Date().addingTimeInterval(3600)
        
        return mockToken
    }
    
    // MARK: - Private Attestation Logic (TSM Simulation)
    
    private func loadOrCreateAttestationKey() {
        // Check if we already have a key in the Keychain (as a SecKey)
        let query: [String: Any] = [
            kSecClass as String: kSecClassKey,
            kSecAttrApplicationTag as String: attestationKeyTag,
            kSecAttrKeyType as String: kSecAttrKeyTypeECSECPrimeRandom,
            kSecReturnRef as String: true
        ]
        
        var keyRef: CFTypeRef?
        let status = SecItemCopyMatching(query as CFDictionary, &keyRef)
        
        if status == errSecSuccess {
            let key = keyRef as! SecKey
            _attestationPublicKey = key
            print("🔑 Loaded existing Secure Enclave attestation key.")
            return
        }
        
        // No key found. Generate a new one inside the Secure Enclave.
        createNewAttestationKey()
    }
    
    private func createNewAttestationKey() {
        // Define key generation attributes.
        // AccessControl: Require the user to authenticate via FaceID/TouchID
        // before the private key can be used (for TSM, this is often .userPresence).
        var error: Unmanaged<CFError>?
        guard let accessControl = SecAccessControlCreateWithFlags(
            nil,
            kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly,
            [.privateKeyUsage, .userPresence],
            &error
        ) else {
            print("❌ Failed to create AccessControl for attestation key.")
            return
        }
        
        let attributes: [String: Any] = [
            kSecAttrKeyType as String: kSecAttrKeyTypeECSECPrimeRandom,
            kSecAttrKeySizeInBits as String: 256,
            kSecAttrTokenID as String: kSecAttrTokenIDSecureEnclave, // Force Secure Enclave
            kSecPrivateKeyAttrs as String: [
                kSecAttrIsPermanent as String: true,
                kSecAttrApplicationTag as String: attestationKeyTag,
                kSecAttrAccessControl as String: accessControl
            ]
        ]
        
        guard let privateKey = SecKeyCreateRandomKey(attributes as CFDictionary, &error) else {
            print("❌ Failed to create Secure Enclave key: \(error?.takeRetainedValue().localizedDescription ?? "unknown")")
            return
        }
        
        // Extract the public key for our mock attestation.
        let publicKey = SecKeyCopyPublicKey(privateKey)
        _attestationPublicKey = publicKey
        print("🔐 Generated new Secure Enclave attestation key. Public Key: \(String(describing: publicKey))")
    }
    
    /// Generates a mock "Attestation Proof" to simulate Apple's TSM `DCAppAttestService`.
    /// In real TSM, this would be a challenge-response against Apple's servers.
    /// Here, we simply sign a random challenge with our Secure Enclave key.
    private func generateAttestationProof() async throws -> String {
        guard let privateKey = getPrivateKeyForAttestation() else {
            throw NSError(domain: "SecurityManager", code: -1, userInfo: [NSLocalizedDescriptionKey: "Attestation key missing"])
        }
        
        // Create a random challenge (simulating the backend's nonce).
        let challenge = UUID().uuidString.data(using: .utf8)!
        
        // Sign the challenge using ES256 (P-256 + SHA-256).
        // In a real TSM, Apple returns a specific JWT format. Here we just return a base64 signature.
        let signature = try signData(challenge, with: privateKey)
        let proof = signature.base64EncodedString()
        
        return "mock_attestation_\(proof)"
    }
    
    private func getPrivateKeyForAttestation() -> SecKey? {
        // Retrieve the private key from Keychain using the tag.
        let query: [String: Any] = [
            kSecClass as String: kSecClassKey,
            kSecAttrApplicationTag as String: attestationKeyTag,
            kSecAttrKeyType as String: kSecAttrKeyTypeECSECPrimeRandom,
            kSecReturnRef as String: true
        ]
        
        var keyRef: CFTypeRef?
        let status = SecItemCopyMatching(query as CFDictionary, &keyRef)
        
        guard status == errSecSuccess else {
            print("❌ Could not retrieve private key for attestation.")
            return nil
        }
        return (keyRef as! SecKey)
    }
    
    private func signData(_ data: Data, with privateKey: SecKey) throws -> Data {
        // SecKeyCreateSignature requires a digest.
        let hash = SHA256.hash(data: data)
        let hashData = Data(hash)
        
        var error: Unmanaged<CFError>?
        guard let signature = SecKeyCreateSignature(privateKey,
                                                    .ecdsaSignatureMessageX962SHA256,
                                                    hashData as CFData,
                                                    &error) else {
            throw error!.takeRetainedValue() as Error
        }
        return signature as Data
    }
}

//OAuth2 – Simulates fetching tokens.
//Keychain – Stores them securely.
//Device Attestation (TSM) – Generates a Secure Enclave key and signs a mock attestation JWT-like object to attach to headers.

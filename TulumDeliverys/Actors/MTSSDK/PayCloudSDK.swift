//
//  PayCloudSDK.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 08/07/26.
//
// PayCloudSDK.swift
import Foundation
import PayCloudTSMSDK
/// Singleton client for the PayCloud TSM SDK.
/// Use this as the single entry point for all TSM operations.
final class PayCloudSDK {
    
    // MARK: - Singleton
    static let shared = PayCloudSDK()
    private init() {}
    
    // MARK: - Internal Client
    private var client: TSMClient?
    private let secureChannel = SecureChannel()
    
    // MARK: - Configuration
    /// Call this once during app launch to configure the SDK.
    /// /// Call this once during app launch to configure the SDK.
    func configure(
        baseUrl: String,
        partnerId: String,
        appletPackageId: String
    ) {
        // 1. Create the KMP configuration object
        let config = NetworkConfig(baseUrl: baseUrl, timeoutMillis: 30_000)
        
        // 2. Instantiate the native Swift auth provider
        let nativeAuthProvider = SwiftAuthTokenProvider()
        
        // 3. Create the iOS-specific network client
        // The Ktor engine is now safely built inside Kotlin!
        let networkClient = IOSNetworkClient(
            config: config,
            authTokenProvider: nativeAuthProvider
        )
        
        // 4. Initialize the core TSM client
        self.client = TSMClient(
            baseUrl: baseUrl,
            partnerId: partnerId,
            appletPackageId: appletPackageId,
            secureChannel: secureChannel,
            networkClient: networkClient
        )
    }
    
    // MARK: - Public API Methods
    
    /// Adds a new card.
    /// - Parameters:
    ///   - encryptedCardData: Base64‑encoded encrypted data from the Secure Element
    ///   - cardholderName: Name on the card
    ///   - billingAddress: Billing address associated with the card
    ///   - pan, expiryMonth, expiryYear, cvv: (optional) for direct input (if not encrypted)
    ///   - deviceId, walletId: (optional) identifiers
    ///   - pushToken: (optional) if provided, returns immediately with a RequestId (async flow)
    @discardableResult
    func addCard(
        encryptedCardData: String,
        cardholderName: String,
        billingAddress: BillingAddress,
        pan: String? = nil,
        expiryMonth: String? = nil,
        expiryYear: String? = nil,
        cvv: String? = nil,
        deviceId: String? = nil,
        walletId: String? = nil,
        pushToken: String? = nil
    ) async throws -> AddCardResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        return try await client.addCard(
            encryptedCardData: encryptedCardData,
            cardholderName: cardholderName,
            billingAddress: billingAddress,
            pan: pan,
            expiryMonth: expiryMonth,
            expiryYear: expiryYear,
            cvv: cvv,
            deviceId: deviceId,
            walletId: walletId,
            pushToken: pushToken
        )
    }
    
    /// Confirms provisioning status for a token (used after receiving a push notification).
    func confirmProvisioning(
        tokenId: String,
        success: Bool,
        errorMessage: String? = nil
    ) async throws -> ConfirmProvisioningResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        return try await client.confirmProvisioning(
            tokenId: tokenId,
            success: success,
            errorMessage: errorMessage
        )
    }
    
    // MARK: - Lifecycle Management
    
    func suspendCard(
        cardId: String,
        reason: String,
        reasonCode: String
    ) async throws -> TokenLifecycleResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        return try await client.suspendCard(
            cardId: cardId,
            reason: reason,
            reasonCode: reasonCode
        )
    }
    
    func resumeCard(
        cardId: String,
        reason: String,
        reasonCode: String
    ) async throws -> TokenLifecycleResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        return try await client.resumeCard(
            cardId: cardId,
            reason: reason,
            reasonCode: reasonCode
        )
    }
    
    func deleteCard(
        cardId: String,
        reason: String,
        reasonCode: String
    ) async throws -> TokenLifecycleResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        return try await client.deleteCard(
            cardId: cardId,
            reason: reason,
            reasonCode: reasonCode
        )
    }
    
    // MARK: - Device Registration
    
    func registerDevice(
        deviceType: String,
        deviceName: String,
        os: String,
        osVersion: String,
        secureElementInfo: SecureElementInfo
    ) async throws {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        try await client.registerDevice(
            deviceType: deviceType,
            deviceName: deviceName,
            os: os,
            osVersion: osVersion,
            secureElementInfo: secureElementInfo
        )
    }
    
    // MARK: - ID&V (Identity & Verification)
    /*
    func initiateIdv(
        tokenId: String,
        preferredMethod: String? = nil,
        deviceId: String? = nil,
        customerId: Int64? = nil
    ) async throws -> InitiateIdvResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        let request = InitiateIdvRequest(
            tokenId: tokenId,
            preferredMethod: preferredMethod,
            deviceId: deviceId,
            customerId: customerId
        )
        return try await client.initiateIdv(request: request)
    }
    
    func verifyIdv(
        verificationId: String,
        otpCode: String? = nil,
        biometricToken: String? = nil,
        appConfirmationToken: String? = nil
    ) async throws -> VerifyIdvResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        let request = VerifyIdvRequest(
            verificationId: verificationId,
            otpCode: otpCode,
            biometricToken: biometricToken,
            appConfirmationToken: appConfirmationToken
        )
        return try await client.verifyIdv(request: request)
    }
    
    func resendOtp(
        verificationId: String,
        newMethod: String? = nil
    ) async throws -> ResendOtpResponse {
        guard let client = client else {
            throw SDKError.notConfigured
        }
        let request = ResendOtpRequest(
            verificationId: verificationId,
            newMethod: newMethod
        )
        return try await client.resendOtp(request: request)
    }
    
    // MARK: - Credentials Stream
    
    /// Returns an async sequence that emits the current list of credentials whenever it changes.
    var currentCredentials: AsyncStream<[CredentialInfo]> {
        guard let client = client else {
            return AsyncStream { continuation in
                continuation.finish()
            }
        }
        return client.currentCredentials
    }*/
    
    // MARK: - Error Types
    enum SDKError: Error {
        case notConfigured
    }
}

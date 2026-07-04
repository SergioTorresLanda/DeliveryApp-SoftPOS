//
//  KeychainManager.swift
//  Secure token storage: Stores OAuth2 refresh tokens with .accessibleAfterFirstUnlockThisDeviceOnly (PCI compliant).
//
// Core/Security/KeychainManager.swift
import Foundation
import Security

/// A generic actor responsible for storing and retrieving sensitive data
/// strictly in the iOS Keychain. We use `.accessibleAfterFirstUnlockThisDeviceOnly`
/// to ensure data isn't available during a device's first boot before the user unlocks,
/// complying with OWASP M5 (Insufficient Biometric/Keychain Protection).
actor KeychainManager {
    
    private let service = "com.paycloud.securetransport"
    
    enum KeychainError: Error {
        case duplicateEntry
        case itemNotFound
        case unexpectedStatus(OSStatus)
    }
    
    /// Saves a `Data` object to the keychain with the given account identifier.
    /// - Parameters:
    ///   - data: The raw data to save (token, key, etc.)
    ///   - account: A unique string identifier (e.g., "oauth_access_token")
    func save(data: Data, forAccount account: String) throws {
        let query: [String: Any] = [
            kSecClass as String: kSecClassGenericPassword,
            kSecAttrService as String: service,
            kSecAttrAccount as String: account,
            kSecValueData as String: data,
            // Critical: Data is only available after first unlock.
            // This protects the token during a cold boot attack.
            kSecAttrAccessible as String: kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
        ]
        
        // Attempt to delete any existing item to avoid duplicates
        SecItemDelete(query as CFDictionary)
        
        let status = SecItemAdd(query as CFDictionary, nil)
        guard status == errSecSuccess else {
            throw KeychainError.unexpectedStatus(status)
        }
    }
    
    /// Retrieves the data for a given account identifier.
    func retrieve(forAccount account: String) -> Data? {
        let query: [String: Any] = [
            kSecClass as String: kSecClassGenericPassword,
            kSecAttrService as String: service,
            kSecAttrAccount as String: account,
            kSecReturnData as String: true,
            kSecMatchLimit as String: kSecMatchLimitOne
        ]
        
        var result: CFTypeRef?
        let status = SecItemCopyMatching(query as CFDictionary, &result)
        
        guard status == errSecSuccess else {
            return nil
        }
        return result as? Data
    }
    
    /// Deletes the item from the keychain.
    func delete(forAccount account: String) throws {
        let query: [String: Any] = [
            kSecClass as String: kSecClassGenericPassword,
            kSecAttrService as String: service,
            kSecAttrAccount as String: account
        ]
        let status = SecItemDelete(query as CFDictionary)
        guard status == errSecSuccess || status == errSecItemNotFound else {
            throw KeychainError.unexpectedStatus(status)
        }
    }
}

//This handles the low-level SecItem APIs. It stores our OAuth2 tokens with strict access controls to satisfy PCI compliance.

//
//  CertificatePinningDelegate.swift
//  SSL Pinning : An URLSessionDelegate that validates the server's SSL public key hash (mTLS simulation).
//

// Core/Security/CertificatePinningDelegate.swift
import Foundation
import Security
// MARK: - CommonCrypto Bridging
// We need this import to call CC_SHA256 in the pinner.
import CommonCrypto
/// A custom URLSessionDelegate that implements public-key pinning.
/// We mock a valid public key hash here. In production, this would be a known
/// fingerprint from the backend team.
final class CertificatePinningDelegate: NSObject, URLSessionDelegate {
    
    // In a real project, you would retrieve this from a secure server API.
    // For the mock, we use a placeholder SHA-256 hash.
    private let pinnedPublicKeyHashes = [
        "MOCK_SERVER_PUBLIC_KEY_SHA256_HASH_32_BYTES_BASE64"
    ]
    
    func urlSession(_ session: URLSession,
                    didReceive challenge: URLAuthenticationChallenge,
                    completionHandler: @escaping (URLSession.AuthChallengeDisposition, URLCredential?) -> Void) {
        
        // 1. Check if the server is asking for server trust evaluation
        guard challenge.protectionSpace.authenticationMethod == NSURLAuthenticationMethodServerTrust,
              let serverTrust = challenge.protectionSpace.serverTrust else {
            // Fallback to default behavior for other auth types
            completionHandler(.performDefaultHandling, nil)
            return
        }
        
        // 2. Evaluate the server's certificate chain
        var error: CFError?
        guard SecTrustEvaluateWithError(serverTrust, &error) else {
            // Certificate is invalid (expired, revoked, etc.)
            completionHandler(.cancelAuthenticationChallenge, nil)
            return
        }
        
        // 3. Extract the public key from the leaf certificate
        guard let certificate = SecTrustGetCertificateAtIndex(serverTrust, 0) else {
            completionHandler(.cancelAuthenticationChallenge, nil)
            return
        }
        
        var publicKey: SecKey?
        if #available(iOS 14.0, *) {
            publicKey = SecCertificateCopyKey(certificate)
        } else {
            // Fallback for older iOS (though we target 16+)
            publicKey = SecCertificateCopyPublicKey(certificate)
        }
        
        guard let key = publicKey else {
            completionHandler(.cancelAuthenticationChallenge, nil)
            return
        }
        
        // 4. Compute SHA-256 hash of the public key's data representation
        var errorUnmanaged: Unmanaged<CFError>?
        guard let keyData = SecKeyCopyExternalRepresentation(key, &errorUnmanaged) as Data? else {
            completionHandler(.cancelAuthenticationChallenge, nil)
            return
        }
        
        let keyHash = sha256(data: keyData).base64EncodedString()
        
        // 5. Compare against our pinned hashes
        if pinnedPublicKeyHashes.contains(keyHash) {
            // Trust the server
            let credential = URLCredential(trust: serverTrust)
            completionHandler(.useCredential, credential)
        } else {
            // Pinning failure – block the connection
            completionHandler(.cancelAuthenticationChallenge, nil)
        }
    }
    
    private func sha256(data: Data) -> Data {
        var hash = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
        data.withUnsafeBytes { bytes in
            _ = CC_SHA256(bytes.baseAddress, CC_LONG(data.count), &hash)
        }
        return Data(hash)
    }
}

//This is our URLSessionDelegate.
//Instead of just checking the entire certificate, we hardcode the SHA-256 hash of the public key.
//This is best practice because it survives certificate renewals as long as the private key stays the same.

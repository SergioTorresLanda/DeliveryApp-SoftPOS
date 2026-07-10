//
//  SwiftAuthTokenProvider.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 09/07/26.
//
import PayCloudTSMSDK // Replace with your actual KMP framework name

// Conforms to the Kotlin interface 'AuthTokenProvider'
class SwiftAuthTokenProvider: NSObject, AuthTokenProvider {
    
    // Standard Kotlin/Native interop converts suspend functions to completion handlers.
    // (If you are using SKIE, this signature would just be 'func getValidToken() async throws -> String')
    func getValidToken(completionHandler: @escaping (String?, Error?) -> Void) {

        let safeCompletion = SendableCompletionBox(completionHandler)

        Task {
            do {
                let token = try await SecurityManager.shared.getValidAccessToken()
                safeCompletion(token, nil)
                
            } catch {
                print("❌ AuthTokenProvider Error: \(error.localizedDescription)")
                safeCompletion(nil, error)
            }
        }
    }
}

//Create a Sendable wrapper to satisfy the Swift 6 Compiler
// We use @unchecked Sendable because we (the engineers) know KMP handles the thread transition safely.
private final class SendableCompletionBox: @unchecked Sendable {
    private let completion: (String?, Error?) -> Void
    
    init(_ completion: @escaping (String?, Error?) -> Void) {
        self.completion = completion
    }
    
    // Using callAsFunction allows us to execute the box as if it were the closure itself
    func callAsFunction(_ token: String?, _ error: Error?) {
        completion(token, error)
    }
}


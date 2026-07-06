//
//  TransactionState.swift

import Foundation

/// Finite State Machine for the SoftPOS payment flow.
/// This drives the entire UX and enforces business rules.
enum TransactionState: Equatable, Sendable {
    case idle                                    // Ready to start
    case waitingForTap                           // NFC session active, waiting for card
    case readingCard                             // EMV APDU sequence in progress
    case processingCryptogram                    // Unpredictable number generated, cryptogram built
    case authorizingCloud                        // Sending P2PE payload to cloud
    case approved(reference: String)             // Transaction successful
    case declined(reason: String)                // Transaction declined
    case error(message: String)                  // Recoverable error (e.g., tap timeout)
    case cancelled                               // User cancelled
    
    // Helper for UI state
    var isTerminal: Bool {
        switch self {
        case .approved, .declined, .error, .cancelled:
            return true
        default:
            return false
        }
    }
    
    var isProcessing: Bool {
        switch self {
        case .waitingForTap, .readingCard, .processingCryptogram, .authorizingCloud:
            return true
        default:
            return false
        }
    }
    
    var displayMessage: String {
        switch self {
        case .idle:
            return "Ready to Tap"
        case .waitingForTap:
            return "📡 Hold your card near the top of the phone..."
        case .readingCard:
            return "🔄 Reading card..."
        case .processingCryptogram:
            return "🔐 Generating cryptogram..."
        case .authorizingCloud:
            return "☁️ Authorizing with cloud..."
        case .approved(let ref):
            return "✅ Approved!\nReference: \(ref)"
        case .declined(let reason):
            return "❌ Declined: \(reason)"
        case .error(let msg):
            return "⚠️ Error: \(msg)"
        case .cancelled:
            return "❌ Cancelled"
        }
    }
}

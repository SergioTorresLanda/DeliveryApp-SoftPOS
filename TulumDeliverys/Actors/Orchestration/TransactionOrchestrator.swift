//
//  TransactionOrchestrator.swift

import Foundation

/// The central coordinator for the SoftPOS payment flow.
/// Owns the state machine and orchestrates the NFC and Security layers.
actor TransactionOrchestrator {
    
    // MARK: - Dependencies
    private let nfcManager: NFCSessionProtocol
    private let securityManager: SecurityManager
    
    // MARK: - State Management
    private(set) var currentState: TransactionState = .idle
    private var stateContinuation: AsyncStream<TransactionState>.Continuation?
    
    // MARK: - Timeout Handling
    private var timeoutTask: Task<Void, Never>?
    private let isoTimeout: TimeInterval = 0.5 // 500ms
    
    // MARK: - Init
    init(nfcManager: NFCSessionProtocol = MockNFCSessionManager(behavior: .success, delay: 1_500_000_000),
         securityManager: SecurityManager = .shared) {
        self.nfcManager = nfcManager
        self.securityManager = securityManager
    }
    
    // MARK: - State Stream
    
    /// Provides an AsyncStream of state updates for the UI to observe.
    nonisolated func stateStream() -> AsyncStream<TransactionState> {
        AsyncStream { continuation in
            Task { await self.setContinuation(continuation) }
        }
    }
    
    private func setContinuation(_ continuation: AsyncStream<TransactionState>.Continuation) {
        self.stateContinuation = continuation
        // Immediately emit current state
        continuation.yield(currentState)
    }
    
    // MARK: - Transition Helper
    
    private func transition(to newState: TransactionState) {
        currentState = newState
        stateContinuation?.yield(newState)
        print("🔄 State Transition: \(newState)")
    }
    
    // MARK: - Public Action
    
    /// Starts the payment flow.
    /// - Parameter amount: The transaction amount (for now, we mock it).
    func startTransaction(amount: String = "33.99") async {
        // Guard against multiple concurrent transactions
        guard currentState == .idle || currentState.isTerminal else {
            print("⚠️ Transaction already in progress. Ignoring start.")
            return
        }
        
        transition(to: .waitingForTap)
        
        // 1. Start the 500ms ISO timeout timer
        timeoutTask = Task {
            try? await Task.sleep(nanoseconds: UInt64(isoTimeout * 1_000_000_000))
            // If we're still waiting for tap after 500ms, trigger a timeout
            if self.currentState == .waitingForTap {
                await self.transition(to: .error(message: "Card tap timed out. Please try again."))
                await self.resetTimeout()
            }
        }
        
        do {
            // 2. Read the card via CoreNFC
            transition(to: .readingCard)
            let cardData = try await nfcManager.readPaymentCard()
            
            // 3. Cancel the timeout since we successfully read the card
            resetTimeout()
            
            // 4. Build the cryptogram (mock) – transition to processing
            transition(to: .processingCryptogram)
            let unpredictableNumber = cardData.unpredictableNumber
            // In a real kernel, we would compute the cryptogram using the CDOL1.
            // We already have a mock cryptogram from Phase 2.
            
            // 5. Build the transaction payload
            let transaction = TransactionPayload(
                transactionId: UUID().uuidString,
                amount: amount,
                currency: "USD",
                pan: cardData.pan,
                expiry: cardData.expiry,
                cryptogram: cardData.cryptogram.hexString,
                unpredictableNumber: unpredictableNumber.hexString,
                aid: cardData.aid,
                issuerAppData: cardData.issuerAppData.hexString
            )
            
            // 6. Send through the secure transport layer
            transition(to: .authorizingCloud)
            /*
            let endpoint = "https://mock.paycloud.com/v1/softpos/process"
            let responseData = try await securityManager.sendSecurePayload(transaction, to: endpoint)
            
            // 7. Parse the response
            if let json = try? JSONSerialization.jsonObject(with: responseData) as? [String: Any],
               let status = json["status"] as? String {
                if status == "APPROVED" {
                    let reference = json["reference"] as? String ?? "N/A"
                    transition(to: .approved(reference: reference))
                } else {
                    let reason = json["reason"] as? String ?? "Unknown"
                    transition(to: .declined(reason: reason))
                }
            } else {
                transition(to: .error(message: "Invalid response from server."))
            }*/
            
            transition(to: .approved(reference: "REF333999"))
            
        } catch NFCSessionManager.NFCError.userCancelled {
            // User cancelled the NFC session
            resetTimeout()
            transition(to: .cancelled)
            
        } catch NFCSessionManager.NFCError.apduFailed(let sw1, let sw2) {
            resetTimeout()
            transition(to: .error(message: "APDU Error: \(String(format: "%02X%02X", sw1, sw2))"))
            
        } catch NFCSessionManager.NFCError.missingData(let missing) {
            resetTimeout()
            transition(to: .error(message: "Missing EMV data: \(missing)"))
            
        } catch {
            // Catch all other errors (network, etc.)
            resetTimeout()
            transition(to: .error(message: error.localizedDescription))
        }
    }
    
    // MARK: - Reset
    
    /// Resets the orchestrator to idle state. Useful after a terminal state.
    func reset() {
        resetTimeout()
        transition(to: .idle)
    }
    
    private func resetTimeout() {
        timeoutTask?.cancel()
        timeoutTask = nil
    }
}

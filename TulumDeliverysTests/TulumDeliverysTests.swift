//
//  TulumDeliverysTests.swift
//  TulumDeliverysTests
//
//  Created by Sergio Torres Landa González on 10/06/25.
//
import XCTest
import Testing
@testable import TulumDeliverys

struct TulumDeliverysTests {

    @Test func example() async throws {
        // Write your test here and use APIs like `#expect(...)` to check expected conditions.
    }
    
    // TransactionTests.swift
    func testAddTransactionSavesToDB() async throws {
        // A. Setup
        let mockDB = MockDataManager()
        let repo = Repository(remoteDataSource: RemoteDataSource(), localDataSource: mockDB) // Inject the Mock!
        
        // B. Act
        try await repo.addTransaction(items: [])
        
        // C. Assert
        let saved = await mockDB.didCallSave
        XCTAssertTrue(saved, "Repository should have called save on the DataManager")
        
        //let items: [Item] = try await mockDB.fetch(descriptor: FetchDescriptor())
        //XCTAssertEqual(items.count, 0)
    }
    
    func testNFCPaymentSessionUpdatesToApproved() async {
        // Inject the mock
        let mockNFC = MockSecureElementService()
        let viewModel = await NFCPaymentSessionManager(secureElement: mockNFC)
        
        // Start the session (it will suspend and wait for a stream event)
        await viewModel.startTapToPhoneSession()
        
        // Simulate the physical hardware tap
        await mockNFC.simulateHardwareTap(payload: "1122334455667788")
        
        // Let the async task process, then assert
        try? await Task.sleep(nanoseconds: 100_000_000) // Brief yield for UI update
        let finalState = await viewModel.sessionState
        
        XCTAssertEqual(finalState, "Approved")
    }

}


// 1. @Suite groups related tests.
// NOTE: Swift Testing runs these @Test functions in PARALLEL by default.
// You no longer need to configure scheme settings for parallel execution.
@Suite("NFC Payment Session Tests")
struct NFCPaymentSessionTests {
    
    @Test("Session initializes and processes successful payment")
    func successfulPaymentFlow() async throws {
        // Setup
        let mockNFC = MockSecureElementService()
        let viewModel = await NFCPaymentSessionManager(secureElement: mockNFC)
        
        await viewModel.startTapToPhoneSession()
        
        // 2. #require (HARD Assertion)
        // If the ViewModel didn't transition to the "Looking" state, the rest of the
        // test is useless. #require immediately throws and halts execution of this test.
        // Bonus: try #require() can also safely unwrap optionals without guard-let!
        let initialState = await viewModel.sessionState
        try #require(initialState == "Looking for Card...", "Setup failed: Hardware not listening.")
        
        // Simulate hardware interaction
        await mockNFC.simulateHardwareTap(payload: "valid_emv_payload")
        
        // Yield thread to allow the MainActor to process the stream
        try await Task.sleep(nanoseconds: 100_000_000)
        
        let finalState = await viewModel.sessionState
        
        // 3. #expect (SOFT Assertion)
        // If this fails, Xcode records the failure but CONTINUES running the test.
        // We use two tools (#expect / #require) instead of XCTest's 40+ XCTAssert variants.
        #expect(finalState == "Approved", "State should be Approved after valid tap.")
        
        // (If #expect failed above, this line would still execute)
        let isTaskRunning = await viewModel.sessionState != "Idle"
        #expect(isTaskRunning)
    }
}

/*
 =========================================
 INTERVIEW NOTES ON ARCHITECTURE LIMITS:
 =========================================
 While we migrated our Business Logic and ViewModel tests to `import Testing`,
 our UI Test target still heavily relies on `import XCTest`.
 
 Swift Testing currently has no replacement for `XCUIApplication()` or `XCUIElement`.
 Therefore, UI black-box testing and UI automation pipelines must remain in XCTest
 for the foreseeable future.
*/

//
//  NFCDelegateBridge.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 05/07/26.
//

// Core/NFC/NFCDelegateBridge.swift
import Foundation
import CoreNFC

/// A pure NSObject bridge that conforms to NFCTagReaderSessionDelegate.
/// This is necessary because CoreNFC expects an Objective-C compatible delegate.
/// All hardware events are forwarded to the actor via Sendable closures.
final class NFCDelegateBridge: NSObject, NFCTagReaderSessionDelegate, @unchecked Sendable {
    
    // MARK: - Sendable Callbacks (Safe for actor communication)
    var onDidBecomeActive: (@Sendable (NFCTagReaderSession) -> Void)?
    var onDidDetectTags: (@Sendable (NFCTagReaderSession, [NFCTag]) -> Void)?
    var onDidInvalidate: (@Sendable (NFCTagReaderSession, Error) -> Void)?
    
    // MARK: - NFCTagReaderSessionDelegate
    
    func tagReaderSessionDidBecomeActive(_ session: NFCTagReaderSession) {
        onDidBecomeActive?(session)
    }
    
    func tagReaderSession(_ session: NFCTagReaderSession, didDetect tags: [NFCTag]) {
        onDidDetectTags?(session, tags)
    }
    
    func tagReaderSession(_ session: NFCTagReaderSession, didInvalidateWithError error: Error) {
        onDidInvalidate?(session, error)
    }
}

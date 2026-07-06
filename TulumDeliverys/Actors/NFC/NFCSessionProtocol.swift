//
//  NFCSessionProtocol.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 05/07/26.
//

// Core/NFC/NFCSessionProtocol.swift
import Foundation

/// A protocol abstracting the NFC hardware layer.
/// This allows us to swap the real CoreNFC implementation with a mock
/// for UI development, testing, and CI.
protocol NFCSessionProtocol: Sendable {
    func readPaymentCard() async throws -> NFCSessionManager.EMVCardData
}

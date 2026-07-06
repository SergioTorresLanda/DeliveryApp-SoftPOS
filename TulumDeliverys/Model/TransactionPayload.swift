//
//  TransactionPayload.swift
//
import Foundation

struct TransactionPayload: Codable {
    let transactionId: String
    let amount: String
    let currency: String
    let pan: String
    let expiry: String
    let cryptogram: String
    let unpredictableNumber: String
    let aid: String
    let issuerAppData: String

    enum CodingKeys: String, CodingKey {
        case transactionId = "transaction_id"
        case amount
        case currency
        case pan
        case expiry
        case cryptogram
        case unpredictableNumber = "unpredictable_number"
        case aid
        case issuerAppData = "issuer_app_data"
    }
}

struct EMVCardData: Sendable {
    let pan: String              // Masked for logging, full for transport
    let expiry: String           // YYMM
    let applicationLabel: String // e.g., "VISA CREDIT"
    let aid: String              // Application ID (hex)
    let afl: [UInt8]             // Application File Locator (for internal use)
    let cdol1: Data              // Card Risk Management Data Object List
    let cryptogram: Data         // 9F26 - Application Cryptogram (mock or real)
    let unpredictableNumber: Data // 9F37 - The UDN we provided
    let issuerAppData: Data      // 9F10 - Issuer Application Data (optional)
}

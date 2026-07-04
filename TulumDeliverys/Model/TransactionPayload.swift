//
//  TransactionPayload.swift
//

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

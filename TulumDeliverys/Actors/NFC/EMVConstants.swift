//
//  EMVConstants.swift
//  TulumDeliverys
//
//
// Core/NFC/EMVConstants.swift
import Foundation

// EMV Tag definitions (ISO 7816-4 & EMV Book 3)
enum EMVTag: String {
    case pan = "5A"           // Primary Account Number
    case expiry = "5F24"      // Expiration Date (YYMM)
    case applicationLabel = "50" // Application Label
    case afl = "94"           // Application File Locator
    case cryptogram = "9F26"  // Application Cryptogram (TC/ARQC)
    case unpredictableNumber = "9F37" // Unpredictable Number
    case cid = "9F27"         // Cryptogram Information Data
    case cdol1 = "8C"         // Card Risk Management Data Object List 1
    case pdol = "9F38"        // Processing Options Data Object List
    case issuerAppData = "9F10" // Issuer Application Data
    case terminalCountryCode = "9F1A"
    case transactionCurrencyCode = "5F2A"
    case transactionAmount = "9F02"
    case terminalType = "9F35"
}

// Helper to parse TLV Data
struct TLV {
    let tag: String
    let length: Int
    let value: Data
    
    static func parse(_ data: Data) -> [TLV] {
        var result: [TLV] = []
        var index = 0
        while index < data.count {
            // 1. Read Tag (1 or 2 bytes)
            let tagByte = data[index]
            var tag = String(format: "%02X", tagByte)
            index += 1
            // Check for extended tag (tag > 0x1F)
            if tagByte & 0x1F == 0x1F {
                // Two-byte tag (e.g., 9F...)
                let tagByte2 = data[index]
                tag += String(format: "%02X", tagByte2)
                index += 1
            }
            
            // 2. Read Length (1 or more bytes)
            var lengthByte = data[index]
            var length = 0
            index += 1
            if lengthByte & 0x80 == 0x80 {
                // Extended length (subsequent bytes tell the length)
                let lengthOfLength = Int(lengthByte & 0x7F)
                for _ in 0..<lengthOfLength {
                    length = (length << 8) + Int(data[index])
                    index += 1
                }
            } else {
                length = Int(lengthByte)
            }
            
            // 3. Read Value
            let value = data.subdata(in: index..<index + length)
            index += length
            
            result.append(TLV(tag: tag, length: length, value: value))
        }
        return result
    }
    
    // Convenience: get first TLV by tag string
    static func firstValue(for tag: String, in data: Data) -> Data? {
        return parse(data).first(where: { $0.tag == tag })?.value
    }
}

//a small helper file for the TLVs and APDU constants we will use.

//
//  DataExt.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 05/07/26.
//
import Foundation
// MARK: - Data Extensions

extension Data {
    var hexString: String {
        return map { String(format: "%02X", $0) }.joined()
    }
}

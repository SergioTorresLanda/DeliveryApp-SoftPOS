//
//  Lattice.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 14/03/26.
//

import Foundation
import simd

/// The fundamental contract governing the 9D quantum field.
protocol Lattice {
    /// The maximum node-to-node refresh rate limit (Speed of Light)
    static var c: Double { get }
    /// Processes an outgoing state-transition to the network
    mutating func sendInformation(payload: Pixel, targetCoordinates: SIMD3<Double>)
    /// Resolves an incoming wave-function collapse / measurement
    mutating func receiveInformation(from source: Pixel)
}

/// The localized, manifested 8-dimensional state vector.
struct Pixel: Lattice {
    // d4: Mass (The Primary Trap)
    // 0.0 means unhindered execution (Photon). > 0 forces local time dilation.
    
    var mass: Double {
        return 0
       // return calculateComputationalWeight(of: charge, spin, color, weakIsospin)
    }
    // MARK: - Axiom II: The Contract
    static let c: Double = 299792458.0
    // MARK: - Axiom III & IV: The 8 Property Dimensions
    // d1, d2, d3: Spatial Coordinates
    // Emerges only upon manifestation. Nil means it exists as pure potential in 9D.
    var position: SIMD3<Double>?
    // d5: Electric Charge
    var charge: Double
    
    // d6: Spin / Chirality
    // The geometry of the handshake. 1.0 (Boson) or 0.5 (Fermion).
    var spin: Double
    
    // d7: Color Charge (Strong Nuclear Topology)
    enum ColorCharge {
        case red, green, blue, unmanifested
    }
    var color: ColorCharge
    
    // d8: Weak Isospin (Weak Nuclear Topology)
    var weakIsospin: Double
    
    // MARK: - Lattice Protocol Methods
    
    mutating func sendInformation(payload: Pixel, targetCoordinates: SIMD3<Double>) {
        // TODO: Phase 4 - Implement electromagnetism/information exchange equations
        // This will define how a trapped pixel emits a photon [0,0,0,0,0,1,0,0]
    }
    
    mutating func receiveInformation(from source: Pixel) {
        // TODO: Phase 3 - Implement wave-function collapse and state resolution
        // If source hits a boundary, self.position is allocated, and properties update.
    }
    
    // MARK: - Core Physics Engine
    /// The current spatial velocity vector of the pixel through the Lattice (v_x, v_y, v_z)
    /// This represents the rate of state-transitions across the d1, d2, d3 dimensions.
    var velocity: SIMD3<Double>
    
    /// Evaluates the local 'tick' rate of the pixel's internal clock compared to the Lattice maximum (c).
    /// Returns a multiplier between 0.0 (time stopped) and 1.0 (time ticking at maximum rest rate).
    func calculateLocalTimeRate() -> Double {
        
        // 1. Calculate the squared magnitude of external velocity (v^2)
        // Using the 3D Pythagorean theorem: v^2 = vx^2 + vy^2 + vz^2
        let vSquared = (velocity.x * velocity.x) +
                       (velocity.y * velocity.y) +
                       (velocity.z * velocity.z)
        
        let cSquared = Pixel.c * Pixel.c
        
        // 2. The Universal Smart Contract Check
        // Axiom II explicitly forbids any pixel from exceeding the bandwidth limit c.
        guard vSquared <= cSquared else {
            fatalError("Axiom II Violation: Pixel transition bandwidth exceeded c.")
        }
        
        // 3. The Pure Light Check (Photon)
        // If the pixel has no mass (d4 is nil/0), it is not trapped.
        if self.mass == 0.0 {
            // It spends 100% of its bandwidth on external movement.
            // Internal tick rate is exactly 0. It experiences no time.
            return 0.0
        }
        
        // 4. The Trapped Light Calculation (Massive Particle)
        // We calculate the remaining bandwidth available for internal processing.
        // Formula: internalRate = sqrt(1 - v^2/c^2)
        let bandwidthRatio = vSquared / cSquared
        let internalTickRate = sqrt(1.0 - bandwidthRatio)
        
        return internalTickRate
    }
    /// Evaluates the local 'tick' rate based on the internal mass trap
    func calculateLocalTimeDilation() -> Double {
        // TODO: Phase 2 - Derive Time Dilation strictly from 'mass' and 'c'
        return 0.0
    }
}

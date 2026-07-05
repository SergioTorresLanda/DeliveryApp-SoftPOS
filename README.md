# DeliveryApp with SoftPOS integration

https://img.shields.io/badge/Swift-6.0-orange.svg
https://img.shields.io/badge/iOS-16.0+-blue.svg
https://img.shields.io/badge/SPM-compatible-brightgreen.svg
https://img.shields.io/badge/License-Proprietary-red.svg

A production-ready delivery application featuring enterprise-grade SoftPOS (tap-to-phone) payment technology and Apple TSM-as-a-Service integration.

📲 Download on the App Store
https://apps.apple.com/us/app/tulumdeliverys/id6747213576?l=pt-BR

## 📱 Overview
DeliveryApp is a full-featured delivery platform that transforms any NFC-enabled iOS device into a secure payment terminal. Built for enterprise merchants, this app enables contactless payment acceptance directly on the iPhone, eliminating the need for external card readers.

## Key Capabilities

### 💳 SoftPOS (Payment Acceptance)
Tap-to-Phone Technology: Accept contactless payments directly on the iPhone using CoreNFC

EMV Level 3 Compliant: Full EMV contactless kernel implementation

Cloud EMV Architecture: Offloads cryptographic processing to secure cloud infrastructure

Real-time Authorization: Sub-500ms transaction processing

### 🔐 Apple TSM-as-a-Service & Digital Card Provisioning
Secure Enclave Integration: Hardware-backed key generation and storage

Device Attestation: Apple-certified TSM solution for credential provisioning

Mobile Wallet Support: Apple Pay-grade security for digital payments

Instant Provisioning: Seamless card onboarding and tokenization

## 🏗️ Architecture
### 4-Layer Cloud-Native Payment Architecture

┌─────────────────────────────────────────────────────────────┐
│  1. Presentation / UX Layer (SwiftUI)                      │
│     - Reactive state management (@Observable)              │
│     - Transaction UX with clear user feedback              │
│     - No crypto or card data touch                         │
└─────────────────────────────────────────────────────────────┘
                              │
┌─────────────────────────────────────────────────────────────┐
│  2. Mobile Orchestration & NFC Core (Actor-based)          │
│     - CoreNFC controller lifecycle                         │
│     - ISO-7816-4 APDU sequence (SELECT, GPO, READ RECORD)  │
│     - TLV parsing & EMV tag extraction                     │
│     - 500ms ISO timeout handling                           │
└─────────────────────────────────────────────────────────────┘
                              │
┌─────────────────────────────────────────────────────────────┐
│  3. Secure Transport & P2PE Middleware                     │
│     - mTLS + Certificate Pinning                           │
│     - OAuth2 token management (Keychain)                   │
│     - P2PE encryption at the NFC controller                │
│     - Device Attestation (TSM identity proof)              │
└─────────────────────────────────────────────────────────────┘
                              │
┌─────────────────────────────────────────────────────────────┐
│  4. Cloud EMV Kernel & Transaction Processing              │
│     - Hardware Security Module (HSM) integration           │
│     - Cryptogram validation & issuer routing              │
│     - ACID-compliant transaction journaling               │
└─────────────────────────────────────────────────────────────┘

### MVVM + Actor-Based Concurrency
The app follows a clean MVVM architecture with Swift 6 strict concurrency:

~Actors protect mutable state in the NFC and Security layers
~Async/await for all asynchronous operations
~@Observable for reactive UI state management
~Protocol-oriented design for testability and dependency injection

## 🛡️ Security Features
~Security Layer    Implementation
~Secure Enclave    Hardware-backed key generation & storage via kSecAttrTokenIDSecureEnclave
~P2PE    Encrypt at NFC controller, decrypt exclusively in Cloud HSM
~Certificate Pinning    SHA-256 public key pinning in URLSessionDelegate
~OAuth2    Secure token lifecycle with automatic refresh
~Keychain    .accessibleAfterFirstUnlockThisDeviceOnly for PCI DSS compliance
~Device Attestation    Apple TSM-compatible Secure Enclave proof generation
~OWASP Mobile Top 10    Jailbreak detection, secure logging, session management

## 📦 Tech Stack

### Frameworks & Technologies

iOS 16.0+ | SwiftUI | Swift 6
CoreNFC – ISO-14443 contactless communication
Security.framework – Keychain, Secure Enclave, Certificate Pinning
CryptoKit – Cryptographic operations & attestation
Combine – Asynchronous data streams
Swift Package Manager (SPM) – No CocoaPods

### Architecture & Patterns

MVVM with @Observable
Actor-based concurrency for thread safety
Async/await for asynchronous flows
Dependency Injection via initializer injection
CheckedContinuation for bridging delegate-based APIs

## 🔒 PCI DSS Compliance
The app is designed with PCI DSS compliance at its core:

✅ P2PE encryption at the NFC controller
✅ No sensitive card data stored on device
✅ Secure Enclave key generation
✅ Certificate pinning prevents MITM
✅ OWASP M2: Secure logging (no PANs in console)
✅ OWASP M3: Jailbreak detection (mock implementation)
✅ OWASP M5: Biometric/Keychain protection
✅ OWASP M8: Code tampering prevention

## 👥 Team
iOS Architecture & EMV Kernel – Sergio Torres Landa Gonzalez
Backend Cloud EMV – Sergio Torres Landa Gonzalez
Security & Compliance – Sergio Torres Landa Gonzalez

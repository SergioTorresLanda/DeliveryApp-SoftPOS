//
//  PaymentView.swift
//
import SwiftUI

struct PaymentView: View {
    
    let vm = SoftPOSVM(securityManager: SecurityManager.shared,
                       nfcManager: NFCSessionManager.shared)
    
    var body: some View {
        VStack(spacing: 30) {
            Text("SoftPOS Terminal")
                .font(.largeTitle)
            
            Text(vm.statusMessage)
                .font(.headline)
                .padding()
                .multilineTextAlignment(.center)
            
            Button {
                Task {
                    await vm.startPaymentFlow()
                }
            } label: {
                Label(vm.isProcessing ? "Processing..." : "Tap to Pay", systemImage: "wave.3.right")
            }
            .buttonStyle(.borderedProminent)
            .disabled(vm.isProcessing)
        }
        .padding()
    }
    

}

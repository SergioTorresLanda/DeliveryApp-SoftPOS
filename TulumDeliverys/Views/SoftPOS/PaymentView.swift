//
//  PaymentView.swift
//
import SwiftUI

struct PaymentView: View {
    
    private let vm = SoftPOSVM()
    
    var body: some View {
        VStack(spacing: 30) {
            Text("SoftPOS Terminal")
                .font(.largeTitle)
                .bold()
            
            Text(vm.statusMessage)
                .font(.headline)
                .multilineTextAlignment(.center)
                .padding()
                .frame(maxWidth: .infinity)
                .background(Color(.secondarySystemBackground))
                .cornerRadius(12)
            
            // Terminal State UI
            if vm.isApproved {
                VStack(spacing: 12) {
                    Image(systemName: "checkmark.circle.fill")
                        .font(.system(size: 60))
                        .foregroundColor(.green)
                    Text("Payment Approved!")
                        .font(.title2)
                        .bold()
                    Button("New Transaction") {
                        vm.resetPaymentFlow()
                    }
                    .buttonStyle(.borderedProminent)
                }
                .padding()
            } else if vm.isDeclined {
                VStack(spacing: 12) {
                    Image(systemName: "xmark.circle.fill")
                        .font(.system(size: 60))
                        .foregroundColor(.red)
                    Text("Payment Declined")
                        .font(.title2)
                        .bold()
                    Button("Try Again") {
                        vm.resetPaymentFlow()
                    }
                    .buttonStyle(.borderedProminent)
                }
                .padding()
            } else if vm.showError {
                VStack(spacing: 12) {
                    Image(systemName: "exclamationmark.triangle.fill")
                        .font(.system(size: 60))
                        .foregroundColor(.orange)
                    Text("Error")
                        .font(.title2)
                        .bold()
                    Text(vm.errorMessage)
                        .font(.subheadline)
                        .foregroundColor(.secondary)
                        .multilineTextAlignment(.center)
                    Button("Retry") {
                        vm.resetPaymentFlow()
                    }
                    .buttonStyle(.borderedProminent)
                }
                .padding()
            } else {
                // Primary Action Button
                Button {
                    vm.startPaymentFlow()
                } label: {
                    Label(vm.isProcessing ? "Processing..." : "Tap to Pay",
                          systemImage: vm.isProcessing ? "hourglass" : "wave.3.right")
                }
                .buttonStyle(.borderedProminent)
                .disabled(vm.isProcessing)
            }
            
            Spacer()
            
            Text("Version 3.3.3 • SoftPOS + TSM")
                .font(.caption)
                .foregroundColor(.secondary)
        }
        .padding()
        .animation(.easeInOut(duration: 0.25), value: vm.isProcessing)
        .animation(.easeInOut(duration: 0.25), value: vm.statusMessage)
    }
    

}

//How the Flow Works (End-to-End)
//1.User taps "Tap to Pay" → VM calls orchestrator.startTransaction().
//2.Orchestrator transitions to .waitingForTap, starts a 500ms timeout task.
//3.NFC session begins (modal system UI). If user taps a card within 500ms:
//4.Orchestrator transitions to .readingCard → .processingCryptogram.
//5.Card data is read via NFCSessionManager.
//6.Cryptogram is packaged into TransactionPayload.
//7.Orchestrator transitions to .authorizingCloud, sends payload via SecurityManager.
//8.Mock cloud responds with APPROVED or DECLINED.
//9.Orchestrator transitions to terminal state (.approved or .declined).
//10.UI reflects the result with appropriate icon and message.
//11.User can reset and start a new transaction.
//12.If the tap times out (> 500ms):
//13.Orchestrator transitions to .error(message: "Card tap timed out...").
//14.User can reset and retry.

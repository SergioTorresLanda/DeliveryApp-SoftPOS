//
//  MenuView.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 09/03/26.
//

import SwiftUI

struct MenuView: View {
    @EnvironmentObject var viewmodel: MyViewModel
    
    var body: some View {
        NavigationStack {
            List(viewmodel.menuItems) { item in
                HStack {
                    Text(item.name)
                    Spacer()
                    Text("$\(item.price)")
                }
            }
            .navigationTitle("Tulum Delivery")
            .overlay {
                if viewmodel.isLoading {
                    ProgressView()
                }
            }
            .task {
                // Trigger the GraphQL flow when the view appears
                if viewmodel.menuItems.isEmpty {
                    await viewmodel.loadMenu()
                }
            }
        }
    }
}

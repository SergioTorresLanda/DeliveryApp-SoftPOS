//
//  RemoteDataSource.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 10/06/25.
//
import Foundation
import FirebaseCore
import FirebaseFirestore

protocol RemoteDataSourceProtocol {
    func fetchProductsFromAPI() async throws -> [Item2]
    func fetchItems() async throws -> [ItemDTO]
}

struct RemoteDataSource: RemoteDataSourceProtocol {
    private let db = Firestore.firestore()
    //private let apiURL = URL(string: "https://www.amiiboapi.com/api/amiibo/")
    
    func fetchProductsFromAPI() async throws -> [Item2] {
        var items: [Item2] = []
        do {
            let snapshot = try await db.collection("products").getDocuments()
            items = try snapshot.documents.compactMap { document in
                try document.data(as: Item2.self)
            }
            print("Successfully fetched \(items.count) items.")
            return items
        } catch {
            print("Error getting documents or decoding: \(error)")
            throw error
        }
    }
    
    func addProducts() async throws {
        do {
          let ref = try await db.collection("products").addDocument(data: [
            "name": "Bacachat",
            "image": "image234",
            "price": 1834
          ])
          print("Document added with ID: \(ref.documentID)")
        } catch {
          print("Error adding document: \(error)")
        }
    }
    
    func fetchItems() async throws -> [ItemDTO] {
            let url = URL(string: "https://api.tulumdeliverys.com/graphql")!
            var request = URLRequest(url: url)
            request.httpMethod = "POST"
            request.setValue("application/json", forHTTPHeaderField: "Content-Type")
            
            // 1. Define the exact shape of the data you want
            let query = """
            query {
                fetchMenuItems {
                    id
                    name
                    image
                    price
                    category
                    active
                }
            }
            """
            
            // 2. Wrap it in a JSON dictionary under the key "query"
            let requestBody: [String: String] = ["query": query]
            request.httpBody = try JSONEncoder().encode(requestBody)
            
            // 3. Make the standard URLSession call
            let (data, response) = try await URLSession.shared.data(for: request)
            
            // 4. Decode the nested GraphQL structure
            let graphQLResponse = try JSONDecoder().decode(GraphQLResponse.self, from: data)
            return graphQLResponse.data.fetchMenuItems
        }
}

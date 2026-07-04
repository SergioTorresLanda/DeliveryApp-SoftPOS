//
//  Repository.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 10/06/25.
//
import Foundation
import SwiftUI
import SwiftData

protocol ProductRepositoryProtocol {
    func fetchAndProcess() async throws -> ([Item], Set<String>)
    func getMenuItems() async throws -> [Item]
}

actor Repository: ProductRepositoryProtocol {
    private let remote: any RemoteDataSourceProtocol
    private let local: any DataManagerProtocol
//"I use the explicit any keyword to acknowledge the creation of an existential type.
    //While I could use Generics to achieve static dispatch, using existentials here allows
    //for much cleaner dependency injection and easier mocking in our unit tests,
    //which outweighs the negligible dynamic dispatch overhead on a network layer."
    init(remoteDataSource: RemoteDataSourceProtocol, localDataSource: any DataManagerProtocol) {
        self.remote = remoteDataSource
        self.local = localDataSource
    }
    
    // 2. This method runs on a background thread automatically!
    func fetchAndProcess() async throws -> ([Item], Set<String>) {
        
        // A. Fetch raw data
        let apiProducts = try await remote.fetchProductsFromAPI()
        
        // B. HEAVY WORK: The Loop happens here (Background)
        var items: [Item] = []
        var categories: Set<String> = []
        
        for prod in apiProducts {
            guard prod.active ?? true else { continue }
            
            let item = Item(
                id: prod.id ?? UUID().uuidString,
                name: prod.name ?? "--",
                image: prod.image ?? "--",
                price: prod.price ?? 0,
                category: prod.category ?? "--",
                active: true
            )
            
            categories.insert(prod.category ?? "ARTESANAL")
            items.append(item)
            // try await local.save(item)
        }
        // C. Persist all at once (Optional)
        try await addTransaction(items: items)
        
        return (items, categories)
    }
    
    func addTransaction(items: [Item]) async throws {
        // 3. We await the abstract protocol method
        try await local.save(items)
    }
    
    func fetchActiveProducts() async throws -> [Item] {
        // 1. Build the query configuration here
        var descriptor = FetchDescriptor<Item>(
            predicate: #Predicate { $0.isFavorite == true },
            sortBy: [SortDescriptor(\.name)]
        )
        
        // 2. Extra power! (You couldn't do this with Version A)
        descriptor.fetchLimit = 50
        
        return try await local.fetch(descriptor)
    }
    
    //GRAPH QL
    func getMenuItems() async throws -> [Item] {
        // Fetch the lightweight network objects
        let dtos = try await remote.fetchItems()
        
        // Map them into your heavy SwiftData models
        return dtos.map { dto in
            Item(
                id: dto.id,
                name: dto.name,
                image: dto.image,
                price: dto.price,
                category: dto.category,
                active: dto.active
            )
        }
    }
}

///LOCK ACTOR STATE
 actor DataRefresher {
     private var isRefreshing = false
     private var cachedData: String = ""

     func refreshData() async throws -> String {
         // 1. Thread-safe check because it happens before any `await`
         guard !isRefreshing else {
             print("Already refreshing, aborting this task.")
             return cachedData
         }

         // 2. Lock the door
         isRefreshing = true
         
         // 3. Guarantee the door unlocks when we leave, even if we crash/throw
         defer { isRefreshing = false }

         // 4. Suspend. The actor door is open to others, but they will hit the guard let!
         let newData = ""//try await fetchFromNetwork()
         
         // 5. We are back. Update state.
         self.cachedData = newData
         return newData
     }
 }
 
 /*
 actor ImageDownloader {
     private var activeTask: Task<Data, Error>?

     func downloadImage() async throws -> Data {
         // 1. If a task is already running, just await its result!
         if let existingTask = activeTask {
             print("Piggybacking on existing task...")
             return try await existingTask.value
         }

         // 2. If no task exists, create one.
         let task = Task {
             // Simulate slow network call
             try await Task.sleep(nanoseconds: 2_000_000_000)
             return Data()
         }

         // 3. Save the task so others can find it
         activeTask = task

         // 4. Await our newly created task
         let result = try await task.value
         
         // 5. Clean up when done
         activeTask = nil
         
         return result
     }
 }
 */

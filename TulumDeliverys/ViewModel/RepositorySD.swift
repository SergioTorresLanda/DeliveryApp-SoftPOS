//
//  RepositorySD.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 26/06/26.
//
import Foundation
import SwiftUI
import SwiftData

actor RepositorySD<Remote: RemoteDataSourceProtocol, Local: DataManagerProtocol>: ProductRepositoryProtocol {
        
    // 1. Properties now use the generic types, not 'any'
    private let remote: Remote
    private let local: Local
    
    // 2. The initializer expects the exact generic types resolved at the call site
    init(remoteDataSource: Remote, localDataSource: Local) {
        self.remote = remoteDataSource
        self.local = localDataSource
    }
    
    func fetchAndProcess() async throws -> ([Item], Set<String>) {
        var items: [Item] = []
        var categories: Set<String> = []
        
        return (items, categories)
    }
    
    func getMenuItems() async throws -> [Item] {
        let x: [Item] = []
        return x
    }
}

// Example instantiation
//let api = LiveRemoteAPI()
//let db = CoreDataManager()

// The compiler knows this is Repository<LiveRemoteAPI, CoreDataManager>
//let repo = RepositorySD(remoteDataSource: api, localDataSource: db)

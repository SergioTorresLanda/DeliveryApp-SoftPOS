//
//  Item.swift
//  TulumDeliverys
//
//  Created by Sergio Torres Landa González on 10/06/25.
//

import Foundation
import SwiftData
import FirebaseFirestore
//import FirebaseFirestoreSwift

@Model
final class Item {
    var id : String
    //var timestamp: Date
    var name : String
    var isFavorite : Bool
    var image: String
    var price: Int
    var category:String
    var selectedItems:Int
    var active:Bool

    init(id:String, name:String, image:String, price:Int, category:String, active:Bool) {
        self.id = id
        self.name = name
        self.image = image
        self.price = price
        self.category = category
        self.active = active
        isFavorite = false
        selectedItems=0
    }
}

struct Item2: Codable, Identifiable { // Identifiable es bueno para SwiftUI
    @DocumentID var id: String? // Mapea automáticamente el ID del documento
    var name: String?
    var image: String?
    var price: Int?
    var category:String?
    var active:Bool?
}

struct GraphQLResponse: Decodable {
    let data: MenuData
}

struct MenuData: Decodable {
    let fetchMenuItems: [ItemDTO]
}

struct ItemDTO: Decodable {
    let id: String
    let name: String
    let image: String
    let price: Int
    let category: String
    let active: Bool
}


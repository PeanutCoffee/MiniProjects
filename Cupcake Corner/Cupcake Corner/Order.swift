//
//  Order.swift
//  Cupcake Corner
//
//  Created by Aarish Rahman on 31/07/21.
//

import Foundation

class Order: ObservableObject, Codable{
    static let types = ["Vanilla","Strawberry","Chocolate","Pineapple"]
    
    @Published var type = 0
    @Published var quantity = 1
    
    @Published var addSprinkles = false
    @Published var extraFrosting = false
    
    @Published var specialRequestEnabled = false{
        didSet{
            if specialRequestEnabled == false{
                addSprinkles = false
                extraFrosting = false
            }
        }
    }
    
    @Published var name = ""
    @Published var streetAddress = ""
    @Published var city = ""
    @Published var zip = ""
    
    var hasValidAddress: Bool{
        if name.isEmptyOrWhitespace() || streetAddress.isEmptyOrWhitespace() || city.isEmptyOrWhitespace() || zip.isEmptyOrWhitespace() {
            return false
        }
        return true
    }
     
    var cost:Double{
        var cost = Double(quantity) * 2
        
        cost += (Double(type) / 2)
        
        if addSprinkles == true{
            cost+=Double(quantity)/2
        }
        
        if extraFrosting == true{
            cost+=Double(quantity)
        }
        return cost
    }
    
    enum CodingKeys: CodingKey {
        case  type, quantity, extraFrosting, addSprinkles, name, streetAddress, city, zip
    }
    
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        
        try container.encode(type,forKey: .type)
        try container.encode(quantity,forKey: .quantity)
        try container.encode(addSprinkles,forKey: .addSprinkles)
        try container.encode(extraFrosting,forKey: .extraFrosting)
        try container.encode(name,forKey: .name)
        try container.encode(streetAddress,forKey: .streetAddress)
        try container.encode(city,forKey: .city)
        try container.encode(zip,forKey: .zip)
        
    }
    
    init() { }
    
    required init(from decoder: Decoder) throws{
        let container = try decoder.container(keyedBy: CodingKeys.self)
        type = try container.decode(Int.self, forKey: .type)
        quantity = try container.decode(Int.self, forKey: .quantity)
        
        extraFrosting = try container.decode(Bool.self, forKey: .extraFrosting)
        addSprinkles = try container.decode(Bool.self, forKey: .addSprinkles)
        
        name = try container.decode(String.self, forKey: .name)
        streetAddress = try container.decode(String.self, forKey: .streetAddress)
        city = try container.decode(String.self, forKey: .city)
        zip = try container.decode(String.self, forKey: .zip)
        

    }
    
}
extension String {
    func isEmptyOrWhitespace() -> Bool {
        
        // Check empty string
        if self.isEmpty {
            return true
        }
        // Trim and check empty string
        return (self.trimmingCharacters(in: .whitespaces) == "")
    }
}

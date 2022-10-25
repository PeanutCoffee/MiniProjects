//
//  ContentView.swift
//  Cupcake Corner
//
//  Created by Aarish Rahman on 31/07/21.
//

import SwiftUI

struct ContentView: View {
    @ObservedObject var order = Order()
    
    var body: some View {
        NavigationView{
            Form{
                Section{
                    Picker("Select your type", selection: $order.type){
                        ForEach(0..<Order.types.count,id: \.self){
                            Text(Order.types[$0])
                        }
                    }
                    
                    Stepper(value: $order.quantity, in:1...20){
                        Text("Number of cakes: \(order.quantity)")
                    }
                }
                
                Section{
                    Toggle(isOn: $order.specialRequestEnabled.animation()) {
                        Text("Any special requests?")
                    }
                    if order.specialRequestEnabled{
                        Toggle(isOn: $order.extraFrosting){
                            Text("Extra Frosting")
                        }
                        Toggle(isOn: $order.addSprinkles){
                            Text("Add Sprinkles")
                        }
                    }
                }
                Section{
                    NavigationLink(destination: AddressView(order: order)){
                        Text("Delivery Details")
                    }
                }
            }
            .navigationBarTitle("Cupcake Corner")
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

//
//  AddressView.swift
//  Cupcake Corner
//
//  Created by Aarish Rahman on 31/07/21.
//

import SwiftUI

struct AddressView: View {
    @ObservedObject var order: Order
    var body: some View {
        Form{
            Section{
                TextField("Name",text: $order.name)
                TextField("Street", text:$order.streetAddress)
                TextField("City", text: $order.city)
                TextField("zip", text: $order.zip)
            }
            Section{
                NavigationLink(destination: CheckOutView(order: order)){
                    Text("Check out")
                }
                .disabled(order.hasValidAddress == false)
            }
            
        }
        .navigationBarTitle("Delivery details", displayMode: .inline)
        
    }
}

struct AddressView_Previews: PreviewProvider {
    static var previews: some View {
        AddressView(order: Order())
    }
}

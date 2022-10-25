//
//  CheckOutView.swift
//  Cupcake Corner
//
//  Created by Aarish Rahman on 31/07/21.
//

import SwiftUI

struct CheckOutView: View {
    @State private var confirmationMessage = ""
    @State private var showingConfirmation = false
    @State private var alertMessage = ""
    
    @ObservedObject var order: Order
    
    var body: some View {
        GeometryReader{geo in
            ScrollView{
                VStack{
                    Image("cupcakes")
                        .resizable()
                        .scaledToFit()
                        .frame(width:geo.size.width)
                    
                    Text("Your total is $\(self.order.cost, specifier: "%.2f")")
                        .font(.title)
                    Button("Place Order"){
                        self.placeOrder()
                            
                    }
                    .padding()
                    
                    
                    
                }
            }
            
            .alert(isPresented: $showingConfirmation) {
                Alert(title: Text(alertMessage), message: Text(confirmationMessage), dismissButton: .default(Text("OK")))
            }
        }
    }
    func placeOrder() {
        guard let encoded = try? JSONEncoder().encode(order) else {
            print("Failed to encode order")
            return
        }
        let url = URL(string: "https://reqres.in/api/cupcakes")!
        var request = URLRequest(url: url)
        request.setValue("application/json", forHTTPHeaderField: "Content-Type")
        request.httpMethod = "POST"
        request.httpBody = encoded
        
        URLSession.shared.dataTask(with: request) { data, response, error in
            guard let data = data else {
                print("No data in response: \(error?.localizedDescription ?? "Unknown error").")
                self.showingConfirmation = true
                self.confirmationMessage = "Turn on Wifi or Mobile Data"
                self.alertMessage = "No Internet"
    
                return
            }
            if let decodedOrder = try? JSONDecoder().decode(Order.self, from: data) {
                self.confirmationMessage = "Your order for \(decodedOrder.quantity)x \(Order.types[decodedOrder.type].lowercased()) cupcakes is on its way!"
                self.showingConfirmation = true
                self.alertMessage = "Thank You"
            } else {
                print("Invalid response from server")
               
            }
        }.resume()
        
        
        
        
        
    }
    
}

struct CheckOutView_Previews: PreviewProvider {
    static var previews: some View {
        CheckOutView(order: Order())
    }
}

//
//  ContentView.swift
//  BetterRest
//
//  Created by Aarish Rahman on 21/06/21.
//

import SwiftUI

struct ContentView: View {
    @State private var wakeUp = defaultWakeTime
    @State private var sleepAmount = 8.0
    @State private var coffeeAmount = 1
    
    @State private var alertTitle = ""
    @State private var alertMessage = ""
  
    
    var body: some View {
        NavigationView{
            Form{
                Section{
                    Text("When do you want to wake up?")
                        .font(.headline)
                    DatePicker("Please enter a time", selection: $wakeUp, displayedComponents: .hourAndMinute)
                        .labelsHidden()
                        .frame(width: 0, height: 120, alignment: .leading)
                        .datePickerStyle(WheelDatePickerStyle())
                                            
                }
                Section{
                    Text("Desired amount of sleep")
                        .font(.headline)
                    
                    Stepper(value: $sleepAmount, in: 4...12, step: 0.25) {
                        Text("\(sleepAmount, specifier: "%g") hours")
                    }
                }
                
                Section{
                    Text("Daily coffee intake")
                        .font(.headline)
                    
                    Picker("Coffee Amount", selection: $coffeeAmount) {
                        ForEach(1..<21){
                            if $0 > 1 {
                                Text("\($0) cups")
                            } else {
                                Text("1 cup")
                            }
                        }
                    }
                    .pickerStyle(WheelPickerStyle())
                    .frame(height: 60, alignment: .center)
                    .clipped()
                    .compositingGroup()
                }
                Section {
                    Text("Your recommended bed time is")
                    Text(calculateBedtime())
                        .font(.largeTitle)
                        .foregroundColor(.red)
                }
                
            }
            
            .navigationBarTitle("BetterRest")
        }
        
    }
    func calculateBedtime() -> String{
        let model = SleepCalculator()
        let components = Calendar.current.dateComponents([.hour, .minute], from: wakeUp)
        let hour = (components.hour ?? 0) * 60 * 60
        let minute = (components.minute ?? 0) * 60
        do {
            let prediction = try model.prediction(wake: Double(hour + minute), estimatedSleep: sleepAmount, coffee: Double(coffeeAmount))
            
            let sleepTime = wakeUp - prediction.actualSleep
            let formatter = DateFormatter()
            formatter.timeStyle = .short
            
            return formatter.string(from: sleepTime)
            
            
            
        } catch {
            return "Sorry, there was a problem calculating your bedtime."
            
        }
        
        
    }
    static var defaultWakeTime: Date {
        var components = DateComponents()
        components.hour = 7
        components.minute = 0
        return Calendar.current.date(from: components) ?? Date()
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

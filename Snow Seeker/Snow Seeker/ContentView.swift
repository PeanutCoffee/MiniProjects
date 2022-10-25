//
//  ContentView.swift
//  Snow Seeker
//
//  Created by Aarish on 28/05/22.
//

import SwiftUI

struct ContentView: View {
    let resorts: [Resort] = Bundle.main.decode("resorts.json")
    @State private var searchText = ""
    @StateObject var favorites = Favorites()
    @State private var sort: Int = 0
    @State private var isSortedByName = false
    @State private var isSortedByCountry = false
    var body: some View {
        NavigationView{
            List(sortedFilteredResort){ resort in
                NavigationLink{
                    ResortView(resort: resort)
                }label: {
                    HStack{
                        Image(resort.country)
                            .resizable()
                            .scaledToFill()
                            .frame(width: 40, height: 25)
                            .clipShape(
                                RoundedRectangle(cornerRadius: 5)
                            )
                            .overlay(
                                RoundedRectangle(cornerRadius: 5)
                                    .stroke(.black, lineWidth: 1)
                            )
                        
                        VStack(alignment: .leading){
                            Text(resort.name)
                                .font(.headline)
                            Text("\(resort.runs) runs")
                                .foregroundColor(.secondary)
                        }
                        if favorites.contains(resort) {
                            Spacer()
                            Image(systemName: "heart.fill")
                                .accessibilityLabel("This is a favorite resort")
                                .foregroundColor(.red)
                        }
                    }
                }
                
            }
            .toolbar{
                ToolbarItem(placement: .navigationBarTrailing) {
                    Picker("sort", selection: $sort) {
                        Label(" Default", systemImage: "arrow.up.arrow.down").tag(0)
                        Label(" By Country", systemImage: "arrow.up.arrow.down").tag(1)
                        Label(" By Name", systemImage: "arrow.up.arrow.down").tag(2)
                      
                    }.onChange(of: sort) { value in
                        print("sort \(value)")
                        if value == 0 {
                            isSortedByName = false
                            isSortedByCountry = false
                        }else if value == 1 {
                            isSortedByName = false
                            isSortedByCountry = true
                        }else{
                            isSortedByName = true
                            isSortedByCountry = false
                        }
                    }
                }
            }
            .navigationTitle("Resorts")
            .searchable(text: $searchText, prompt: "Search for a resort")
            
            WelcomeView()
        }
        .environmentObject(favorites)
    }
    var sortedFilteredResort: [Resort] {
        if isSortedByName {
            // by name
            return filteredResorts.sorted(by: { $0.name < $1.name })
        }
        if  isSortedByCountry {
            // by country
            return filteredResorts.sorted(by: {$0.country < $1.country})
        }
        else {
            return filteredResorts
        }
    }
    var filteredResorts: [Resort]{
        if searchText.isEmpty {
            return resorts
        }else{
            return resorts.filter{$0.name.localizedCaseInsensitiveContains(searchText)}
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

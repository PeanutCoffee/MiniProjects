//
//  AnimeList.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import SwiftUI

struct AnimeTracked: View {
    @ObservedObject var book : Book
    @ObservedObject var manga : Manga
    @ObservedObject var anime : Anime
    @ObservedObject var movie : Movie
   
    @State private var showAddOption = false
    @State private var searchText = ""
    var body: some View {
        
        List{
            
            ForEach(filteredAnime.indices, id: \.self){ index in
                NavigationLink(destination: AnimeDetails(index: index).environmentObject(anime)){
                    HStack{
                        if let displayedImage = AddView.loadImageFromDocumentDirectory(fileName: filteredAnime[index].id.uuidString) {
                            Image(uiImage: displayedImage)
                                .resizable()
                                .scaledToFit()
                                .cornerRadius(2)
                                .frame(width: 50,height: 70)
                                
                        } else {
                            Image(systemName: "photo")
                                .resizable()
                                .foregroundColor(.black)
                                .scaledToFit()
                                .cornerRadius(2)
                                .frame(width: 50,height: 70)
                        }
                        VStack(alignment: .leading){
                            Text(filteredAnime[index].name)
                                .font(.title2)
                                .fontWeight(.bold)
                            Text(" Ep \(filteredAnime[index].episode)")
                                .font(.subheadline)
                                .fontWeight(.semibold)
                                .foregroundColor(.secondary)
                            HStack(spacing: 0){
                                Image(systemName: "star.fill")
                                    .foregroundColor(.orange)
                                    .font(.subheadline)
                                Text("\(filteredAnime[index].rating)")
                                    .font(.subheadline)
                                    .fontWeight(.semibold)
                                    .foregroundColor(.secondary)
                            }.padding(.leading,3)
                            
                            Spacer()
                        }
                       
                       
                    }.frame(height: 80)
                }
            }
            .onDelete(perform: removeItems)
            
        }
        .searchable(text: $searchText)
        .navigationTitle("Anime")
        .toolbar{
            ToolbarItem(placement: .navigationBarTrailing) {
                Button {
                    showAddOption = true
                } label: {
                    Label("", systemImage: "plus")
                }
                
            }
        }
        .sheet(isPresented: $showAddOption){
            AddView(selectedOption: 1, manga: self.manga, anime: self.anime, movie: self.movie, book: self.book)
        }
       
        
    }
    
    
    var filteredAnime: [AnimeList]{
        if searchText.isEmpty {
            return anime.items
        }else{
            return anime.items.filter{$0.name.localizedCaseInsensitiveContains(searchText)}
        }
    }
    func removeItems(at offsets: IndexSet) {
        anime.items.remove(atOffsets: offsets)
        generator.notificationOccurred(.success)
    }
}

//struct AnimeTracked_Previews: PreviewProvider {
//    static var previews: some View {
//        MovieTracked()
//    }
//}

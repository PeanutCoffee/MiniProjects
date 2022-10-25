//
//  MovieList.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import SwiftUI

struct MangaTracked: View {
    @ObservedObject var book : Book
    @ObservedObject var manga : Manga
    @ObservedObject var anime : Anime
    @ObservedObject var movie : Movie
    @State private var showAddOption = false
    @State private var searchText = ""
    
    var body: some View {
        
        List{
            ForEach(filteredManga.indices, id: \.self){ index in
                NavigationLink(destination: MangaDetails(index: index).environmentObject(manga)) {
                    HStack{
                        if let displayedImage = AddView.loadImageFromDocumentDirectory(fileName: filteredManga[index].id.uuidString) {
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
                            Text(filteredManga[index].name)
                                .font(.title2)
                                .fontWeight(.bold)
                            Text(" Ch \(filteredManga[index].chapters)")
                                .font(.subheadline)
                                .fontWeight(.semibold)
                                .foregroundColor(.secondary)
                            HStack(spacing: 0){
                                Image(systemName: "star.fill")
                                    .foregroundColor(.orange)
                                    .font(.subheadline)
                                Text("\(filteredManga[index].rating)")
                                    .font(.subheadline)
                                    .fontWeight(.semibold)
                                    .foregroundColor(.secondary)
                            }.padding(.leading,3)
                            
                            Spacer()
                        }
                    }
                    .frame(height: 80)
                    
                }
            }
            .onDelete(perform: removeItems)
            
        }
        
        .searchable(text: $searchText)
        .navigationTitle("Manga")
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
            AddView(selectedOption: 0,manga: manga
                    , anime: self.anime, movie: self.movie, book: self.book)
            
        }
      
        
    }
    
    
    
    var filteredManga: [MangaList]{
        
        if searchText.isEmpty {
            return manga.items
        }else{
            return manga.items.filter{$0.name.localizedCaseInsensitiveContains(searchText)}
        }
    }
    
    func removeItems(at offsets: IndexSet) {
        
        manga.items.remove(atOffsets: offsets)
        generator.notificationOccurred(.success)
    }
    
}

//struct MangaTracked_Previews: PreviewProvider {
//    static var previews: some View {
//        MangaTracked()
//    }
//}

//
//  MovieList.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import SwiftUI

struct MovieTracked: View {
    @ObservedObject var book : Book
    @ObservedObject var manga : Manga
    @ObservedObject var anime : Anime
    @ObservedObject var movie : Movie
    
    @State private var showAddOption = false
    @State private var searchText = ""
    var body: some View {
        
        List{
            ForEach(filteredMovie.indices, id: \.self){ index in
                NavigationLink(destination:MovieDetails(index: index).environmentObject(movie)) {
                HStack{
                    if let displayedImage = AddView.loadImageFromDocumentDirectory(fileName: filteredMovie[index].id.uuidString) {
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
                        Text(filteredMovie[index].name)
                            .font(.title2)
                            .fontWeight(.bold)
                        Text(" Ep \(filteredMovie[index].episode)")
                            .font(.subheadline)
                            .fontWeight(.semibold)
                            .foregroundColor(.secondary)
                        HStack(spacing: 0){
                            Image(systemName: "star.fill")
                                .foregroundColor(.orange)
                                .font(.subheadline)
                            Text("\(filteredMovie[index].rating)")
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
        .navigationTitle("Movies & Shows")
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
            AddView(selectedOption: 2,manga: self.manga, anime: self.anime, movie: self.movie, book: self.book)
        }
        
        
    }
    func removeItems(at offsets: IndexSet) {
        movie.items.remove(atOffsets: offsets)
        generator.notificationOccurred(.success)
    }
    var filteredMovie: [MoviesList]{
        if searchText.isEmpty {
            return movie.items
        }else{
            return movie.items.filter{$0.name.localizedCaseInsensitiveContains(searchText)}
        }
    }
}

//struct MovieTracked_Previews: PreviewProvider {
//    static var previews: some View {
//        MovieTracked()
//    }
//}

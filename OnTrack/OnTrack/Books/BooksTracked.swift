//
//  MovieList.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import SwiftUI

struct BooksTracked: View {
    @ObservedObject var book : Book
    @ObservedObject var manga : Manga
    @ObservedObject var anime : Anime
    @ObservedObject var movie : Movie
    @State private var showAddOption = false
    @State private var searchText = ""
    
    var body: some View {
        
        List{
            ForEach(filteredbooks.indices, id: \.self){ index in
                NavigationLink(destination: BookDetails(index: index).environmentObject(book)) {
                    HStack{
                        if let displayedImage = AddView.loadImageFromDocumentDirectory(fileName: filteredbooks[index].id.uuidString) {
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
                            Text(filteredbooks[index].name)
                                .font(.title2)
                                .fontWeight(.bold)
                            Text(" Ch \(filteredbooks[index].chapters)")
                                .font(.subheadline)
                                .fontWeight(.semibold)
                                .foregroundColor(.secondary)
                            HStack(spacing: 0){
                                Image(systemName: "star.fill")
                                    .foregroundColor(.orange)
                                    .font(.subheadline)
                                Text("\(filteredbooks[index].rating)")
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
            //
            
        }
        .searchable(text: $searchText)
        .navigationTitle("Books")
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
            AddView(selectedOption: 3, manga: self.manga, anime: self.anime, movie: self.movie, book: self.book)
        }
            }
    var filteredbooks: [BookList]{
        if searchText.isEmpty {
            return book.items
        }else{
            return book.items.filter{$0.name.localizedCaseInsensitiveContains(searchText)}
        }
    }
    func removeItems(at offsets: IndexSet) {
        book.items.remove(atOffsets: offsets)
        generator.notificationOccurred(.success)
    }
}



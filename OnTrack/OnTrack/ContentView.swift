//
//  ContentView.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import SwiftUI

struct CustomGroup:View {
    var img = ""
    var count = ""
    var col:Color
    var label = ""
    var body: some View{
        VStack{
            GroupBox(label:
                        HStack{
                            Text("\(Image(systemName: img))")
                                .foregroundColor(col)
                                .font(.title)
                            Spacer()
                            Text(count)
                                .foregroundColor(.gray)
                                .font(.title)
                                .fontWeight(.bold)
                        }
            ){
                VStack{
                    Text("")
                    HStack{
                        Text(label)
                            .font(.subheadline)
                            .foregroundColor(.gray)
                            .fontWeight(.semibold)
                            .lineLimit(1)
                        Spacer()
                    }
                }
            }.cornerRadius(15)
                
            
        }
    }
}

struct ContentView: View {
    @State private var searchText = ""
    @ObservedObject var book : Book
    @ObservedObject var manga : Manga
    @ObservedObject var anime : Anime
    @StateObject var movie : Movie
    @State var movieCount: Int?
    @State var bookCount: Int?
    @State var animeCount : Int?
    @State var mangaCount: Int?
    var body: some View {
        NavigationView{
            ScrollView{
            VStack{
                HStack{
                    NavigationLink(destination: MangaTracked(book: book, manga: manga, anime: anime, movie: movie)) {
                        CustomGroup(img: "books.vertical", count: "\(manga.items.count)", col: Color.green, label: "Manga")
                            
                    }
                    NavigationLink(destination: AnimeTracked(book: book, manga: manga, anime: anime, movie: movie)){
                        CustomGroup(img: "tv", count: "\(anime.items.count)", col: Color.red, label: "Anime")
                    }
                    
                }.padding(.horizontal)
                HStack{
                    NavigationLink(destination: MovieTracked(book: book, manga: manga, anime: anime, movie: movie)) {
                        CustomGroup(img: "film", count: "\(movie.items.count)", col: Color.gray, label: "Movies & Shows")
                    }
                    NavigationLink(destination: BooksTracked(book: book, manga: manga, anime: anime, movie: movie)) {
                        CustomGroup(img: "text.book.closed", count: "\(book.items.count)", col: Color.blue, label: "Books")
                    }
                    
                    
                }.padding(.horizontal)
                Spacer()
            }
            .onAppear(perform: {
             
//                mangaCount = manga.items.count
//                bookCount = book.items.count
//                animeCount = anime.items.count
//                movieCount = movie.items.count
            })
            .navigationTitle("Track")
//            .searchable(text: $searchText)
            }
        }
    }
   
}

//struct ContentView_Previews: PreviewProvider {
//    static var previews: some View {
//        ContentView()
//    }
//}

//
//  TrackingItems.swift
//  Series on Track
//
//  Created by Aarish on 29/05/22.
//

import Foundation
import SwiftUI

struct MangaList: Identifiable, Codable{
    var id = UUID()
    var name: String
    var rating: Int
    var chapters: Int
    var review: String
}

class Manga: ObservableObject {
    @Published var items = [MangaList](){
        didSet {
            do {
                let data = try JSONEncoder().encode(items)
                try data.write(to: saveManga, options: [.atomic, .completeFileProtection])
            } catch {
                print("Unable to save data.")
            }
        }
    }
    init() {
        do {
            let data = try Data(contentsOf: saveManga)
            
            items = try JSONDecoder().decode([MangaList].self, from: data)
            
        } catch {
            items = []
            print("Unable to .")
        }

    }
}

struct AnimeList: Identifiable, Codable{
    var id = UUID()
    var name: String
    var rating: Int
    var episode: Int
    var review: String
}

class Anime: ObservableObject {
    @Published var items = [AnimeList](){
        didSet {
            do {
                let data = try JSONEncoder().encode(items)
                try data.write(to: saveAnime, options: [.atomic, .completeFileProtection])
            } catch {
                print("Unable to save data.")
            }
        }
    }
    init() {
        do {
            let data = try Data(contentsOf: saveAnime)
            
            items = try JSONDecoder().decode([AnimeList].self, from: data)
            
        } catch {
            items = []
            print("Unable to .")
        }

    }
}

struct MoviesList: Identifiable, Codable{
    var id = UUID()
    var name: String
    var rating: Int
    var episode: Int
    var review: String
//    let image: MyImage
}
//struct MyImage: Codable{
//    let imageData: Data?
//
//    init(withImage image: UIImage) {
//        self.imageData = image.pngData()
//    }
//
//    func getImage() -> UIImage? {
//        guard let imageData = self.imageData else {
//            return nil
//        }
//        let image = UIImage(data: imageData)
//
//        return image
//    }
//}
class Movie: ObservableObject {
    @Published var items = [MoviesList](){
        
        didSet {
            
            do {
                let data = try JSONEncoder().encode(items)
                try data.write(to: saveMovies, options: [.atomic, .completeFileProtection])
            } catch {
                print("Unable to save data.")
            }
        }
    }
    init() {
        do {
            let data = try Data(contentsOf: saveMovies)
            
            items = try JSONDecoder().decode([MoviesList].self, from: data)
            
        } catch {
            items = []
            print("Unable to .")
        }

    }
}

struct BookList: Identifiable, Codable{
    var id = UUID()
    var name: String
    var rating: Int
    var chapters: Int
    var review: String
    
}


class Book: ObservableObject {
    @Published var items = [BookList](){
        didSet {
            do {
                let data = try JSONEncoder().encode(items)
                try data.write(to: saveBooks, options: [.atomic, .completeFileProtection])
            } catch {
                print("Unable to save data.")
            }
        }
    }
    init() {
        do {
            let data = try Data(contentsOf: saveBooks)
            
            items = try JSONDecoder().decode([BookList].self, from: data)
            
        } catch {
            items = []
            print("Unable to .")
        }

    }
}
class NumbersOnly: ObservableObject {
    @Published var value = "" {
        didSet {
            let filtered = value.filter { $0.isNumber }
            
            if value != filtered {
                value = filtered
            }
        }
    }
}

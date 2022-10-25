//
//  OnTrackApp.swift
//  OnTrack
//
//  Created by Aarish on 30/05/22.
//

import SwiftUI

@main
struct OnTrackApp: App {
    @State var value = 0
    var body: some Scene {
        WindowGroup {
            ContentView(book: Book(), manga: Manga(), anime: Anime(), movie: Movie())
        }
    }
}

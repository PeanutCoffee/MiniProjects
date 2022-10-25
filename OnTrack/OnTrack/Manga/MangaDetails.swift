//
//  MovieDetails.swift
//  OnTrack
//
//  Created by Aarish on 31/05/22.
//

import SwiftUI

struct MangaDetails: View {

    @EnvironmentObject var mangaObject : Manga
    @State private var name = ""
    @State private var rating = 1
    @State private var chapters: Int = 0
    @State private var review = ""
    @State private var inputImage: UIImage?
    @State private var showImagePicker = false
    @State private var showEditView = false
    var imageToDisplay: Image {
        if let displayedImage = inputImage {
            return Image(uiImage: displayedImage)
        } else {
            return Image(uiImage: UIImage(named: "default")!)
                
        }
       
    }
    var index: Int
    var body: some View {
        
        
            
        List{
            
//            if (inputImage == nil) {
//                Image(systemName: "photo")
//                    .resizable()
//                    .scaledToFit()
//                    .foregroundColor(.black)
//                    .contextMenu{
//                        Button{
//                            showImagePicker = true
//                        }label: {
//                            Label("Add Image", systemImage: "photo")
//                        }
//                    }
//                    .listRowInsets(EdgeInsets(top: 0, leading: 0, bottom: 0, trailing: 0))
//            }else{
                imageToDisplay
                    .resizable()
                    .scaledToFit()
//                    .background(Color.clear)
//                    .foregroundColor(.black)
                    .contextMenu{
                        Button{
                            showImagePicker = true
                        }label: {
                            Label("Change Image", systemImage: "photo")
                        }

                    }
                    .listRowInsets(EdgeInsets(top: 0, leading: 0, bottom: 0, trailing: 0))
//            }

                
            TextField("Name", text: $mangaObject.items[index].name).autocapitalization(.words)
            Stepper(value:$rating,in: 1...10, step: 1){
                HStack{
                    Image(systemName: "star.fill")
                        .foregroundColor(.orange)
                    Text("\(rating)")
                }
            }
            Stepper(value:$chapters, in: 0...30000,step: 1){
                Text("\(chapters) Chapters")
            }.swipeActions {
                Button("Edit") {
                    showEditView.toggle()
                }
                .tint(.orange)
            }
            TextEditor(text: $mangaObject.items[index].review)
        }
        .sheet(isPresented: $showEditView) {
            EditView(val: $chapters, recieved: chapters)
        }
        .sheet(isPresented: $showImagePicker){
            ImagePicker(image: $inputImage)
        }
        .navigationTitle(mangaObject.items[index].name)
        .onAppear {
            inputImage = AddView.loadImageFromDocumentDirectory(fileName: mangaObject.items[index].id.uuidString)
            rating = mangaObject.items[index].rating
            chapters = mangaObject.items[index].chapters
        }
        .onChange(of: chapters, perform: { _ in
            saveChanges()
        })
        .onChange(of: rating, perform: { _ in
            saveChanges()
        })
        .onChange(of: inputImage, perform: { _ in
            let _ =  AddView.saveImageInDocumentDirectory(image: (inputImage ?? UIImage(named: "default"))!, fileName:  mangaObject.items[index].id.uuidString)
        })
        .onDisappear {
            saveChanges()
        }
    }
   
   
    func saveChanges(){
        
        mangaObject.items[index].chapters = chapters
        mangaObject.items[index].rating = rating
       
    }
        
}
//
//struct MovieDetails_Previews: PreviewProvider {
//    static var previews: some View {
//        MovieDetails(movie: movie)
//    }
//}

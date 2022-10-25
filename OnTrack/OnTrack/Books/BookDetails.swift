//
//  MovieDetails.swift
//  OnTrack
//
//  Created by Aarish on 31/05/22.
//

import SwiftUI

struct BookDetails: View {

    @EnvironmentObject var bookObject : Book
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
                    .foregroundColor(.black)
                    .contextMenu{
                        Button{
                            showImagePicker = true
                        }label: {
                            Label("Change Image", systemImage: "photo")
                        }
//                        Button(role: .destructive){
//                            inputImage = UIImage(named: "default")
//                        }label: {
//                            Label("Remove", systemImage: "trash")
//                        }
                    }
                    .listRowInsets(EdgeInsets(top: 0, leading: 0, bottom: 0, trailing: 0))
//            }
            
            TextField("Name", text: $bookObject.items[index].name).autocapitalization(.words)
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
            TextEditor(text: $bookObject.items[index].review)
                .frame(height: 100)
        }
        .sheet(isPresented: $showEditView) {
            EditView(val: $chapters, recieved: chapters)
        }
        .sheet(isPresented: $showImagePicker){
            ImagePicker(image: $inputImage)
        }
        .navigationTitle(bookObject.items[index].name)
        .onAppear {
            inputImage = AddView.loadImageFromDocumentDirectory(fileName: bookObject.items[index].id.uuidString)
            rating = bookObject.items[index].rating
            chapters = bookObject.items[index].chapters
           
        }
        .onChange(of: chapters, perform: { _ in
            saveChanges()
        })
        .onChange(of: rating, perform: { _ in
            saveChanges()
        })
        .onChange(of: inputImage, perform: { _ in
            
            let _ =  AddView.saveImageInDocumentDirectory(image: (inputImage ?? UIImage(named: "default"))!, fileName:  bookObject.items[index].id.uuidString)
        })
        .onDisappear {
            saveChanges()
        }
    }
    func saveChanges(){
       
        bookObject.items[index].chapters = chapters
        bookObject.items[index].rating = rating
       
    }
        
}
//
//struct MovieDetails_Previews: PreviewProvider {
//    static var previews: some View {
//        MovieDetails(movie: movie)
//    }
//}

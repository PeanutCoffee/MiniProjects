//
//  MovieDetails.swift
//  OnTrack
//
//  Created by Aarish on 31/05/22.
//

import SwiftUI

struct EditView: View {
    @Environment(\.dismiss) var dismiss
    @Binding var val: Int
    @State  var recieved: Int
    @ObservedObject var input = NumbersOnly()
    var body: some View {
        NavigationView{
            VStack{
                Form{
                    TextField("Input", text: $input.value)
                        .padding()
                        .keyboardType(.decimalPad)
                }
//
                Spacer()
            }
            .navigationTitle("Update")
            .navigationBarItems(trailing: Button(action: {
                val = Int(input.value) ?? recieved
                generator.notificationOccurred(.success)
                dismiss()
            }) {
                Text("Done").bold()
            })
        }
      
    }
}

struct AnimeDetails: View {

    @EnvironmentObject var animeObject : Anime
    @State private var name = ""
    @State private var rating = 1
    @State  var episodes: Int = 0
    @State private var review = ""
    @State private var showEditView = false
    @State private var inputImage: UIImage?
    @State private var showImagePicker = false
    
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
            
            TextField("Name", text: $animeObject.items[index].name)
            Stepper(value:$rating,in: 1...10, step: 1){
                HStack{
                    Image(systemName: "star.fill")
                        .foregroundColor(.orange)
                    Text("\(rating)")
                }
            }
            Stepper(value:$episodes, in: 0...30000,step: 1){
                Text("\(episodes) Episodes")
            }.swipeActions {
                Button("Edit") {
                    showEditView.toggle()
                }
                .tint(.orange)
            }
            TextEditor(text: $animeObject.items[index].review)
                .frame(height: 100)
        }
        .sheet(isPresented: $showEditView) {
            EditView(val: $episodes, recieved: episodes)
        }
        .sheet(isPresented: $showImagePicker){
            ImagePicker(image: $inputImage)
        }
        .navigationTitle(animeObject.items[index].name)
        .onAppear {
            inputImage = AddView.loadImageFromDocumentDirectory(fileName: animeObject.items[index].id.uuidString)
            rating = animeObject.items[index].rating
            episodes = animeObject.items[index].episode
           
        }
        .onChange(of: episodes, perform: { _ in
            saveChanges()
        })
        .onChange(of: rating, perform: { _ in
            saveChanges()
        })
        .onChange(of: inputImage, perform: { _ in
            
            let _ =  AddView.saveImageInDocumentDirectory(image: (inputImage ?? UIImage(named: "default"))!, fileName:  animeObject.items[index].id.uuidString)
        })
        .onDisappear {
            saveChanges()
        }
    }
    func saveChanges(){
       
        animeObject.items[index].episode = episodes
        animeObject.items[index].rating = rating
       
    }
        
}
//
//struct MovieDetails_Previews: PreviewProvider {
//    static var previews: some View {
//        MovieDetails(movie: movie)
//    }
//}

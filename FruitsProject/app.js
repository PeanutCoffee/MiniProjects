//jshint esversion:6

const mongoose = require('mongoose')
mongoose.connect("mongodb://localhost:2701/fruitsDB", { useNewUrlParser: true });

const fruitSchema = new mongoose.Schema({

    name: {
        type :String,
        required : [true,"Plz check your data"]
    },
    rating:{
        type : Number,
        min:1,
        max:10
    } ,
    review: String
});

const Fruit = mongoose.model("Fruit", fruitSchema);

const fruit = new Fruit({
    name: "Apple",
    rating: 7,
    review: "Pretty solid as a fruit"
});

fruit.save();

const personSchema = new mongoose.Schema({
    name: String,
    age: Number
});

const Person = mongoose.model("Person", personSchema);

const person = new Person({
    name: "John",
    age: 37
});

// person.save();

const kiwi = new Fruit({
    name: "Kiwi",
    score: 10,
    review: "The best fruit!"
});

const orange = new Fruit({
    name: "Orange",
    score: 4,
    review: "Too sour for me"
});

const banana = new Fruit({
    name: "Banana",
    score: 3,
    review: "Weird texture"
});

Fruit.insertMany([kiwi,orange,banana], function(err){
    if(err) {
        console.log(err);
    }
    else {
        console.log("Successfully Saved all the fruits to fruitsDB")
    }
});

Fruit.find(function (err, fruits) {
    if (err) {
        console.log(err);
    }
    else {
        console.log(fruits);
        mongoose.connection.close();
        fruits.forEach(function (fruit) {
            console.log(fruit.name);
        });

    }
});


// Fruit.updateOne({_id : "5bc08vhvjmvjvm"},{name:"Peach"},function(err){
//     if(err){
//         console.log(err);}
//     else
//     {console.log("Succesfully updated");    
//     }
// });

Fruit.deleteOne({name : "Peach"},function(err){
    if(err){
        console.log(err);}
    else
    {console.log("Succesfully deleted");    
    }
});








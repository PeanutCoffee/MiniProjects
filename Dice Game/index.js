var numa = Math.floor(Math.random() * 6) + 1;
var numb = Math.floor(Math.random() * 6) + 1;

var imgSourceA="images/dice"+numa+".png";
var imgSourceB="images/dice"+numb+".png";

var img1=document.querySelector("#img1");
var img2=document.querySelector("#img2");

img1.setAttribute("src", imgSourceA);
img2.setAttribute("src", imgSourceB);


if (numa > numb) {
    document.querySelector("h1").innerHTML = "🚩 Player 1 Wins";
    document.querySelector("h1").classList.add("sizeDecreaser");
}
else if (numb > numa) {
    document.querySelector("h1").innerHTML = "Player 2 Wins 🚩";
    document.querySelector("h1").classList.add("sizeDecreaser");
}
else {
    document.querySelector("h1").innerHTML = "Draw";
    document.querySelector("h1").classList.remove("sizeDecreaser");
}


// function picSelector1(num) {
//     switch (num) {
//         case 1: {
//             document.querySelector("#img1").setAttribute("src", "images/dice1.png");
//             break;
//         }
//         case 2: {
//             document.querySelector("#img1").setAttribute("src", "images/dice2.png");
//             break;
//         }
//         case 3: {
//             document.querySelector("#img1").setAttribute("src", "images/dice3.png");
//             break;
//         }
//         case 4: {
//             document.querySelector("#img1").setAttribute("src", "images/dice4.png");
//             break;
//         }
//         case 5: {
//             document.querySelector("#img1").setAttribute("src", "images/dice5.png");
//             break;
//         }
//         case 6: {
//             document.querySelector("#img1").setAttribute("src", "images/dice6.png");
//             break;
//         }

//     }
// }
// function picSelector2(num) {
//     switch (num) {
//         case 1: {
//             document.querySelector("#img2").setAttribute("src", "images/dice1.png");
//             break;
//         }
//         case 2: {
//             document.querySelector("#img2").setAttribute("src", "images/dice2.png");
//             break;
//         }
//         case 3: {
//             document.querySelector("#img2").setAttribute("src", "images/dice3.png");
//             break;
//         }
//         case 4: {
//             document.querySelector("#img2").setAttribute("src", "images/dice4.png");
//             break;
//         }
//         case 5: {
//             document.querySelector("#img2").setAttribute("src", "images/dice5.png");
//             break;
//         }
//         case 6: {
//             document.querySelector("#img2").setAttribute("src", "images/dice6.png");
//             break;
//         }

//     }
// }
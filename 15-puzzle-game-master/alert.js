function alert_me(){
	alert("hii");
}

function swapTiles(cell1,cell2){
	//console.log("c");
	var c= document.getElementById(cell1).innerHTML;
	document.getElementById(cell1).innerHTML = document.getElementById(cell2).innerHTML;
	document.getElementById(cell2).innerHTML=c;

  var temp = document.getElementById(cell1).className;
  document.getElementById(cell1).className = document.getElementById(cell2).className;
  document.getElementById(cell2).className = temp;

	// var i = document.getElementById(cell1).id;
  // document.getElementById(cell1).id = document.getElementById(cell2).id;
  // document.getElementById(cell2).id = i;

}

function shuffle() {
	document.getElementById("play-button").innerHTML="Reset";

for (var row=1;row<=4;row++) { //For each row of the 4x4 grid
   for (var column=1;column<=4;column++) { //For each column in this row

    var row2=Math.floor(Math.random()*4 + 1); //Pick a random row from 1 to 4
    var column2=Math.floor(Math.random()*4 + 1); //Pick a random column from 1 to 4

    swapTiles("cell"+row+column,"cell"+row2+column2); //Swap the look & feel of both cells
  }
}
}

var move=0;

function clickTile(row,column) {
	move=move+1;
	document.getElementById("span").innerHTML="Move: "+move;
  var cell = document.getElementById("cell"+row+column);
  var tile = cell.className;
  if (tile!="tile16") {
       //Checking if white tile on the right
       if (column==1) {
				 if ( document.getElementById("cell"+row+(column+3)).className=="tile16") {
					 swapTiles("cell"+row+(column+3),"cell"+row+(column+2));
					 swapTiles("cell"+row+(column+2),"cell"+row+(column+1));
					swapTiles("cell"+row+column,"cell"+row+(column+1));
					return;
				}

				 else if ( document.getElementById("cell"+row+(column+2)).className=="tile16") {
					 swapTiles("cell"+row+(column+2),"cell"+row+(column+1));
					 swapTiles("cell"+row+column,"cell"+row+(column+1));
					 return;
				 }

         else if ( document.getElementById("cell"+row+(column+1)).className=="tile16") {
           swapTiles("cell"+row+column,"cell"+row+(column+1));
           return;
         }
       }

			 else if (column==2) {
				if ( document.getElementById("cell"+row+(column+2)).className=="tile16") {
					swapTiles("cell"+row+(column+2),"cell"+row+(column+1));
					swapTiles("cell"+row+column,"cell"+row+(column+1));
					return;
				}

				 else if ( document.getElementById("cell"+row+(column+1)).className=="tile16") {
					 swapTiles("cell"+row+column,"cell"+row+(column+1));
					 return;
				 }
			 }

			else  if (column==3) {
				 if ( document.getElementById("cell"+row+(column+1)).className=="tile16") {
					 swapTiles("cell"+row+column,"cell"+row+(column+1));
					 return;
				 }
			 }

       //Checking if white tile on the left

			 if (column==4) {
				 if ( document.getElementById("cell"+row+(column-3)).className=="tile16") {
					 swapTiles("cell"+row+(column-3),"cell"+row+(column-2));
					 swapTiles("cell"+row+(column-2),"cell"+row+(column-1));
					swapTiles("cell"+row+column,"cell"+row+(column-1));
					return;
				}

				 else if ( document.getElementById("cell"+row+(column-2)).className=="tile16") {
					 swapTiles("cell"+row+(column-2),"cell"+row+(column-1));
					 swapTiles("cell"+row+column,"cell"+row+(column-1));
					 return;
				 }

         else if ( document.getElementById("cell"+row+(column-1)).className=="tile16") {
           swapTiles("cell"+row+column,"cell"+row+(column-1));
           return;
         }
       }

			 else if (column==3) {
				if ( document.getElementById("cell"+row+(column-2)).className=="tile16") {
					swapTiles("cell"+row+(column-2),"cell"+row+(column-1));
					swapTiles("cell"+row+column,"cell"+row+(column-1));
					return;
				}

				 else if ( document.getElementById("cell"+row+(column-1)).className=="tile16") {
					 swapTiles("cell"+row+column,"cell"+row+(column-1));
					 return;
				 }
			 }

			else  if (column==2) {
				 if ( document.getElementById("cell"+row+(column-1)).className=="tile16") {
					 swapTiles("cell"+row+column,"cell"+row+(column-1));
					 return;
				 }
			 }

         //Checking if white tile is above

				 if (row==1) {
					 if ( document.getElementById("cell"+(row+3)+column).className=="tile16") {
						 swapTiles("cell"+(row+3)+column,"cell"+(row+2)+column);
						 swapTiles("cell"+(row+2)+column,"cell"+(row+1)+column);
						swapTiles("cell"+(row+1)+column,"cell"+row+column);
						return;
					}

					 else if ( document.getElementById("cell"+(row+2)+column).className=="tile16") {
						 swapTiles("cell"+(row+2)+column,"cell"+(row+1)+column);
						 swapTiles("cell"+row+column,"cell"+(row+1)+column);
						 return;
					 }

	         else if ( document.getElementById("cell"+(row+1)+column).className=="tile16") {
	           swapTiles("cell"+row+column,"cell"+(row+1)+column);
	           return;
	         }
	       }

				 else if (row==2) {
 					if ( document.getElementById("cell"+(row+2)+column).className=="tile16") {
 						swapTiles("cell"+(row+2)+column,"cell"+(row+1)+column);
 						swapTiles("cell"+row+column,"cell"+(row+1)+column);
 						return;
 					}

 					else if ( document.getElementById("cell"+(row+1)+column).className=="tile16") {
 						swapTiles("cell"+row+column,"cell"+(row+1)+column);
 						return;
 					}
 				}

				else if (row==3) {
					if ( document.getElementById("cell"+(row+1)+column).className=="tile16") {
						swapTiles("cell"+row+column,"cell"+(row+1)+column);
						return;
					}
				}
	       //Checking if white tile on the left
				 if (row==4) {
					if ( document.getElementById("cell"+(row-3)+column).className=="tile16") {
						swapTiles("cell"+(row-3)+column,"cell"+(row-2)+column);
						swapTiles("cell"+(row-2)+column,"cell"+(row-1)+column);
					 swapTiles("cell"+(row-1)+column,"cell"+row+column);
					 return;
				 }

					else if ( document.getElementById("cell"+(row-2)+column).className=="tile16") {
						swapTiles("cell"+(row-2)+column,"cell"+(row-1)+column);
						swapTiles("cell"+row+column,"cell"+(row-1)+column);
						return;
					}

					else if ( document.getElementById("cell"+(row-1)+column).className=="tile16") {
						swapTiles("cell"+row+column,"cell"+(row-1)+column);
						return;
					}
				}

				else if (row==3) {
					 if ( document.getElementById("cell"+(row-2)+column).className=="tile16") {
						 swapTiles("cell"+(row-2)+column,"cell"+(row-1)+column);
						 swapTiles("cell"+row+column,"cell"+(row-1)+column);
						 return;
					 }

					 else if ( document.getElementById("cell"+(row-1)+column).className=="tile16") {
						 swapTiles("cell"+row+column,"cell"+(row-1)+column);
						 return;
					 }
				 }

			 else if (row==2) {
				 if ( document.getElementById("cell"+(row-1)+column).className=="tile16") {
					 swapTiles("cell"+row+column,"cell"+(row-1)+column);
					 return;
				 }
		}
  }
}

let time= 00;

const countdownEl=document.getElementById('time');

setInterval(updateCountdown,1000);

function updateCountdown(){
	const minutes = Math.floor(time/60);
	let seconds=time%60;

	countdownEl.innerHTML="Time = "+minutes+":"+seconds;
	time++;
}

let jokes=[
"Be yourself; everyone else is already taken."  , 
"A room without books is like a body without a soul.",
"To live is the rarest thing in the world. Most people exist, that is all.",
"Be who you are and say what you feel, because those who mind don't matter, and those who matter don't mind.",
"You only live once, but if you do it right, once is enough.",
"Be the change that you wish to see in the world.",
"If you want to know what a man's like, take a good look at how he treats his inferiors, not his equals",
"Insanity is doing the same thing, over and over again, but expecting different results.",
"Fairy tales are more than true: not because they tell us that dragons exist, but because they tell us that dragons can be beaten.",
"Life is what happens to us while we are making other plans.",

];
  
  let jokeText1=document.getElementById("jokeText");
  let clicks=0;
  
  function updateJoke(){
    
    clicks=clicks+1;
    clicks=clicks%(jokes.length);
    //the array just cycles to give new jokes
    jokeText1.textContent=jokes[clicks];
    
  }


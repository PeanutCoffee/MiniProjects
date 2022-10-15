const quoteContainer = document.getElementById('quote-container');
const quoteText = document.getElementById('quote');
const authorText = document.getElementById('author');
const twitterBtn = document.getElementById('twitter');
const newQuoteBtn = document.getElementById('new-quote');
const loader = document.getElementById('loader');

// show loading
loader.hidden = true;

function loading() {
    loader.hidden = false;
    quoteContainer.hidden = true;
}

// hide loading
function complete() {
    quoteContainer.hidden = false;
    loader.hidden = true;
}


// Get Quotes from the API
let apiQuotes = [];

// to pull a single quote everytime
function newQuote() {
    loading();
    // pick a random quote from apiQuotes.
    const quote = apiQuotes[Math.floor(Math.random() * apiQuotes.length)];

    // check if author field is null
    if (!quote.author) {
        authorText.text = "Unknown";
    }else{
        authorText.textContent = quote.author;
    }

    // check the quote to determine styling
    if (quote.text.length > 60) {
        quoteText.classList.add('long-quote');
    } else {
        authorText.classList.remove('long-quote');
    }

    //set quote and hide the loader
    complete();
    
    quoteText.textContent = quote.text;
}

// To fetch the quotes into a local Array.
async function getQuotes() {
    loading();
    const apiUrl = 'https://type.fit/api/quotes';
    try {
        const response = await fetch(apiUrl);
        apiQuotes = await response.json();
        newQuote();
    } catch (error) {
        //Catch Error Occurued
        alert("Some Error... Please Report in Manoj's Github");
    }
}

// Tweet Quote
function tweetQuote() {
    const twitterUrl = `https://twitter.com/intent/tweet?text=${quoteText.textContent} - ${authorText.textContent}`;
    window.open(twitterUrl, '_blank');
}

// Event Listners
newQuoteBtn.addEventListener('click', newQuote);
twitterBtn.addEventListener('click', tweetQuote);

// On Load the function
getQuotes();
// loading();



/***** For LocalQuotes in script.js *****/

/*
function newQuote() {
    const quote = localQuotes[Math.floor(Math.random() * localQuotes.length)];
    if (quote.author == null) {
        authorText.text = "Unknown";
    }

    // check the quote to determine styling
    if (quote.text.length > 60) {
        quoteText.classList.add('long-quote');
    } else {
        authorText.classList.remove('long-quote');
    }

    authorText.textContent = quote.author;
    quoteText.textContent = quote.text;
}

newQuote();
*/

import React, { useState, useEffect } from 'react';
import Quote from './Quote';
import Auther from './Auther';
import './Quote.css';
import { DisappearedLoading } from 'react-loadingg';

function RandomQuote({ random }) {
    const [quote, setQuote] = useState({});
    const [loading, setLoading] = useState(true);

    const getRandomQuote = () => {
        fetch('https://quote-garden.herokuapp.com/api/v3/quotes/random')
            .then((res) => res.json())
            .then((data) => {
                setQuote(data.data[0]);
                setLoading(false);
            });
    };
    useEffect(() => {
        setLoading(true);
        getRandomQuote();
    }, [random]);

    return (
        <>
            {!loading ? (
                <>
                    <Quote content={quote.quoteText} random={random} />
                    <Auther auther={quote.quoteAuthor} genre={quote.quoteGenre} />
                </>
            ) : (
                <DisappearedLoading />
            )}
        </>
    );
}

export default RandomQuote;

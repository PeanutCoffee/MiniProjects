import React, { useState, useEffect } from "react";
import './App.css';
import SearchIcon from './search.svg';
import Logo from './Logo.png';
import MovieCard from "./MovieCard";
import Footer from "./Footer";

const API_URL = "https://www.omdbapi.com/?apikey=YOUR-API-KEY";


const App = () => {
    const [searchTerm, setSearchTerm] = useState("");
    const [movies, setMovies] = useState([]);

    useEffect(() => {
        searchMovies("Avengers");
    },[]);

    const searchMovies = async (title) => {
        const response = await fetch(`${API_URL}&s=${title}`);
        const data = await response.json();
        // console.log(data.Search);
        setMovies(data.Search);
    };

    

    return (
        <div className="app">
            <img 
                src={Logo}
                alt="logo"
                style={{width: '120px'}}
            />
            <h1>Film Fest</h1>

            <div className="search">
                <input
                    value={searchTerm}
                    onChange={(e) => setSearchTerm(e.target.value)}
                    placeholder="Search for Movies"
                    />
                <img 
                    src={SearchIcon}
                    alt="search"
                    onClick={() => searchMovies(searchTerm)}
                />
            </div>

            {movies?.length > 0 ? (
                <div className="container">
                    {movies.map((movie) => (
                        <MovieCard movie={movie} />
                    ))}
                </div>
            ) : (
                <div className="empty">
                    <h2>No Movies Found</h2>
                </div>
            )}
            <Footer />
        </div>
        
    );
};

export default App;

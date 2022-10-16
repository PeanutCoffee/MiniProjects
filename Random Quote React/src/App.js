import React, { useState } from 'react';
import Header from './components/Header';
import Main from './components/Main';
import Footer from './components/Footer';
import { HashRouter as Router } from 'react-router-dom';

function App() {
    const [random, setRandom] = useState(Date.now());
    return (
        <Router>
            <Header setRandom={setRandom} />
            <Main random={random} />
            <Footer />
        </Router>
    );
}

export default App;


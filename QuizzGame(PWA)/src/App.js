// import logo from './logo.svg';
// import './App.css';
import {
  HashRouter as Router,
  Routes,
  Route
  
} from "react-router-dom";
import About from "./components/About";
import Contact from "./components/Contact";
import Index from "./components/Index";
import Navbar from "./components/Navbar";
import Quizz from "./components/Quizz";
import Quizzdashboard from "./components/Quizzdashboard";
function App() {
  return (
    <>
    <Router>
      <Navbar/>
     
      <Routes>
        <Route exact path="/" element={<Index/>}/>
        <Route exact path="/about" element={<About/>}/>
        <Route exact path="/contact" element={<Contact/>}/>
        <Route exact path="/quizz" element={<Quizz/>}/>
        <Route exact path="/quizzdashboard" element={<Quizzdashboard/>}/>
      </Routes>
    </Router>
    </>
  );
}

export default App;

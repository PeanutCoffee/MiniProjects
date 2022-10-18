import React from 'react'
import {Link} from 'react-router-dom'
import { HashLink as Link1 } from 'react-router-hash-link';
function Navbar() {
    return (
        <div>
            <nav className="navbar navbar-expand-lg navbar-dark bg-dark">
  <div className="container-fluid">
    <Link className="navbar-brand nav" to="/">Quizzer</Link>
    <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span className="navbar-toggler-icon"></span>
    </button>
    <div className="collapse navbar-collapse" id="navbarSupportedContent">
      <ul className="navbar-nav me-auto mb-2 mb-lg-0">
        <li className="nav-item">
          <Link className="nav-link active" aria-current="page" to="/">Home</Link>
        </li>
        <li className="nav-item">
          <Link1 className="nav-link active" to="/#about">About</Link1>
        </li>
        <li className="nav-item">
          <Link className="nav-link active" aria-current="page" to="/quizz">Quiz Menu</Link>
        </li>
      
       
      </ul>
     
    </div>
  </div>
</nav>
        </div>
    )
}

export default Navbar

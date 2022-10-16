import React from "react";
import Sync from "@material-ui/icons/Sync";
import "./Header.css";
import { Link } from "react-router-dom";

function Header({ setRandom }) {
    return (
        <header>
            <Link
                to="/"
                className="random-btn"
                replace
                onClick={() => setRandom(Date.now())}
            >
                Random
                <Sync />
            </Link>
        </header>
    );
}

export default Header;

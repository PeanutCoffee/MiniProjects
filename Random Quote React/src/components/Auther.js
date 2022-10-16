import React from "react";
import { Link } from "react-router-dom";
import "./Auther.css";
import { ArrowRightAlt } from "@material-ui/icons";

function Auther({ auther, genre }) {
    return (
        <div className="auther container">
            <Link to={"/auther?q=" + auther}>
                <span className="auther-name">{auther}</span>
                <br />
                <span className="genre">{genre}</span>
                <ArrowRightAlt />
            </Link>
        </div>
    );
}

export default Auther;

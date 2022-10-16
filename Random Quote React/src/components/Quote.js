import React from "react";
import "./Quote.css";

function Quote({ content }) {
    return (
        <div className="quote container">
            <div className="line"></div>
            <div className="content">{`“${content}”`}</div>
        </div>
    );
}

export default Quote;

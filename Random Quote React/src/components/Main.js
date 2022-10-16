import React from "react";
import "./Main.css";
import { Route, Switch } from "react-router-dom";
import RandomQuote from "./RandomQuote";
import ListQuotes from "./ListQuotes";

function Main({ random }) {
    return (
        <main>
            <Switch>
                <Route path="/" exact random={random}>
                    <RandomQuote random={random} />
                </Route>
                <Route path="/auther" component={ListQuotes} />
            </Switch>
        </main>
    );
}
export default Main;

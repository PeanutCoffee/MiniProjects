import React, { useState, useEffect, useCallback } from 'react';
import QueryString from 'query-string';
import { DisappearedLoading } from 'react-loadingg';
import Quote from './Quote';
import './ListQuotes.css';

// export default class ListQuotes extends React.Component {
//     constructor(props) {
//         super(props);
//         this.state = { quotes: [], loading: true };
//         this.auther = QueryString.parse(this.props.location.search).q;
//     }
//     getQuotes = () => {
//         fetch(
//             `https://quote-garden.herokuapp.com/api/v2/authors/${this.auther.replace(
//                 " ",
//                 "%20"
//             )}?page=1&limit=10`
//         )
//             .then((res) => res.json())
//             .then((data) => {
//                 this.changeState("quotes", data.quotes);
//                 this.changeState("loading", false);
//             });
//     };

//     changeState = (x, y) => {
//         let state = this.state;
//         state[x] = y;
//         this.setState({ state });
//     };
//     componentDidMount() {
//         this.changeState("loading", true);
//         this.getQuotes();
//     }
//     render() {
//         return (
//             <>
//                 {this.state.loading ? (
//                     <DisappearedLoading />
//                 ) : (
//                     <>
//                         <div className="auther_name container">
//                             {this.auther}
//                         </div>
//                         {this.state.quotes.map((x, i) => (
//                             <Quote key={i} content={x.quoteText} />
//                         ))}
//                     </>
//                 )}
//             </>
//         );
//     }
// }

function ListQuotes({ location }) {
    const [quotes, setquotes] = useState([]);
    const [loading, setLoading] = useState(true);
    const auther = QueryString.parse(location.search).q;
    const getQuotes = useCallback(() => {
        fetch(`https://quote-garden.herokuapp.com/api/v3/authors/${auther.replace(' ', '%20')}?page=1&limit=10`)
            .then((res) => res.json())
            .then((data) => {
                setquotes(data.quotes);
                setLoading(false);
            });
    }, [auther]);

    useEffect(() => {
        setLoading(true);
        getQuotes();
    }, [getQuotes]);

    return (
        <>
            {loading ? (
                <DisappearedLoading />
            ) : (
                <>
                    <div className="auther_name container">{auther}</div>
                    {quotes.map((x, i) => (
                        <Quote key={i} content={x.quoteText} />
                    ))}
                </>
            )}
        </>
    );
}

export default ListQuotes;

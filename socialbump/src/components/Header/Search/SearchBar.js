import React, { useState } from 'react';
import { db } from '../../../firebase/firebase';
import SearchIcon from '@mui/icons-material/Search';
import InputBase from '@mui/material/InputBase';
import { styled, alpha } from '@mui/material/styles';
import { useNavigate } from 'react-router-dom';

const SearchBar = () => {
    const Navigate = useNavigate();
    const Search = styled("div")(({ theme }) => ({
        position: "relative",
        borderRadius: theme.shape.borderRadius,
        backgroundColor: alpha(theme.palette.common.white, 0.15),
        "&:hover": {
            backgroundColor: alpha(theme.palette.common.white, 0.25),
        },
        marginRight: theme.spacing(2),
        marginLeft: 0,
        width: "100%",
        [theme.breakpoints.up("sm")]: {
            marginLeft: theme.spacing(3),
            width: "auto",
        },
    }));
    const SearchIconWrapper = styled("div")(({ theme }) => ({
        padding: theme.spacing(0, 2),
        height: "100%",
        position: "absolute",
        pointerEvents: "none",
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
    }));
    const StyledInputBase = styled(InputBase)(({ theme }) => ({
        color: "inherit",
        "& .MuiInputBase-input": {
            padding: theme.spacing(1, 1, 1, 0),
            // vertical padding + font size from searchIcon
            paddingLeft: `calc(1em + ${theme.spacing(4)})`,
            transition: theme.transitions.create("width"),
            width: "100%",
            [theme.breakpoints.up("md")]: {
                width: "20ch",
            },
        },
    }));

    const [usersData, setusersData] = React.useState([]);
    const [dataSet, setdataSet] = React.useState(false);
    const [suggestionData, setsuggestionData] = useState([]);
    const [inputValue, setinputValue] = useState("");
    const [dataStore, setDataStore] = useState('')
    db.collection("Profile").onSnapshot((snap) => {
        const dataArr = [];
        snap.docChanges().forEach((change) => {
            if (change.type === "added") {
                dataArr.push(change.doc.data());
            }
        });
        if (!dataSet) {
            setusersData(dataArr);
            // console.log(dataArr);
            setdataSet(true);
        }
    });
    const filterSuggestion = (e) => {
        const searchWord = e.target.value;
        setinputValue(searchWord);
        // const myArr = usersData.map((obj) => obj.Name);
        const filteredData = usersData.filter((obj) => {
            const lowerCaseName = obj.Name.toLowerCase();
            return lowerCaseName.indexOf(searchWord.toLowerCase()) !== -1;
        });
        setsuggestionData(filteredData);
        // console.log(suggestionData);
    };
    const searchData = (e) => {
        const foundedUser = suggestionData[0];
        setDataStore(foundedUser);
        Navigate(`/profile/${foundedUser.username}`);
        // window.location.reload();
        // console.log(dataStore);
    }
    return (
        <div>
            <Search>
                <SearchIconWrapper>
                    <SearchIcon />
                </SearchIconWrapper>
                <StyledInputBase
                key={0}
                    placeholder="Search…"
                    inputProps={{
                        "aria-label": "search",
                        value: inputValue,
                        onChange: filterSuggestion,
                        autoFocus: "ture",
                    }}
                />
            </Search>
            <div className="suggestions">
                {suggestionData
                    ?
                    suggestionData.map((obj) => {
                        return <div
                            className="suggestion"
                            onClick={searchData}
                            value={dataStore}
                        >
                            {obj.Name}
                        </div>;
                    })
                    : ""}
            </div>
        </div>
    )
}

export default SearchBar;

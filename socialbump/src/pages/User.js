import React from 'react';
import NavBar from '../components/Header/NavBar';
import UserComp from '../components/Header/Search/UserComp';
import './style.css';

const User = () => {

    return (
        <>
            <NavBar />
            <UserComp />
        </>
    )
}

export default User;

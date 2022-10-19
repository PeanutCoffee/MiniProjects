import React from 'react'
import NavBar from '../components/Header/NavBar'
import Profile from '../components/Header/Profile/Profile'
import UpdateProfile from '../components/Header/Profile/UpdateProfile'
import './style.css';

const Setting = () => {
    return (
        <div className='main2'>
            <NavBar />
            <Profile />
            {/* <UpdateProfile /> */}
        </div>
    )
}

export default Setting

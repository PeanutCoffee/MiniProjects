import React from 'react'
import NavBar from '../components/Header/NavBar'
import CreatePost from '../components/Feed/CreatePost'
import Feed from '../components/Feed/Feed'
import './style.css';

const Dashboard = () => {
    return (
        <div className='main'>
            <NavBar />
            <CreatePost />
            <Feed />
        </div>
    )
}

export default Dashboard;

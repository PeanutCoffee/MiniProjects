import React, { useState, useEffect } from 'react'
import Post from './Post'
import { db } from '../../firebase/firebase'
import { useAuth } from '../../context/AuthContext';

const Feed = () => {
    const [posts, setPosts] = useState([]);

    useEffect(() => {
        db.collection("posts").orderBy("timestamp", "desc").onSnapshot(snapshot => {
            setPosts(snapshot.docs.map(doc => ({
                id: doc.id,
                data: doc.data(),
            })))
        })
    }, [])
    return (
        <>
            {
                posts.map(post => {
                    return <Post
                        key={post.id}
                        name={post.data.name.Name}
                        timestamp={post.data.timestamp}
                        message={post.data.message}
                        image={post.data.image}
                        profilePic={post.data.profilePic.Photo.url}
                    />
                })
            }
        </>
    )
}

export default Feed;

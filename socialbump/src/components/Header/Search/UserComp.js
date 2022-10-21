import { CssBaseline, Typography, TextField, Card, IconButton, Stack, Avatar, Box, Button, Modal } from '@mui/material';
import AccountCircleOutlinedIcon from '@mui/icons-material/AccountCircleOutlined'; import InfoOutlinedIcon from '@mui/icons-material/InfoOutlined'; import CheckCircleIcon from '@mui/icons-material/CheckCircle'; import UploadIcon from '@mui/icons-material/Upload'; import DoubleArrowIcon from '@mui/icons-material/DoubleArrow';
import React, { useState, useEffect } from 'react'
import { useParams } from 'react-router-dom';
import { db } from '../../../firebase/firebase';
import '../../style.css'
import { useAuth } from '../../../context/AuthContext';
import Post from '../../Feed/Post';
import Feed from '../../Feed/Feed';

const UserComp = () => {
    const { username } = useParams()
    // console.log(username)

    const [profile, setProfile] = useState({
        Name: "",
        Bio: "",
        Photo: "",
    });

    const { Name, Bio, Photo } = profile;
    db.collection('Profile').where('username', '==', username).onSnapshot((data) => {
        data.forEach((doc) => {
            const { Bio, Name, Photo } = doc.data();
            setProfile(prev => ({ ...prev, Bio, Name, Photo }))
        })
    });

    const [posts, setPosts] = useState([]);

    db.collection('posts').where('username', '==', username).onSnapshot(snapshot => {
        setPosts(snapshot.docs.map(doc => ({
            id: doc.id,
            data: doc.data(),
        })))
    })
return (
    <div>
        <CssBaseline>
            <div>
                <Card sx={{ height: 'auto', width: '60%', m: 'auto' }} className='accountMain'>
                    <div className='accountDiv'>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>

                            <IconButton color="primary"  >
                                <Stack>
                                    <Avatar
                                        src={Photo.url}
                                        sx={{ width: 150, height: 150 }}
                                    />
                                </Stack>
                            </IconButton>

                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center', m: 2, p: 1 }}>
                            <AccountCircleOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="Name" variant="standard" value={Name} sx={{ width: "50%" }} />
                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center', m: 2, p: 1 }}>
                            <InfoOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="About" variant="standard" value={Bio} sx={{ width: "50%" }} />
                        </Box>
                    </div>
                </Card>
            </div>

            {/* <Feed className='accountMain ' /> */}
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
        </CssBaseline>
    </div>
)
}

export default UserComp

import React, { useState, useEffect } from "react";
import { CssBaseline, Typography, TextField, Card, IconButton, Stack, Avatar, Box } from '@mui/material';
import AccountCircleOutlinedIcon from '@mui/icons-material/AccountCircleOutlined'; import InfoOutlinedIcon from '@mui/icons-material/InfoOutlined'; import CheckCircleIcon from '@mui/icons-material/CheckCircle'; import UploadIcon from '@mui/icons-material/Upload'; import DoubleArrowIcon from '@mui/icons-material/DoubleArrow';
import { styled } from '@mui/material/styles';
import { db, storage, auth } from '../../../firebase/firebase';
import { useAuth } from "../../../context/AuthContext";
import '../../style.css'
import UserName from "./UserName";

const UpdateProfile = () => {
    const { currentUser } = useAuth();

    const [usernames, setUsernames] = useState({ username: "" })
    useEffect(() => {
        auth.onAuthStateChanged(() => {
            const userEmail = auth.currentUser.email;
            setUsernames(() => ({ username: UserName(userEmail) }))
        })
    }, []);
    const { username } = usernames;

    const Input = styled('input')({
        display: 'none',
    });
    const [image, setImage] = useState('');
    const [url, setUrl] = useState("");
    const handleImg = (e) => {
        if (e.target.files[0]) {
            setImage(e.target.files[0]);
        }
    }
    const uploadProfile = () => {
        const uploadTask = storage.ref(`Profile Photo/${image.name}`).put(image);
        uploadTask.on("state_changed",
            snapshot => {
                // const progress = Math.round(
                //     (snapshot.bytesTransferred / snapshot.totalBytes) * 100
                // );
                // setProgress(progress);
            },
            error => { console.log(error); },
            () => {
                storage
                    .ref("Profile Photo")
                    .child(image.name)
                    .getDownloadURL()
                    .then(url => {
                        setUrl(url);
                    })
            });
    };
    const [name, setName] = useState('');
    const [bio, setBio] = useState('');

    const addProfile = () => {
        db.collection('Profile').doc(currentUser.uid).set({
            Photo: { url },
            Name: name,
            Bio: bio,
            uid: currentUser.uid,
            username
        })
    }
    return (
        <CssBaseline >
            <div  >
                <br />
                <Card sx={{ height: 'auto', width: '60%', m: 'auto' }} className='accountMain'>
                    <Typography variant='h4' component="div" gutterBottom >Update Profile <DoubleArrowIcon /></Typography>

                    <div className='accountDiv'>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
                            <label htmlFor="icon-button-file">
                                <Input accept="image/*" id="icon-button-file" type="file" onChange={handleImg} />
                                <IconButton color="primary" aria-label="upload picture" component="span">
                                    <Stack>
                                        <Avatar
                                            src={url}
                                            
                                            adefaultValue={url}
                                            sx={{ width: 60, height: 60 }}
                                        />
                                    </Stack>
                                </IconButton>
                            </label>

                            <IconButton sx={{ mt: 7, ml: -3 }} onClick={uploadProfile} className='iconBtn2'><UploadIcon /></IconButton>
                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
                            <AccountCircleOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="Name" variant="standard" defaultValue="Hello World" value={name} onChange={(e) => setName(e.target.value)} />
                            <IconButton sx={{ m: 3 }} onClick={() => { addProfile() }} className='iconBtn2'><CheckCircleIcon /></IconButton>
                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center' }}>
                            <InfoOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="About" variant="standard" value={bio} onChange={(e) => setBio(e.target.value)} />
                            <IconButton sx={{ m: 3 }} onClick={() => { addProfile() }} className='iconBtn2' ><CheckCircleIcon /></IconButton>
                        </Box>
                    </div>
                </Card>
            </div>
        </CssBaseline>
    )
}

export default UpdateProfile;

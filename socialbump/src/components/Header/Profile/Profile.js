import React, { useEffect, useState } from "react";
import { CssBaseline, Typography, TextField, Card, IconButton, Stack, Avatar, Box, Button, Modal } from '@mui/material';
import AccountCircleOutlinedIcon from '@mui/icons-material/AccountCircleOutlined'; import InfoOutlinedIcon from '@mui/icons-material/InfoOutlined'; import CheckCircleIcon from '@mui/icons-material/CheckCircle'; import UploadIcon from '@mui/icons-material/Upload'; import DoubleArrowIcon from '@mui/icons-material/DoubleArrow';
import '../../style.css'
import { auth, db } from "../../../firebase/firebase";
import UserName from "./UserName";
import UpdateProfile from "./UpdateProfile";
import { useAuth } from "../../../context/AuthContext";

const Profile = () => {
    const { currentUser } = useAuth();

    const [open, setOpen] = useState(false);

    const handleClose = () => {
        setOpen(false)
    }
    const handleOpen = () => {
        setOpen(true)
    }
    const [usernames, setUsernames] = useState({ username: "" })
    useEffect(() => {
        auth.onAuthStateChanged(() => {
            const userEmail = auth.currentUser.email;
            setUsernames(() => ({ username: UserName(userEmail) }))
        })
    }, []);
    const { username } = usernames;

    const [profile, setProfile] = useState({
        Name: "",
        Bio: "",
        Photo: "",
    });

    const { Name, Bio, Photo } = profile;
    useEffect(() => {
        db.collection("Profile").doc(currentUser.uid).get().then(doc => {
            if (doc.exists) {
                const { Bio, Name,Photo } = doc.data();
                setProfile(prev => ({ ...prev, Bio, Name, Photo }))
            }
            else {
                console.log("No Doc available");
            }
        })
    }, [])

    return (
        <CssBaseline >
            <div  >
                <br />
                <Card sx={{ height: 'auto', width: '60%', m: 'auto' }} className='accountMain'>
                    <Typography variant='h4' component="div" gutterBottom >Profile <DoubleArrowIcon /></Typography>

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
                            <InfoOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="User Name" variant="standard" value={username} sx={{ width: "50%" }} />
                            {/* <IconButton sx={{ m: 3 }} className='iconBtn2'><CheckCircleIcon /></IconButton> */}
                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center', m: 2, p: 1 }}>
                            <AccountCircleOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="Name" variant="standard" value={Name} sx={{ width: "50%" }} />
                            {/* <IconButton sx={{ m: 3 }}  className='iconBtn2'><CheckCircleIcon /></IconButton> */}
                        </Box>
                        <Box sx={{ display: 'flex', alignItems: 'center', justifyContent: 'center', m: 2, p: 1 }}>
                            <InfoOutlinedIcon sx={{ color: 'action.active', mr: 2, my: 0.5 }} className='iconBtn1' />
                            <TextField id="standard-basic" label="About" variant="standard" value={Bio} sx={{ width: "50%" }} />
                            {/* <IconButton sx={{ m: 3 }} className='iconBtn2'><CheckCircleIcon /></IconButton> */}
                        </Box>
                        <Button variant="contained" className="submit" onClick={handleOpen}>Edit</Button>
                    </div>
                </Card>
            </div>
            <Modal open={open} onClose={handleClose}>
                <UpdateProfile />
            </Modal>
        </CssBaseline>
    )
};
export default Profile;

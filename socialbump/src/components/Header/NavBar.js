import React, { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import { AppBar, Box, Toolbar, IconButton, Typography, Menu, Container, Avatar, Tooltip, MenuItem, CssBaseline, Alert } from '@mui/material';
import '../style.css';
import { useAuth } from '../../context/AuthContext';
import SearchBar from './Search/SearchBar';
import { db } from '../../firebase/firebase';

const NavBar = () => {
    const [error, setError] = useState('');
    const { logout } = useAuth();
    const navigate = useNavigate();
    const { currentUser } = useAuth();

    const logoutHandler = async () => {
        setError('')

        try {
            await logout()
            navigate('/login')
        }
        catch {
            setError('Failed to log out')
        }
    }
    const logo = () => {
        navigate("/");
    }
    const settings = [
        {
            name: 'Home', func: () => {
                navigate("/");
            }
        },
        {
            name: 'Settings', func: () => {
                navigate("/setting");
            }
        },

        // { name: 'Account' },

        {
            name: 'Logout', func: () => {
                logoutHandler()
            }
        }
    ];
    const [profile, setProfile] = useState({
        Name: "",
        Photo: "",
    });

    const { Name, Photo } = profile;
    useEffect(() => {
        db.collection("Profile").doc(currentUser.uid).get().then(doc => {
            if (doc.exists) {
                const { Name, Photo } = doc.data();
                setProfile(prev => ({ ...prev, Name, Photo }))
            }
            else {
                console.log("No Doc available");
            }
        })
    }, [])
    const [anchorElUser, setAnchorElUser] = useState(null);

    const handleOpenUserMenu = (event) => {
        setAnchorElUser(event.currentTarget);
    };
    const handleCloseNavMenu = () => {
        // setAnchorElNav(null);
    };
    const handleCloseUserMenu = () => {
        setAnchorElUser(null);
    };
    return (
        <CssBaseline>
            <AppBar root position="static" className='navBar'>
                <Container maxWidth="xl">
                    <Toolbar disableGutters>
                        <Container sx={{ flexGrow: 1, mr: 2, display: { xs: 'flex', md: 'flex' } }} >
                            <img src="SocialBump.png" alt='SocialBump' onClick={logo} style={{
                                "imageRendering": "-webkit-optimize-contrast", "width": "35vh"
                            }} />
                        </Container>
                        <div>
                            <SearchBar />
                        </div>
                        <Box sx={{ flexGrow: 0 }}>
                            <Tooltip title="Open settings">
                                <IconButton onClick={handleOpenUserMenu} sx={{ p: 0 }}>
                                    <Avatar
                                        src={Photo.url}
                                    />
                                </IconButton>
                            </Tooltip>
                            <Menu
                                sx={{ mt: '45px' }}
                                id="menu-appbar"
                                anchorEl={anchorElUser}
                                anchorOrigin={{
                                    vertical: 'top',
                                    horizontal: 'right',
                                }}
                                keepMounted
                                transformOrigin={{
                                    vertical: 'top',
                                    horizontal: 'right'
                                }}
                                open={Boolean(anchorElUser)}
                                onClose={handleCloseUserMenu}
                            >
                                {settings.map((setting) => (
                                    <MenuItem key={setting.name} onClick={function () { handleCloseNavMenu(); setting.func(); }}>
                                        <Typography textAlign="center">{setting.name}</Typography>
                                    </MenuItem>
                                ))}
                            </Menu>
                            {error && <Alert variant="danger">{error}</Alert>}
                        </Box>
                    </Toolbar>
                </Container>
            </AppBar>
        </CssBaseline>
    )
}

export default NavBar

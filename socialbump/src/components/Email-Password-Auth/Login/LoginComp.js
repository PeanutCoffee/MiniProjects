import React, { useRef, useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { LockRounded } from '@mui/icons-material';
import { Container, Card, CardContent, CssBaseline, Avatar, Typography, TextField, Button, Grid, Alert } from '@mui/material';
import { useAuth } from "../../../context/AuthContext";
import '../style.css';

const LoginComp = () => {
    const emailRef = useRef();
    const passwordRef = useRef();
    const { login } = useAuth();
    const [error, setError] = useState('');
    const [loading, setLoading] = useState('');
    const navigate = useNavigate();

    const submitHandler = async (e) => {
        e.preventDefault()

        try {
            setError("")
            setLoading(true)
            await login(emailRef.current.value, passwordRef.current.value)
            navigate("/")
        }

        catch {
            setError("Failed to Log In")
        }

        setLoading(false)
    }
    return (
        <Container component="main" maxWidth="xs">
            <Card className='card'>
                <div >
                    <CardContent className='paper'>
                        <CssBaseline />
                        <Avatar className='avatar'>
                            <LockRounded />
                        </Avatar>
                        <Typography component="h1" variant="h5">
                            Log In
                        </Typography>
                        {error && <Alert severity="error" variant='outlined'>{error}</Alert>}
                        <form onSubmit={submitHandler}>
                            {/* <TextField label="Username" id='username' type="text" helperText="Please enter your name" inputRef={usernameRef} fullWidth margin="normal" variant="outlined" required /> */}
                            <TextField label="Email" id='email' type="email" inputRef={emailRef} fullWidth margin="normal" variant="outlined" required />
                            <TextField label="Password" id='password' type="password" inputRef={passwordRef} fullWidth margin="normal" variant="outlined" required />
                            <Button type="submit" disabled={loading} fullWidth variant="contained" className='submit' >Log In</Button><br />
                        </form>
                        <Grid item>
                            <Link to='/forgotPassword' className='pointer-sm'>Forgot Password?</Link>
                        </Grid>
                    </CardContent>
                    <Grid container>
                        <Grid item>
                            Don't have an account?<Link to='/signup' className='pointer'> Sign Up</Link>
                        </Grid>
                    </Grid>
                </div>
            </Card>
        </Container >
    )
}

export default LoginComp;

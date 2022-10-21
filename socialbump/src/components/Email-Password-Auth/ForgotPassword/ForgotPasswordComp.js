import React, { useRef, useState } from 'react';
import { Link } from 'react-router-dom';
import { LockRounded } from '@mui/icons-material';
import { Container, Card, CardContent, CssBaseline, Avatar, Typography, TextField, Button, Grid, Alert } from '@mui/material';
import { useAuth } from "../../../context/AuthContext";
import '../style.css';

const ForgotPasswordComp = () => {
    const emailRef = useRef();
    const { resetPassword } = useAuth();
    const [error, setError] = useState('');
    const [message, setMessage] = useState('');
    const [loading, setLoading] = useState('');

    const submitHandler = async (e) => {
        e.preventDefault()

        try {
            setMessage("")
            setError("")
            setLoading(true)
            await resetPassword(emailRef.current.value)
            setMessage('Check your inbox for further instructions')
        }

        catch {
            setError("Failed to reset password")
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
                            Password Reset
                        </Typography>
                        {error && <Alert severity="success" variant='outlined'>{error}</Alert>}
                        {message && <Alert severity="success" variant='outlined'>{message}</Alert>}
                        <form onSubmit={submitHandler}>
                            {/* <TextField label="Username" id='username' type="text" helperText="Please enter your name" inputRef={usernameRef} fullWidth margin="normal" variant="outlined" required /> */}
                            <TextField label="Email" id='email' type="email" inputRef={emailRef} fullWidth margin="normal" variant="outlined" required />
                            <Button type="submit" disabled={loading} fullWidth variant="contained" className='submit' >Reset Password</Button><br />
                        </form>
                        <Grid item>
                            <Link to='/login' className='pointer'>Login</Link>
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

export default ForgotPasswordComp;

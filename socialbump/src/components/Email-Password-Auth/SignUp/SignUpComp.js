import React, { useRef, useState } from 'react'
import { Link, useNavigate } from 'react-router-dom';
import { LockRounded } from '@mui/icons-material'
import { Container, Card, CardContent, CssBaseline, Avatar, Typography, TextField, Button, Grid, Alert } from '@mui/material'
import { useAuth } from "../../../context/AuthContext"
import '../style.css';

const SignUpComp = () => {
    const emailRef = useRef();
    const passwordRef = useRef();
    const confirmPasswordRef = useRef();
    const { signup} = useAuth();
    const [error, setError] = useState('');
    const [loading, setLoading] = useState(false);
    const navigate = useNavigate();

    const submitHandler = async (e) => {
        e.preventDefault()

        if (passwordRef.current.value !== confirmPasswordRef.current.value) {
            return setError('Password do not match')
        }

        try {
            setError("")
            setLoading(true)
            await signup(emailRef.current.value, passwordRef.current.value)
            navigate("/setting")

        }

        catch {
            setError("Failed to create an account")
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
                            Sign Up
                        </Typography>
                        {error && <Alert severity="error" variant='outlined'>{error}</Alert>}
                        <form onSubmit={submitHandler}>
                            <TextField label="Email" id='email' type="email" inputRef={emailRef} fullWidth margin="normal" variant="outlined" required />
                            <TextField label="Password" id='password' type="password" inputRef={passwordRef} fullWidth margin="normal" variant="outlined" required />
                            <TextField label="Confirm Password" id='confirmPassword' type="password" helperText="Please enter your name" inputRef={confirmPasswordRef} fullWidth margin="normal" variant="outlined" required />
                            <Button type="submit" disabled={loading} fullWidth className='submit' variant="contained" >Sign Up</Button><br />
                        </form>
                    </CardContent>
                    <Grid container>
                        <Grid item>
                            Already have an account?<Link to='/login' variant="body2" className='pointer'> Log In
                            </Link>
                        </Grid>
                    </Grid>
                </div>
            </Card>
        </Container >
    )
}

export default SignUpComp;

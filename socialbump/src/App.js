import React from 'react'
import { AuthProvider } from './context/AuthContext'
import Routes from './routes/Routes'

const App = () => {
  return (
    <AuthProvider>
      <Routes />
    </AuthProvider>
  )
}

export default App;

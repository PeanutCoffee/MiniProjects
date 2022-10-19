import { BrowserRouter as Router, Route, Routes as AppRoutes } from "react-router-dom";
import Dashboard from "../pages/Dashboard";
import SignUp from '../pages/SignUp';
import Login from '../pages/Login';
import User from '../pages/User';
import Setting from "../pages/Setting";
// import PrivateRoute from "./PrivateRoute"
import ForgotPassword from "../pages/ForgotPassword";
import { useAuth } from '../context/AuthContext';

const Routes = () => {
    const { currentUser } = useAuth();

    return (
        <>
            <Router>
                <AppRoutes>
                    {/* </PrivateRoute>  */}
                    {/* <Route path="/" element={
                        <PrivateRoute>
                            <Dashboard />
                        </PrivateRoute>
                    } /> */}


                    {/* </Route> */}
                    { currentUser &&
                        <>
                            <Route path="*" element={<Dashboard />} />
                            <Route path="/" element={<Dashboard />} />
                            <Route path="/setting" element={<Setting />} />
                            <Route path="/profile/:username" element={<User />} />
                        </>
                    }
                    { !currentUser &&
                        <>
                            <Route path="*" element={<SignUp />} />
                            <Route path="/" element={<SignUp />} />
                            <Route path="/login" element={<Login />} />
                            <Route path="/forgotPassword" element={<ForgotPassword />} />
                        </>
                    }
                </AppRoutes>
            </Router>
        </>
    )
}

export default Routes

import React, { useState, useEffect } from 'react';
import { useAuth } from '../../context/AuthContext';
import { db } from '../../firebase/firebase';

const DashboardComp = () => {
    const { currentUser } = useAuth();

    return (
        <div>
            <strong>Email:</strong> {currentUser.email}
            <strong>Uid:</strong> {currentUser.uid}

        </div>
    )
}

export default DashboardComp;

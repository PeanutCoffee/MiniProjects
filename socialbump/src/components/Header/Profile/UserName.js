const UserName = (email) => {
    let username = "";
    const indexofAt = email.indexOf("@");
    username = email.substring(0, indexofAt);

    return username;
}

export default UserName;

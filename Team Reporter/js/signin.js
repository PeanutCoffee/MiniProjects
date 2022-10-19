let loginEmail1 = document.getElementById("loginEmail1");
let loginPassword = document.getElementById("loginPassword");
let login = document.getElementById("login");
let mainDiv = document.getElementById("mainDiv");
let LoginHelp = document.getElementById("LoginHelp");
let userObjLogin;
var userLogin = false;


// getting data from local storage
let userObj = localStorage.getItem("userObjLocal");
userObj = JSON.parse(userObj)
console.log(userObj)


login.addEventListener('click', () => {

    for (let i = 0; i < userObj.length; i++) {
        if (userObj[i].email === loginEmail1.value && userObj[i].password === loginPassword.value) {
            userLogin = true;
            userObjLogin = userObj[i]
        }

    }
    userObjLogin = JSON.stringify(userObjLogin)
    localStorage.setItem("userObjLoginLocal", userObjLogin)
    console.log(userObjLogin, userLogin)
    if (userLogin) {
        window.location = "login.html"

    }

})
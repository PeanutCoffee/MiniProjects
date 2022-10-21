// getting elements from dom 
let InputUser = document.getElementById("InputUser");
let InputEmail = document.getElementById("InputEmail");
let InputPassword1 = document.getElementById("InputPassword1");
let InputPassword2 = document.getElementById("InputPassword2");
let submit = document.getElementById("submit")
let alertDiv = document.getElementById("alertDiv");
let subForm = document.getElementById("subForm");
let LoginHelp = document.getElementById("LoginHelp");




// created class for user's input
class UserObj {
    constructor(name, email, password, userKey, partTeam, createdTeam) {
        this.name = name;
        this.email = email;
        this.password = password;
        this.userKey = userKey;
        this.partTeam = partTeam;
        this.createdTeam = createdTeam;
    }
}





// created class for validating and clearing methods
class AddUserData {
    // validating user's input
    validate() {
        let userCond = true;

        if (InputUser.value === "") {
            InputUser.style.borderColor = "red";
            userCond = false;
        }
        else {
            InputUser.style.borderColor = "#ccc";
        }

        let usersObj = localStorage.getItem("userObjLocal");
        usersObj = JSON.parse(usersObj);

        if (usersObj) {
            for (let i = 0; i < usersObj.length; i++) {
                if (usersObj[i].name === InputUser.value.toUpperCase()) {
                    InputUser.style.borderColor = "red";
                    userCond = false;
                    LoginHelp.innerHTML = `this username is not availabe,try another`
                }
            }
            if (userCond === true) {
                InputUser.style.borderColor = "#ccc";
                LoginHelp.innerHTML = ``
            }
        }

        if (InputEmail.value === "") {
            InputEmail.style.borderColor = "red";
            userCond = false;
        }
        else {
            InputEmail.style.borderColor = "#ccc";
        }
        if (InputPassword1.value === "") {
            InputPassword1.style.borderColor = "red";
            userCond = false;
        }
        else {
            InputPassword1.style.borderColor = "#ccc";
        }
        if (InputPassword2.value === "") {
            InputPassword2.style.borderColor = "red";
            userCond = false;
        }
        else {
            InputPassword2.style.borderColor = "#ccc";
        }

        // email validation regex
        var emailRgex = /\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*/;

        if (emailRgex.test(InputEmail.value)) {
            InputEmail.style.borderColor = "#ccc";

        } else {
            InputEmail.style.borderColor = "red";
            userCond = false;

        }

        // validating password
        if (InputPassword1.value !== InputPassword2.value) {
            InputPassword1.style.borderColor = "red";
            InputPassword2.style.borderColor = "red";
            userCond = false;

        } else {
            // InputPassword1.style.borderColor = "#ccc";
            // InputPassword2.style.borderColor = "#ccc";

        }
        // console.log(userCond)    
        return userCond



    }

    // resetting form after submit
    clear() {
        subForm.reset()
    }

    // creating object after validating

    createObj() {
        let data1 = new UserObj(InputUser.value.toUpperCase(), InputEmail.value, InputPassword1.value, new Date().getTime(), [], []);
        return data1

    }
}

// creating object from adduserdata class
let user = new AddUserData();


// submit event
submit.addEventListener('click', event => {







    user.validate()
    if (user.validate()) {
        user.createObj();
        let userObbb = user.createObj();

        // adding data to local storage
        let getfromLocal = localStorage.getItem("userObjLocal");
        if (getfromLocal === null) {
            var arr = [];
        } else {
            arr = JSON.parse(getfromLocal);
        }

        arr.push(userObbb)
        localStorage.setItem("userObjLocal", JSON.stringify(arr))

        console.log(getfromLocal)
        user.clear()
    } else {
        console.log("user cond false")

    }
    // console.log("submitted")
    event.preventDefault()
})
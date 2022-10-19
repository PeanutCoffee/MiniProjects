// getting elements from dom
let teamName = document.getElementById("teamName");
let questionInp = document.getElementById("questionInp");
let addQuestionBtn = document.getElementById("addQuestionBtn");
let questionUl = document.getElementById("questionUl");
let teamMembers = document.getElementById("teamMembers");
let membersUl = document.getElementById("membersUl");
let membersLi = document.getElementsByClassName("membersLi");
let membersLiModal = document.getElementsByClassName("membersLiModal");
let arrForMember = [];
let showingMembers = [];
let delTeamFlag = false;

// getting data from localStorage
let usersObj = localStorage.getItem("userObjLocal");
usersObj = JSON.parse(usersObj);

let userIndex = localStorage.getItem("userIndex");
userIndex = JSON.parse(userIndex);

let teamIndex = localStorage.getItem("teamIndex");
teamIndex = JSON.parse(teamIndex);

// getting login data from local storage
let getUserFromLocal = localStorage.getItem("userObjLoginLocal");
getUserFromLocal = JSON.parse(getUserFromLocal);
if (getUserFromLocal) {
    console.log(getUserFromLocal)
} else {
    window.location = 'index.html'
}

let teamsArr = [];
let newArr = []

let curruntTeam = usersObj[userIndex].createdTeam[teamIndex];
// function for reloading page
function refresh() {
    setTimeout(function() {
        location.reload()
    }, 100);
}


let deleteMemIndex;
let deletePartTeamFunc = (index) => {

    for (let i = 0; i < usersObj.length; i++) {
        if (usersObj[i].name == curruntTeam.members[index]) {
            deleteMemIndex = i;
            console.log(usersObj[i], console.log(index))
        }
    }

    for (let j = 0; j < usersObj[deleteMemIndex].partTeam.length; j++) {
        if (usersObj[deleteMemIndex].partTeam[j].teamKey == curruntTeam.teamKey) {
            usersObj[deleteMemIndex].partTeam.splice(j, 1)
            console.log("key matched")
        }
    }
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))
}







// function for deleting members 
// let deleteMemInd;

let deletMemberFunc = (e, eId) => {
    console.log(eId)
    deletePartTeamFunc(eId)
        // deleting member from dom
    e.parentNode.remove();

    curruntTeam.members.splice(eId, 1)
    deleteMemId = eId;
    deleteMemFlag = true;
    // setting data to local storage after deleting member
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))
    refresh()
}

// displying team name and member 
let displayFunc = () => {

    // showing team name
    teamName.innerHTML = `Team Name : ${curruntTeam.teamName}`;

    //    showing team members on main page
    for (let i = 0; i < curruntTeam.members.length; i++) {
        teamMembers.innerHTML += `
        <li class="membersLi" id="${i}">${curruntTeam.members[i]}<i id="${i}" onclick="deletMemberFunc(this,this.id)" class="fas fa-user-times"></i></li>`
        showingMembers.push(curruntTeam.members[i])
    }

}
displayFunc()
    // function for adding question to object
let addQuestFunc = () => {
    // getting questions from users input
    if (curruntTeam.questions === undefined) {
        var questArr = []
    } else {

        questArr = curruntTeam.questions;
    }
    questArr.push({ q: questionInp.value, ans: "" })
        // setting question in  users object 
    curruntTeam.questions = questArr;
    curruntTeam.reports = []
        // updating users object after adding question
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))

    // removing question from input afer adding
    questionInp.value = ""
    displayQuestFunc()
        // refresh()
}
addQuestionBtn.addEventListener('click', addQuestFunc);

// function for deleting questions
let deleteQuest = (id, e) => {
    // deleting question from dom
    e.parentNode.parentNode.remove()

    // deleting question from users object
    curruntTeam.questions.splice(id, 1);
    // setting localstorage updated object after deleting question
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))

}

// function for displaying questions
let displayQuestFunc = () => {
    if (curruntTeam.questions) {
        questionUl.innerHTML = ""
            // loop for displaying question
        for (let i = 0; i < curruntTeam.questions.length; i++) {
            questionUl.innerHTML += `
                    <li id="${i}" class="list-group-item"><div>${curruntTeam.questions[i].q}</div><div><i id="${i}" onclick="deleteQuest(this.id,this)" class="fas fa-trash"></i></div></li>`
        }

    }

}

// reloading page after adding members
let addMembersFunc = () => {
    refresh()

}

// function showing useres and add them
let addMemberFunc = (e, eId) => {
    // removing members from dom after clicking on members
    e.remove()
        // pushing members after clicking on member
    arrForMember.push(usersObj[eId].name);

    // setting data in object after adding
    curruntTeam.members.push(usersObj[eId].name);
    // setting data to localstorage after updating members
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))
}

// showing members in modal box
let modalBBtn = document.getElementById("modalBBtn");

var addMembers = () => {
    for (let i = 0; i < usersObj.length; i++) {
        membersUl.innerHTML += `
        <li class="membersLiModal" onclick="addMemberFunc(this,this.id)"  id="${i}">${usersObj[i].name}</li>`

        if (usersObj[i].name == usersObj[userIndex].name) {
            console.log(membersLiModal[i].innerText, usersObj[userIndex].name)
            membersLiModal[i].style.display = "none"
        }
        for (let s = 0; s < membersLi.length; s++) {

            if (membersLiModal[i].innerText == membersLi[s].innerText) {
                membersLiModal[i].style.display = "none"
            }
        }

    }
}
addMembers()


// delete team function
let deleteTeamFunc = () => {
    Swal.fire({
        title: 'Are you sure?',
        text: "You won't be able to revert this!",
        icon: 'warning',
        showCancelButton: true,
        confirmButtonColor: '#3085d6',
        cancelButtonColor: '#d33',
        confirmButtonText: 'Yes, delete it!'
    }).then((result) => {
        if (result.isConfirmed) {
            Swal.fire(
                'Deleted!',
                'Your file has been deleted.',
                'success'
            )
            delTeamFlag = true
            deletePartTeam()
            window.location = "login.html"
        }
    })

    // getting index from id and deleting from object
    // setting deleted item from object and setting it to main object
    // localStorage.setItem("userObjLocal", JSON.stringify(usersObj));
    // changing window location

}
console.log(delTeamFlag)

// console.log(usersObj[userIndex].createdTeam[teamIndex].members)
// let curruntTeamObj = usersObj[userIndex]

var deletePartTeam = () => {

    let teamFound = true;
    let curruntpartIndex;
    let teamMemberArr = curruntTeam.members;
    for (let i = 0; i < usersObj.length; i++) {
        for (let j = 0; j < teamMemberArr.length; j++) {
            // console.log(usersObj[i], teamMemberArr[j])
            if (usersObj[i].name == teamMemberArr[j]) {
                // console.log("matched")
                for (let k = 0; k < usersObj[i].partTeam.length; k++) {
                    if (usersObj[i].partTeam[k].teamKey == curruntTeam.teamKey) {
                        usersObj[i].partTeam.splice(k, 1)
                        curruntpartIndex = k;
                        // teamFound = false;
                    }
                }
                if (teamFound) {
                    usersObj[i].partTeam.push(curruntTeam);
                }
                if (delTeamFlag) {
                    usersObj[i].partTeam.splice(curruntpartIndex, 1)
                        // console.log(usersObj[i].name);
                }
            }
        }
    }

    if (delTeamFlag) {
        usersObj[userIndex].createdTeam.splice(teamIndex, 1)
    }
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj));
}

deletePartTeam()




let getAnswer = () => {

}




displayQuestFunc()

////////////////////////////////////// logout
logoutBtn.addEventListener('click', () => {
    localStorage.removeItem("userObjLoginLocal");
    window.location = 'index.html'
})
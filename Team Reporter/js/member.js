// getting elements from dom
let teamName = document.getElementById("teamName");
let questionInp = document.getElementById("questionInp");
let addQuestionBtn = document.getElementById("addQuestionBtn");
let questionUl = document.getElementById("questionUl");
let teamMembers = document.getElementById("teamMembers");
let membersUl = document.getElementById("membersUl");
let membersLi = document.getElementsByClassName("membersLi");
let membersLiModal = document.getElementsByClassName("membersLiModal");
let submitBtn = document.getElementById("submitBtn");
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

let teamsArr = [];
let newArr = []

let curruntUsername = usersObj[userIndex].name;

console.log(usersObj[userIndex].partTeam[teamIndex])

let curruntTeam = usersObj[userIndex].partTeam[teamIndex];


// getting login data from local storage
let getUserFromLocal = localStorage.getItem("userObjLoginLocal");
getUserFromLocal = JSON.parse(getUserFromLocal);
if (getUserFromLocal) {
    console.log(getUserFromLocal)
} else {
    window.location = 'index.html'
}


// function for reloading page
function refresh() {
    setTimeout(function() {
        location.reload()
    }, 100);
}


// displying team name and member 
let displayFunc = () => {

    // showing team name
    teamName.innerHTML = `Team Name : ${curruntTeam.teamName}`;

}
displayFunc()
    // function for adding question to object
    // let addQuestFunc = () => {
    //     // getting questions from users input
    //     if (curruntTeam.questions === undefined) {
    //         var questArr = []
    //     } else {

//         questArr = curruntTeam.questions;
//     }
//     questArr.push({ q: questionInp.value, ans: "" })
//     // setting question in  users object 
//     curruntTeam.questions = questArr;
//     // updating users object after adding question
//     localStorage.setItem("userObjLocal", JSON.stringify(usersObj))

//     // removing question from input afer adding
//     questionInp.value = ""
//     displayQuestFunc()
//     // refresh()
// }
// addQuestionBtn.addEventListener('click', addQuestFunc);

// function for deleting questions






console.log(curruntTeam.questions[0])
let answer = (element, Eid) => {
    curruntTeam.questions[Eid].ans = element.value;
    console.log(element.value)


    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))
    console.log(curruntTeam.questions)
}

let submit = () => {
    // curruntTeam.questions[Eid].ans = element.value;
    for (let i = 0; i < usersObj.length; i++) {
        for (let j = 0; j < usersObj[i].createdTeam.length; j++) {
            if (usersObj[i].createdTeam[j].admin == curruntTeam.admin) {
                console.log(curruntTeam.admin, usersObj[i].createdTeam[j].admin);
                usersObj[i].createdTeam[j].reports.push({
                    [curruntUsername]: curruntTeam.questions
                })
            }
        }
    }
    // curruntTeam.questions.push()
    curruntTeam.subBtnStatus = true;
    localStorage.setItem("userObjLocal", JSON.stringify(usersObj))
        // console.log(curruntTeam.admin)
    submitBtn.disabled = true;

}
submitBtn.disabled = curruntTeam.subBtnStatus;
// function for displaying questions
let displayQuestFunc = () => {
    questionUl.innerHTML = ""
        // loop for displaying question
    for (let i = 0; i < curruntTeam.questions.length; i++) {
        questionUl.innerHTML += `
                <li id="${i}" class="list-group-item"><div>Q : ${curruntTeam.questions[i].q}</div>
                    <div><input type="email" onblur="answer(this,this.id)" value="${curruntTeam.questions[i].ans}" class="form-control answer" id="${i}" placeholder="ANSWER"></div>
                </li>`
    }

}

displayQuestFunc()

////////////////////////////////////// logout
logoutBtn.addEventListener('click', () => {
    localStorage.removeItem("userObjLoginLocal");
    window.location = 'index.html'
})
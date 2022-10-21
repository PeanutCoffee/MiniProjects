let qA = document.getElementById("qA");
let userName = document.getElementById("userName");
let reportsSec = document.getElementById("reportsSec");


// getting data from localStorage
let usersObj = localStorage.getItem("userObjLocal");
usersObj = JSON.parse(usersObj);

let userIndex = localStorage.getItem("userIndex");
userIndex = JSON.parse(userIndex);

let teamIndex = localStorage.getItem("teamIndex");
teamIndex = JSON.parse(teamIndex);

curruntTeam = usersObj[userIndex].createdTeam[teamIndex]

// getting login data from local storage
let getUserFromLocal = localStorage.getItem("userObjLoginLocal");
getUserFromLocal = JSON.parse(getUserFromLocal);
if (getUserFromLocal) {
    console.log(getUserFromLocal)
} else {
    window.location = 'index.html'
}


if (curruntTeam.reports.length == 0) {
    reportsSec.innerHTML = `<hr><p>no one has submitted answers.`
} else {
    // console.log(Object.keys(curruntTeam.reports[0]))
    let html = [];
    let userHtml = [];
    let p = 0;
    let displayQuest = () => {
        for (let i = 0; i < curruntTeam.reports.length; i++) {
            // console.log(curruntTeam.reports[0])
            console.log(Object.keys(curruntTeam.reports[i])[0])
            html.push(`<hr>Name : ${Object.keys(curruntTeam.reports[i])[0]}`)
            console.log(curruntTeam.reports[i])

            for (let j in curruntTeam.reports[i]) {
                // userHtml = Object.keys(curruntTeam.reports[p])[0]
                userHtml.push(Object.keys(curruntTeam.reports[p])[0])
                console.log(userHtml)
                p++
                for (let k = 0; k < curruntTeam.reports[i][j].length; k++) {
                    console.log(curruntTeam.reports[i][j][k])
                    html.push(`Q .${curruntTeam.reports[i][j][k].q}`)
                    html.push(`A .${curruntTeam.reports[i][j][k].ans}`)
                        // += `
                        // <p>${curruntTeam.reports[i][j][k].q}</p>
                        // <p>${curruntTeam.reports[i][j][k].ans}</p>
                        // `
                }
                // for(let k in curruntTeam.reports[i]){

                // }

                // qA.innerHTML = `${html}`


                // userName.innerHTML += ` <p >${userHtml[i]}</p> `
            }
            console.log(html)
                // <div id="userName">${userHtml[i]}</div>



        }
        for (let d = 0; d < html.length; d++) {
            console.log(html[d])
            qA.innerHTML += `
            
            <div id="qA">
            <p>${html[d]}</p>
            
            
            
            </div>`
        }
        // <div id="userName">${userHtml[d]}</div>

    }
    displayQuest()

}
////////////////////////////////////// logout
logoutBtn.addEventListener('click', () => {
    localStorage.removeItem("userObjLoginLocal");
    window.location = 'index.html'
})
let countel = document.getElementById("count")
let saveel = document.getElementById("save-el")
let count = 0

function increment(){
    count += 1
    countel.innerText = count
}

function save() 
{
    let counterStr = count + " - "
    saveel.textContent += counterStr
    countel.textContent = 0
    count = 0
}

//using saveel.textContent instead of saveel.innerText is used to get hidden characters such as "-"
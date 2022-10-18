const greetingDisplay = document.getElementById("greeting-display")
const to = document.getElementById("recipient-input");
const fro = document.getElementById("sender-input")
const message = document.getElementById("greeting-select")
const custominput = document.getElementById("custom-input")
const customDiv = document.getElementById("custom")
let msg =``

function writeGreeting() {
    // Write a function update the message in the greeting-display paragraph each time the form is updated.
    if(to.value){
        msg = `Dear ${to.value},<br><br>`;
    }
    if (message.value == "custom") {
        customDiv.setAttribute("class", "")
        msg += custominput.value;
    } else {
        customDiv.setAttribute("class", "hidden")
        msg += message.value;
    }
    if(fro.value){
        msg += `<br><br>&emsp;&emsp;With love,<br>&emsp;&emsp;&emsp;${fro.value}`    
    }
    
    greetingDisplay.innerHTML = msg;
    
}

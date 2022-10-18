const chatForm = document.getElementById('chat-form')
const roomName = document.getElementById('room-name')
const userList = document.getElementById('users')
const chatMsg = document.querySelector('.chat-messages');
const { username,room } = Qs.parse(location.search,{
    ignoreQueryPrefix: true
});
console.log(username,room)
const socket =io(); 

socket.emit('joinRoom',{username,room})
socket.on('message',message =>{
    console.log(message);
    outputMessage(message)
})
socket.on('roomUsers',({room,users})=>{
    outputRoomName(room);
    outputUsers(users);
})

chatForm.addEventListener('submit',(e)=>{
    e.preventDefault();
    const msg = e.target.elements.msg.value;
    // console.log(msg)
    socket.emit('chatMessage',msg);
    e.target.elements.msg.value =" ";
    e.target.elements.msg.focus();
})
chatMsg.scrollTop = chatMsg.scrollHeight;
function outputMessage(message) {
    const div = document.createElement('div');
    div.classList.add('message');
    div.innerHTML = `<p class="meta">${message.username} <span>${message.time}</span></p>
    <p class="text">
    ${message.text}
    </p>`;
    document.querySelector('.chat-messages').appendChild(div);
    }
    function outputRoomName(room){
        roomName.innerText = room;
    }

    function outputUsers(users){
        userList.innerHTML = `${users.map(user=> `<li> ${user.username} </li>`).join('')}`;
    }
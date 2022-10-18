const path = require('path')
const express = require('express');
const http = require('http');
const app = express();
const socketio = require('socket.io')
const formatMessage = require('./utils/messages')
const {userJoin,getCurrentUser,userLeave,getRoomUsers} = require('./utils/users')
 

const server = http.createServer(app)
const io = socketio(server);
const admin = 'Admin'
io.on('connection', socket => {
socket.on('joinRoom',({username,room})=>{
const user = userJoin(socket.id,username,room);
    socket.join(user.room); 
    socket.emit('message', formatMessage(admin,'Welcome to the chat'))
    socket.broadcast.to(user.room).emit('message', formatMessage(admin,
        ` ${user.username} joined the chat`))
          io.to(user.room).emit('roomUsers',{ room :user.room,
        users :  getRoomUsers(user.room)})
})
  
    socket.on('disconnect', () => {
        const user = userLeave(socket.id)
        if(user){
            io.to(user.room).emit('message', formatMessage(admin,`${user.username} left the chat`))
            io.to(user.room).emit('roomUsers',{ room :user.room,
                users:getRoomUsers(user.room)}) 
        }
        
    });
        socket.on('chatMessage',(msg)=>{
            const user = getCurrentUser(socket.id);
            io.to(user.room).emit('message',formatMessage(user.username,msg));
        })
});

const PORT = 3000||process.env.PORT;
app.use(express.static(path.join(__dirname, 'public')))
server.listen(3000,()=>{
    console.log('listening on port 3000')
})
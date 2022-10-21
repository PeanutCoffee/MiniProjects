const path = require('path');
const express = require('express');
const app = express();
const port = process.env.PORT || 3000;

const publicPath = path.join(__dirname, '../', 'build');

app.use(express.static(publicPath));

app.get('/', (req, res) => {
    res.sendFile(path.join(publicPath, 'index.html'));
});
app.listen(port, () => {
    console.log('Server is up!');
});
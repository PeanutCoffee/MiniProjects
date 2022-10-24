import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import Calculator from './Components/Calculator';
import registerServiceWorker from './registerServiceWorker';

ReactDOM.render(<Calculator />, document.getElementById('Calculator'));
registerServiceWorker();

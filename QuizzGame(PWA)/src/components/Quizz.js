import React,{useState} from 'react'
import quizzwal from './quizzwall.jpg'
import {Link} from 'react-router-dom' 
// import Quizzdashboard from './Quizzdashboard'
function Quizz(props) {
	// const [types, settypes] = useState("multiple");
    const [quizz, setquizz] = useState({amount:"10",category:"",type:"multiple",difficulty:""})
    const handleOnchange=(e)=>{
        setquizz({...quizz, [e.target.name]: e.target.value})
    }
    return (
        <div  style={{height:"110vh",width:"100vw",backgroundImage:`url(${quizzwal})`}}>
        <div  className="container">
			<div className='quizselect'>
            <h1 style={{    color: "#092652"}} className='text-center mb-4'>Create a Quizz</h1>
           

		<label className='ll' htmlFor="amount">Number of Questions:(max: 50)</label>
		<input type="number" name="amount" id="amount" className="form-control pp" min="1" max="50" value={quizz.amount} onChange={handleOnchange}/>

		<br/>

		<label className='ll' htmlFor="category">Select Category: </label>
		<select name="category" className="form-control pp" id="category" 
		// onChange={(e)=>{
		// 		const selectedvalue=e.target.value;
		// 		setCategory(selectedvalue);}}
		onChange={handleOnchange}
		>
			<option value="any">Any Category</option>
			<option value="9">General Knowledge</option><option value="10">Entertainment: Books</option><option value="11">Entertainment: Film</option><option value="12">Entertainment: Music</option><option value="13">Entertainment: Musicals &amp; Theatres</option><option value="14">Entertainment: Television</option><option value="15">Entertainment: Video Games</option><option value="16">Entertainment: Board Games</option><option value="17">Science &amp; Nature</option><option value="18">Science: Computers</option><option value="19">Science: Mathematics</option><option value="20">Mythology</option><option value="21">Sports</option><option value="22">Geography</option><option value="23">History</option><option value="24">Politics</option><option value="25">Art</option><option value="26">Celebrities</option><option value="27">Animals</option><option value="28">Vehicles</option><option value="29">Entertainment: Comics</option><option value="30">Science: Gadgets</option><option value="31">Entertainment: Japanese Anime &amp; Manga</option><option value="32">Entertainment: Cartoon &amp; Animations</option>		</select>

		<br/>

		<label className='ll' htmlFor="difficulty">Select Difficulty: </label>
		<select name="difficulty" className="form-control pp" onChange={handleOnchange}>
			<option value="any">Any Difficulty</option>
			<option value="easy">Easy</option>
			<option value="medium">Medium</option>
			<option value="hard">Hard</option>
		</select>

		<br/>

		<label className='ll' htmlFor="type">Select Type: </label>
		<select name="type" className="form-control pp" onChange={handleOnchange}>
			
			<option value="multiple">Multiple Choice</option>
			<option value="boolean">True / False</option>
		</select>

		<br/>
			
		<Link to="/quizzdashboard"><button onClick={()=>{localStorage.setItem("quizz",JSON.stringify(quizz));localStorage.setItem("typest",quizz.type);localStorage.setItem("score",0);localStorage.setItem("count",0)}}  className="btn btn-lg btn-primary btn-block" type="submit">Create Quizz</button></Link>
	

        </div>
		</div>
        </div>
    )
}

export default Quizz

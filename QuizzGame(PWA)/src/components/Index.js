import React from 'react'
import {useNavigate} from 'react-router-dom'
import dp from './dp.png'
import dp1 from './dp1.png'
import quizzer from './quizzer.png'
function Index() {
    let navigate=useNavigate()
    return (
      <>
        <div className='bg'>
          <div className='text-center pt-4'>
            
          <div className="mainlogo d-inline">Quizzer</div>&emsp;
          <img src={quizzer} alt="" /></div>
          <hr style={{color:"cyan",height:"5px"}}/>
<div className="container">
               <div style={{backgroundColor:"transparent"}} className="card cardd  " >
  <div className="row g-0">
    <div className="col-md-4">
      <img src={dp} className="img-fluid rounded-start" alt="..."/>
    </div>
    <div className="col-md-8">
      <div className="card-body mt-5">
        <h3 style={{color:"Highlight"}} className="card-title">Test Your Knowledge</h3>
        <p  style={{color:"white",fontSize:"larger"}} className="card-text mt-3"> <i className="fas fa-hand-point-right"></i> Education is an admirable thing, but it is well to remember from time to time that nothing that is worth knowing can be taught. – Oscar Wilde</p>
        <p style={{color:"white",fontSize:"larger"}}><i className="fas fa-hand-point-right"></i> An investment in knowledge pays the best interest.- Benjamin Franklin</p>
        <p style={{color:"white",fontSize:"larger"}}><i className="fas fa-hand-point-right"></i> To educate a man in mind and not in morals is to educate a menace to society. – Theodore Roosevelt</p>
        <p style={{color:"white",fontSize:"larger"}}><i className="fas fa-hand-point-right"></i> Education is the ability to listen to almost anything without losing your temper or your self-confidence. – Robert Frost</p>
       <div> <button className='btnn' onClick={()=>{navigate("/quizz")}}>Play Quiz</button></div>
      </div>
    </div>
  </div>
</div></div>
<section id="about">
<h2 style={{color:"Highlight"}} className="text-center">About</h2>
<hr style={{color:"cyan",height:"5px"}}/>
            <div style={{backgroundColor:"transparent",paddingTop:"1rem"}} className="card cardd  " >
  <div className="row g-0">
    <div className="col-md-4">
      <img src={dp1} className="img-fluid rounded-start" alt="..."/>
    </div>
    <div className="col-md-8">
      <div className="card-body mt-5">
        
        <p  style={{color:"white",fontSize:"large"}} className="card-text mt-3"> Quizzer is an application to create and play Quizzes of different categories like sciene,films and many more. You can set the difficulty level and Number of Questions. On clicking on option it give the correct answer immediately.</p>
        <p style={{color:"cyan",fontSize:"large"}}>
          API used for fetching data---<strong>Open Trivia DB</strong>
        </p>
       
      </div>
    </div>
  </div>
</div>
<footer className="footr">
<h5>-----  Build by - Sachin Sharma  -----</h5> 
</footer>
        </section>
        </div>
       
        </>
    )
}

export default Index

import React,{useState,useEffect} from 'react'
import QuizzItem from './QuizzItem';
import jquery from 'jquery';
import error from './error-404.png'
import { useNavigate } from 'react-router-dom';
import bgg from './bgg.jpg'

function Quizzdashboard() {
  const [visible, setVisible] = useState(false);
  let navigate=useNavigate()
  
  const [nodata, setNodata] = useState(false);
const [gameover, setGameover] = useState(false);
  const score=(score)=>{
      document.getElementById("getscore").innerText=score;
     
  }
  
  const count=(count)=>{
      if(count===retrive().amount){
      
        setGameover(true);
      }
      
  }
  const getData=(questions)=>{
   
let str = questions;
    
let html = jquery.parseHTML(str);
   
return html[0].data;
}
  const getDataa=(answer)=>{
    
    let arr=[],i;
    for(i=0;i<4;i++)
       {
           arr[i]=jquery.parseHTML(answer[i])[0].data;
       }

return arr;
}
  
    const retrive=()=>{
        var a=localStorage.getItem("quizz");
        return JSON.parse(a);
    }
    const [results, setResults] = useState([])
    const [url1, seturl] = useState("")
    const retrievequizz=async()=>{
      setVisible(true)
        
    let url = `https://opentdb.com/api.php?amount=${retrive().amount}&category=${retrive().category}&difficulty=${retrive().difficulty}&type=${retrive().type}`;
    seturl(url);
    
    let data = await fetch(url);
    
    let parsedData = await data.json();
   
    if(parsedData.results.toString()===''){
      setNodata(true);
      document.getElementById('head').style.display='none'
    }
    setResults(parsedData.results);
    
    setVisible(false)
    
    }
    useEffect(() => {
      retrievequizz();
      
    
      
      // eslint-disable-next-line
    }, []);

    function shuffleArray(array) {
      let curId = array.length;
     
      while (0 !== curId) {
       
        let randId = Math.floor(Math.random() * curId);
        curId -= 1;
       
        let tmp = array[curId];
        array[curId] = array[randId];
        array[randId] = tmp;
      }
      return array;
    }
    
    return (
      <>
      {gameover &&<div className='gameover'>
        <div className="card">
          <div >
          <h1>Your Score:</h1>
          <div className='scoo'>{localStorage.getItem("score")}</div></div>
          <div>
            <button onClick={()=>{window.location.reload()}} className='btn btn-success'>Play Again</button>&emsp;
            <button onClick={()=>{navigate("/quizz")}} className='btn btn-success'>Back to Quizz Menu</button>
          </div>
        </div>
      </div>}
      
       {visible && <div className='load'></div>}
       {nodata && <div style={{height:"100vh"}} className='nodata'><div className='imgerr' >
         <img src={error} alt="" />
         <div className='errlabel'>
           Currently Not Available!! <br/>
           Try for different category,type or level<br/><br/>
           <button onClick={()=>{navigate('/quizz')}} className='btn btn-primary'>Quiz Menu</button>
         </div>
         </div></div>}
       <div style={{backgroundImage:`url(${bgg})`,marginBottom:"2rem"}}>
            <div id='head' className=' header'>
                <h1 className='darkmode d-flex align-items-center'>Quizzer</h1>
                <div className="borderr p-3"><h3 className='darkmode'>Score :</h3>  <div id="getscore" className='darkmode srr'></div></div>
            </div>

                <div className="container">
            {results.map((element) => {
                    let answer=shuffleArray([...element.incorrect_answers,element.correct_answer])
                  
              return (
                <div className="container"  key={url1+element.question} >
                  
                  {localStorage.getItem("typest")==="multiple"?<QuizzItem
                  
                  score={score}
                 count={count}
                    question={getData(element.question)}
                   category={getData(element.category)}
                    type={getData(element.type)}
                    difficulty={getData(element.difficulty)}
                    answer={getDataa(answer)}
                    correct_answer={getData(element.correct_answer)}
                  />:
                  <QuizzItem
                
                  score={score}
                  count={count}
                  amount={retrive().amount}

                    question={getData(element.question)}
                   category={getData(element.category)}
                    type={getData(element.type)}
                    difficulty={getData(element.difficulty)}
                    correct_answer={getData(element.correct_answer)}
                   
                    answer={answer}
                  />}

                </div>
              );

            })}


          </div>
        </div>
        <div className='text-center darkmode p-3' style={{height:"10vh",backgroundColor:"black",marginTop:"-32px"}}>
              Quizzer &copy; all right reserved
        </div>
        </>
    )
}

export default Quizzdashboard

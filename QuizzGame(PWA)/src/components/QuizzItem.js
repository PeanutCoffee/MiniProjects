import React,{useEffect,useState} from 'react'
function QuizzItem(props) {
   
const [visible, setVisible] = useState(false);
const [getuserans, setGetuserans] = useState("");



useEffect(() => {
 localStorage.setItem("score",0);
 let score=parseInt(localStorage.getItem("score"));
 props.score(score);
 localStorage.setItem("count",0);
 let count=parseInt(localStorage.getItem("count"));
 props.count(count)


 //eslint-disable-next-line
}, []);

const checkanswer=()=>{
  let count=parseInt(localStorage.getItem("count"));
    count=count+1;
    count=count.toString()
  
      localStorage.setItem("count",count)
      props.count(count);

  if(localStorage.getItem("userans")===props.correct_answer.toString())
  {
    let score=parseInt(localStorage.getItem("score"));
    score=score+1;
    score=score.toString()
   
      localStorage.setItem("score",score)
      props.score(score)
      return "correct"
    // console.log(score);
  }
  
    }
        


    const handleonchange1=(e)=>{

      localStorage.removeItem("userans");
      localStorage.setItem("userans",e.target.value);
      setGetuserans(localStorage.getItem("userans"));
      
      checkanswer();
      document.getElementById(`${props.question}+1`).disabled=true;
      document.getElementById(`${props.question}+2`).disabled=true;
      document.getElementById(`${props.question}+3`).disabled=true;
      document.getElementById(`${props.question}+4`).disabled=true;
  
   
        setVisible(true);
    //  props.score(score);
    }
   
    const handleonchangeb1=(e)=>{
      localStorage.removeItem("userans");
      localStorage.setItem("userans",e.target.value);
      
      
      setGetuserans(localStorage.getItem("userans"));
    
   
      checkanswer()
      
      document.getElementById(`${props.question}+10`).disabled=true;
      document.getElementById(`${props.question}+20`).disabled=true;
    
      // props.score(score);
      setVisible(true);
    }
    
    
    return (
        <div>
            <div id="questionc" className="container my-4 ">
                <section>
                    <div className="inner shadow-sm rounded p-4 quizbg">
                        <div style={{marginBottom:"1rem"}} id="question " className='darkmode'>Q.{props.question}</div>
                        <div className="options">
                           
                        {localStorage.getItem("typest")==="multiple"?<><div className="form-check mb-2" id="1" >
  <input className="form-check-input" type="radio" name={`${props.question}+1`} id={`${props.question}+1`}onClick={handleonchange1} value={props.answer[0]} />
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+1`}>
   {props.answer[0]}
  </label>
</div>
                           
                        <div className="form-check mb-2" id="2" >
  <input className="form-check-input" type="radio" name={`${props.question}+1`} id={`${props.question}+2`} onClick={handleonchange1} value={props.answer[1]}  />
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+2`}>
  {props.answer[1]}
  </label>
</div>
             
                        <div className="form-check mb-2"id="3" >
  <input className="form-check-input" type="radio" name={`${props.question}+1`} id={`${props.question}+3`}onClick={handleonchange1} value={props.answer[2]} />
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+3`}>
  {props.answer[2]}
  </label>
</div>
                           
                        <div className="form-check mb-2" id="4"  >
  <input className="form-check-input" type="radio" name={`${props.question}+1`} onClick={handleonchange1} id={`${props.question}+4`} value={props.answer[3]}/>
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+4`}>
  {props.answer[3]}
  </label>
</div>
</>:<>                     <div className="form-check mb-2" id="b1" >
  <input className="form-check-input" type="radio" name={`${props.question}+11`}onClick={handleonchangeb1} id={`${props.question}+10`}  value={props.answer[0]}/>
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+10`}>
  {props.answer[0]}
  </label>
</div>
                           
                        <div className="form-check mb-2" id="b2" >
  <input className="form-check-input" type="radio" name={`${props.question}+11`}onClick={handleonchangeb1} id={`${props.question}+20`}  value={props.answer[1]}/>
  <label className="form-check-label darkmode ts" htmlFor={`${props.question}+20`}>
  {props.answer[1]}
  </label>
</div></> }  
                                
                        </div>
                    </div>
                  
                   {visible && <div style={{backgroundColor:"#2fff7c"}}>
                   <div style={{padding:"6px 30px",borderRadius:"3px",fontFamily:"cursive",fontWeight:"bold"}}>
                     <h4 style={{fontWeight:"bold"}}>Correct Answer</h4>
                     
                   {props.correct_answer}
                   </div>
                    {props.correct_answer!==getuserans?<div id={`${props.question}`}>
                        <div style={{backgroundColor:"rgb(19 101 142)",padding:"6px 30px",fontFamily:"cursive",fontWeight:"bold"}}>
                          <h4 style={{fontWeight:"bold"}}>Your Answer</h4>
                        {getuserans}
                        </div>
                      </div>:
                      <div id={`${props.question}`} style={{padding:"6px 30px",fontFamily:"cursive",fontWeight:"bold"}}>
                        <h4 style={{fontWeight:"bold"}}>Your Answer</h4>
                        {getuserans}
                      </div>}
                   </div>}
                </section>
            </div>
        </div>
    )
}

export default QuizzItem

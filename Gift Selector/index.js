document.getElementById("btn").addEventListener("click", calculate)
const costEl = document.getElementById("cost-el")
 
let total = 0;

function calculate() {
    // 1. Write the JavaScript to calculate the total cost of the selected options from the form.
  const isValid = gift.checkValidity();
  if(!isValid){
    alert("Please fill all fields");
  }
  else{
    const foodOption = document.getElementById('food-select');
    const transportOption = document.getElementById('transport-select');
    const food = parseInt(foodOption.value);
    const transport = parseInt(transportOption.value);
    const balloon = document.getElementById('balloon-checkbox');
    
    let checkedBalloon = 1; 
      if(balloon.checked){
           checkedBalloon = 0;
      }
    
    total = food + transport + checkedBalloon;
    console.log(total);
    // 2. Display the total cost in the cost-el span.
    costEl.textContent = "$" + total;
  }
    
}
 
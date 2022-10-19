// ## Array Cardio Day 2
const people = [
    { name: 'Wes', year: 1988 },
    { name: 'Kait', year: 1986 },
    { name: 'Irv', year: 1970 },
    { name: 'Lux', year: 2015 }
  ];
  const comments = [
    { text: 'Love this!', id: 523423 },
    { text: 'Super good', id: 823423 },
    { text: 'You are the best', id: 2039842 },
    { text: 'Ramen is my fav food ever', id: 123523 },
    { text: 'Nice Nice Nice!', id: 542328 }
  ];
  // Some and Every Checks
  // Array.prototype.some() // is at least one person 19 or older?
  // const isAdult = people.some(function(person)  {
  //   if(currentYear - person.year >= 19) {
  //     return true;
  //   }
  // });
  // OR GOOD 
  // const isAdult = people.sone(person => {
  //   const currentYear = (new Date()).getFullYear();
  //   return currentYear - person.year >= 19;
  // })

  // OR BETTER
  const isAdult = people.some(person => ((new Date()).getFullYear()) - person.year >= 19); // HOTSHOT BRO

  // Array.prototype.every() // is everyone 19 or older?    console.log({isAdult});
  const allAdult = people.every(person => ((new Date()).getFullYear()) - person.year >= 19); 

  console.log({allAdult});

  // Array.prototype.find()
  // Find is like filter, but instead returns just the one you are looking for
  // const comment = comments.find(function(comment) {
  //   if(comment.id === 823423) {
  //     return true;
  //   }
  // })
  // Console.log(comment);

  // Better with arrow function
  const comment = comments.find(comment => 
     comment.id === 823423);
  
  console.log(comment);

  // find the comment with the ID of 823423
  // Array.prototype.findIndex()
  // Find the comment with this ID
  // delete the comment with the ID of 823423

  const index = comments.findIndex(comment => comment.id === 823423);
  console.log(index);
  // comments.splice(index, 1);
  // this is popular with the redux world
  const newComments = [
    ...comments.slice(0, index),
    ...comments.slice(index + 1)
  ];
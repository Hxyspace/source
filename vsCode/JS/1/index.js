console.log('hello world');

function square(number) {
    return number * number;
}

console.log(square(5));

const name = 'li Hua';
const age = 20;

console.log('Hello, I am' + name + ', my age is' + age);
//用反引号表示使用字符串模板
let hello = `Hello , I am ${name}, my age is ${age}.`;

console.log(hello);
console.log(hello.length);
console.log(hello.toUpperCase());
console.log(hello.substring(0, 5));
console.log(hello.split(' '));

const todos = [
    {
        id:1,
        text: 'this is first text.',
        inCompleted: true
    },
    {
        id: 2,
        text: 'this is secont text.',
        inCompleted: true
    },
    {
        id: 3,
        text: 'this is thrid text.',
        inCompleted: false
    }
];

console.log(todos[2].text);

const totoJson = JSON.stringify(todos);
console.log(totoJson);

for(let todo of todos) {
    console.log(todo.id);
}

//forEach, map, filter
todos.forEach(function(todo){
    console.log(todo.id);
})

const todoText = todos.map(function(todo){
    return todo.text;
})
console.log(todoText);

const todoCompleted = todos.filter(function(todo){
    return todo.inCompleted === true;
})
console.log(todoCompleted)
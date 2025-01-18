let full_name = "Tony Stark";
let age = 17;
let price = 150.50;
x = null;
y = undefined;
isFollow = false;

const pi = 3.14;
//pi = 3

console.log(full_name);
console.log(age);
console.log(price);
console.log(x);
console.log(y);
console.log(isFollow);
console.log(pi);

console.log(typeof(price));
console.log(typeof(full_name));
console.log(typeof(x));

const student = {
    fullName : "Rahul Kumar",
    age : 20,
    cgpa : 8.2,
    isPass : true
};

console.log(student);
console.log(typeof(student));

console.log(student["fullName"]);
console.log(student.fullName);

student["age"] = student["age"] + 1;
console.log(student["age"]);
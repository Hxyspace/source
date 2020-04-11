/*
function Persion( fristName, lastName, dob) {
    this.fristName = fristName;
    this.lastName = lastName;
    this.dob = new Date(dob);
}

Persion.prototype.getBrithYear = function () {
    return this.dob.getFullYear();
}

Persion.prototype.getFullName = function() {
    return `${this.fristName} ${this.lastName}`;
}
 */

 //上面对象原型的构造函数 实现的功能 与下面的类 相同   类是ES新特性
class Persion {
    constructor ( fristName, lastName, dob) {
        this.fristName = fristName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }
    getBrithYear() {
        return this.dob.getFullYear();
    }

    getFullName() {
        return `${this.fristName} ${this.lastName}`;
    }
}

const persion1 = new Persion('Li', 'Hua', '3-9-1987');
const persion2 = new Persion('Xiao', 'Hua', '4-6-2012');

console.log(persion1.getFullName());
console.log(persion2);
console.log(persion1.getBrithYear());
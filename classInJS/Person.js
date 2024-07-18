const { TestContext } = require("node:test");

class Person {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }
    intro() {
        console.log('hello chao ', this.name);
    }
};
class Student extends Person {
    constructor(name, age, university, className) {
        super(name, age);
        this.university = university;
        this.className = className;
    }
    intro() {
        console.log('ban den tu', this.university, ' lop', this.className);
    }
};

class DocTor extends Person {
    constructor(name, age, salary) {
        super(name, age);
        this.salary = salary;
    }
    intro() {
        console.log('bac si', this.name, ' luong ', this.salary);
    }
}

class Teacher extends Person {
    constructor(name, age, object) {
        super(name, age);
        this.object = object;
    }
    intro() {
        console.log('xin chao giao vien', this.name, 'day mon', this.object);
    }
}

class MathOject extends Teacher {
    constructor(name, age, object, experience) {
        super(name, age, object);
        this.experience = experience;
    }
    intro() {
        console.log('TOI LA', this.name, 'GIAO VIEN MON', this.object, this.experience, 'KINH NGHIEM');
    }
}
let mt1 = new MathOject('CAM LY', '18', 'TINH YEU HOC DU0NG', '100 NAM');
console.log(mt1);
mt1.intro();
// let pr1 = new Person('Hoang Hai ', '19 tuoi');
// console.log(pr1);
// let st1 = new Student('Hoang Hai', '19', 'hcmue', 'CNTTT.A');
// console.log(st1);
// let dt1 = new DocTor('Hooang Son', '26', parseInt(7000000));
// console.log(dt1);
// let tc1 = new Teacher('Hoang Hoai', '24', 'Giang vien Tin Hoc');
// console.log(tc1);
// tc1.intro();;;
// dt1.intro();
// pr1.intro();
// st1.intro();
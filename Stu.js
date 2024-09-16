const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
class Student {
    constructor(nameclass, nameschool) {
        this.nameclass = nameclass;
        this.nameschool = nameschool;
    }
    intro() {
        console.log('sinh vien lop :', this.nameclass, 'truong', this.nameschool);
    }
}
class Example extends Student {
    constructor(nameclass, nameschool, TotNghiep) {
        super(nameclass, nameschool);
        this.TotNghiep = parseFloat(TotNghiep);
    }

}
async function main() {
    let b = await cin('nhap lop: ');
    let c = await cin('nhap truong: ');
    let d = await cin('Nhap diem ki thi TN: ');
    let a = new Example(b, c, d);
    console.log(a);
    a.intro();
    rl.close();
}
main();
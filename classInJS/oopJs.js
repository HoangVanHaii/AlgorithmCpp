const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

class object_oriented_programing {
    constructor(name, date, coef) {
        this.name = name;
        this.date = date;
        this.coef = coef;
    }
}
class javascript extends object_oriented_programing {
    constructor(name, date, coef, api) {
        super(name, date, coef);
        this.api = api;
    }
}

async function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
async function main() {
    let a = await cin('nhap a');
    console.log(a);
    rl.close();
}
main();

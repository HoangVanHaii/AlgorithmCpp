const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function cin(input) {
    return new Promise(value => rl.question(input, value));
}

class DN {
    #name;
    #age;

    constructor(name, age) {
        this.#name = name;
        this.#age = age;
    }
    // Getter và Setter cho name
    get ten() {
        return this.#name;
    }
    set name(value) {
        this.#name = value;
    }
    // Getter và Setter cho age
    get tuoi() {
        return this.#age;
    }
    set age(value) {
        this.#age = value;
    }
}
async function main() {
    let a = await cin(('nhap ten: '));
    let b = await cin('nhap tuoi: ');
    let c = new DN(a, b);
    console.log(c);
    console.log(`ten : ${c.ten}, tuoi: ${c.tuoi}`);
    rl.close();
}

main();

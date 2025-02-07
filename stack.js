const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function cin(input) {
    return new Promise(resolve => rl.question(input, answer => resolve(answer)));
}

class Stack {
    constructor() {
        this.arr = [];
    }
    push(x) {
        this.arr.push(x);
    }
    pop() {
        return this.arr.pop();
    }

    clear() {
        this.arr = [];
    }
    size() {
        return this.arr.length;
    }
    empty() {
        return this.arr.length === 0;
    }
    ouput() {
        let str = "";
        for (let i = this.arr.length - 1; i >= 0; i--) {
            str += (this.arr[i])
            str += ' ';
        }
        console.log(str);
    }
    top() {
        return this.arr[this.arr.length - 1];
    }
}
async function main() {
    let a = new Stack()
    let n = await cin('nhap n: ');
    for (let i = 0; i < n; i++) {
        let x = await cin('nhap x: ');
        a.push(x);
    }
    // console.log(a);
    a.ouput();
    a.pop();
    a.ouput();
    console.log(a.size());
    while (!a.empty()) {
        console.log(a.top());
        a.pop();
    }
    rl.close();
}

main();

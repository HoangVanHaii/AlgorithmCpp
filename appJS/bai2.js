const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

async function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
};

async function main() {
    let n = parseInt(await cin('nhap n: '));
    let arr = [];
    for (let i = 0; i < n; i++) {
        let x = parseInt(await cin('nhap cac phan tu cua mang: '));
        arr.push(x);
    }
    console.log(arr);
}
main();
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

async function recomment(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
async function main() {
    let a = [];
    let n = parseInt(await recomment('nhap n: '));
    let b = parseFloat(await recomment('nhap b: '));
    let c = parseInt(await recomment('nhap c; '));
    console.log(n, b, c);
    console.log('\n');
    for (let i = 0; i < n; i++) {
        let x = parseInt(await recomment('nhap x: '));
        a.push(x);
    }

    console.log('mang a: ', a);
    rl.close();
}

main();

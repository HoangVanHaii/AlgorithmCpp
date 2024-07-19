const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
function isPri(a) {
    return false;
}

async function main() {
    let a = parseInt(await cin('nhap gia tri cua a; '));
    console.log(a);
    let b = await cin('nhap b: ');
    console.log(b);
    // async function abb() {
    //     let a = await cin('nhap a: ');
    //     console.log('gia tri phu; ', a);
    //     rl.close();
    // }
}
main();

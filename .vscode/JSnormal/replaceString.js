const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

function cin(input) {
    return new Promise(value => rl.question(input, value));
}
function replace(str) {

    str = str.replace(/\s+/g, ' ');
    return str;
}
async function main() {
    let x = await cin('nhap chuoi x: ');
    let y = replace(x);
    console.log(y);
    console.log(y.length);
    rl.close();
}
main();
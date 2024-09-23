const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

function cin(input) {
    return new Promise(value => rl.question(input, value));
}
function replace(str) {
    // str[0].toUppercase();
    // for (let i = 0; i < str.length; i++) {
    //     if (str[i] == ' ' && str[i + 1] == ' ') {
    //         str.erase(i, 1);
    //     }
    // }
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
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
function checkPalindrome(str) {
    for (let i = 0; i < str.length; i++) {
        if (str[i] != str[str.length - i - 1]) return false;
    }
    return true;
}
async function main() {
    let x = await cin('nhap chuoi can check: ');
    if (checkPalindrome(x)) {
        console.log('YES');
    }
    else console.log('NO');
    rl.close();

}
main();
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
function isPrime(a) {
    if (a < 2) return false;
    for (let i = 2; i <= Math.sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}
for (let i = 0; i < n; i++) {

}
function main() {
    let a = [];
    let n;
    rl.question('nhap n: ', function (cin) {
        n = cin;
        for (let i = 0; i < n; i++) {
            let x;
            rl.question('nhap x: ', function (scandf) {
                x = scandf;
                a.push(x);
            })
        }
        console.log('mnag a: ', a);
    })
}
main();
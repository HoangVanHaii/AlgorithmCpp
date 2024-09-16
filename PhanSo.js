const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

function cin(input) {
    return new Promise(resolve => rl.question(input, resolve));
}
function gcd(a, b) {
    while (b != 0) {
        let tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
class PhanSo {
    constructor(tu, mau) {
        this.tu = parseInt(tu);
        this.mau = parseInt(mau);
    }
    cout() {
        console.log(this.tu, '/', this.mau);
    }
    getTu() {
        return this.tu;
    }
    getMau() {
        return this.mau;
    }
    sum(x) {
        let tuMoi = this.tu * x.mau + this.mau * x.tu;
        let MauMoi = this.mau * x.mau;
        let uc = gcd(tuMoi, MauMoi);
        tuMoi /= uc;
        MauMoi /= uc;
        return new PhanSo(tuMoi, MauMoi);
    }

}

async function nhap(x) {
    let tu = await cin(`nhap tu so ${x}: `);
    let mau = await cin('nhap mau so ', x, ': ');
    return new PhanSo(tu, mau);
}

async function main() {
    let ps1 = await nhap('PS1 ');
    let ps2 = await nhap('PS2 ');
    console.log(ps1, ps2);
    ps1.cout();
    ps2.cout();

    let pstong = ps1.sum(ps2);
    pstong.cout();
    rl.close();
}

main();
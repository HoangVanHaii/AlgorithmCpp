const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function cin(input) {
    return new Promise(resolve => rl.question(input, answer => resolve(answer)));
}

class Vector {
    constructor() {
        this.arr = [];
    }
    push_back(x) {
        this.arr.push(x);
    }
    sort() {
        let a = [...this.arr]
        for (let i = 0; i < a.length; i++) {
            for (let j = i + 1; j < a.length; j++) {
                if (a[i] > a[j]) {
                    let tmp = this.arr[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
    }
    erase(x, y) {
        for (let i = 0; i < this.arr.length; i++) {
            if (i == x) {
                this.arr.splice(x, y);
            }
        }
    }

}
async function main() {
    let n = await cin('nhap so phan tu: ');
    let cnt = 0;
    let a = new Vector();
    while (n--) {
        cnt++;
        let x = await cin(`nhap phan tu thu ${cnt}: `);
        a.push_back(x);
    }
    a.sort();
    console.log(a);
    let pos = await cin('nhap vi tri muon xoa: ');
    let posdelete = await cin('nhap so phan tu muon xoa: ');
    a.erase(pos, posdelete);
    console.log(a);
    rl.close();
}
main(); 
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

function cin(input) {
    return new Promise(value => rl.question(input, value));
}
function MaxArr(arr) {
    let Max = arr[0];
    for (let i of arr) {
        if (Max < i) {
            Max = i;
        }
    }
    return Max;
}
function MaxArr2() {
    let Max = arguments[0];
    for (let i of arguments) {
        if (Max < i) {
            Max = i;
        }
    }
    return Max;
}
function SortArr(a) {
    let arr = [...a];
    for (let i = 0; i < arr.length - 1; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] < arr[j]) {
                let tmp = arr[i];
                arr[i] = a8rr[j];
                arr[j] = tmp;
            }
        }
    }
    return arr;
}
function OneOne(a) {
    let arr = [...a];
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == arr[i + 1]) {
            arr.splice(i, 1);
            i--;

        }
    }
    return arr;
}
function OneTwo(a) {
    let arr = [...a];
    for (let i = 1; i < arr.length; i++) {
        for (let j = i - 1; j >= 0; j--) {
            if (arr[i] == arr[j]) {
                arr.splice(i, 1);
                i--;
            }
        }
    }
    return arr;
}
async function main() {
    let arr = [];
    let n = await cin('nhap so phan tu: ');
    for (let i = 0; i < n; i++) {
        let x = await cin(`nhap phan tu thu ${i + 1} `);
        arr.push(x);
    }
    let arr2 = arr;
    let gitc = arr;
    console.log('mang ban dau', arr);
    console.log('mang da sort', SortArr(arr2));
    let a = OneTwo(arr);
    console.log('mang xoa pt trung k sort', a);
    let b = SortArr(arr2);
    console.log('mang da duoc sap xep: ', arr2);
    console.log('mang xoa pt trung bang SORT', OneOne(b));
    rl.close();
}
main();
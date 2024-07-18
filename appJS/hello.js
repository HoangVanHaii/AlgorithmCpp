const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function abc() {
    rl.question('Nhập mảng a: ', function(cin) {
        // Chuyển chuỗi đầu vào thành mảng
        let array = cin.split('\n');
        
        // Tính tổng các phần tử trong mảng
        let sum = 0;
        for (let i = 0; i < array.length; i++) {
            sum += parseInt(array[i]);
        }
        
        rl.question('Nhập mảng b:  ', function(scandf) {
            let b = scandf.split(' ');
            console.log('mảng a :', array,'\n');
            console.log('\nMảng b :', b);
            
            rl.close();
        });
    });
}

abc();

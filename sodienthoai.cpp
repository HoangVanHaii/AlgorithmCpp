#include<bits/stdc++.h>
using namespace std;
struct SoDienThoai{
    string so;
    int goiDen, goiDi;
};

void output(SoDienThoai x){
    cout << "{" << x.so << " " << x.goiDen << " " << x.goiDi << "}\n";
}
SoDienThoai timSoDienThoai(SoDienThoai arr[], string x, int n){
    for (int i = 0; i < n ; i++){
        if(arr[i].so == x){
            return arr[i];
        }
    }
}
SoDienThoai timSoGoiDenNhieuNhat(SoDienThoai arr[], int n){
    SoDienThoai Max = arr[0];
    for (int i = 0; i < n ; i++){
        if(arr[i].goiDen > Max.goiDen){
            Max = arr[i];
        }
    }
    return Max;
}
SoDienThoai timSogoiDiItNhat(SoDienThoai arr[], int n){
    SoDienThoai Min = arr[0];
    for (int i = 0; i < n ; i++){
        if(arr[i].goiDi < Min.goiDi){
            Min = arr[i];
        }
    }
    return Min;
}
int main(){
    int n;
    string x;
    cin >> n >> x;
    SoDienThoai arr[n];
    for(int i = 0 ; i < n ; i++){
        string so;
        int goiden, goidi;
        cin >> so >> goiden >> goidi;
        SoDienThoai tmp = {so, goiden, goidi};
        arr[i] = tmp;
    }
    SoDienThoai Maxgoiden = timSoGoiDenNhieuNhat(arr, n);
    SoDienThoai Mingoidi = timSogoiDiItNhat(arr, n);
    SoDienThoai timso = timSoDienThoai(arr, x, n);
    output(timso);
    output(Maxgoiden);
    output(Mingoidi);
    return 0;
}
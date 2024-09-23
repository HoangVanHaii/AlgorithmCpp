#include <bits/stdc++.h>
using namespace std;
template <class DataType>
void SelecSort(DataType a[], int n){
    for (int i = 0; i < n - 1; i++){
        int max = i;
        for (int j = i + 1; j < n; j++){
            if(a[j] > a[max]){
                max = j;
            }
        }
        if(max != i){
            swap(a[i], a[max]);
        }
    }
}


int main(){
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    int arr[n] = {65,97,39,57,65,25,77,92,37,87};
    // cout << "nhap cac phan tu cua mang:\n";
    // for (int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    SelecSort(arr, n);
    cout << "mang sau khi SelectSort:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    return 0;
}
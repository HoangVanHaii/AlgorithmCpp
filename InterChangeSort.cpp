#include <bits/stdc++.h>
using namespace std;
template <class DataType>
void interChangeSort(DataType a[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}


int main(){
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    int arr[n];
    cout << "nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    interChangeSort(arr, n);
    cout << "mang sau khi interChange:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    return 0;
}
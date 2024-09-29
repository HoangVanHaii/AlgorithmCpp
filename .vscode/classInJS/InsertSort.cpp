#include <bits/stdc++.h>
using namespace std;
template <class DataType>
void insertSort(DataType a[], int n){
    for (int i = 1; i < n ; i++){
        DataType k = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > k){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
}
void insertsort(int a[], int n){
    for(int i = 1 ; i < n; i++){
        int x = a[i];
        int j;
        for (j = i; j > 0 && a[j - 1] < x; j--){
            a[j] = a[j - 1];
        }
        a[j] = x;
    }
}
// 2 1 4 7 3

int main(){
    int n;
    cout << "nhap so phan tu: ";
    cin >> n;
    int arr[n];
    cout << "nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    insertsort(arr, n);
    cout << "mang sau khi insertSort:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    return 0;
}
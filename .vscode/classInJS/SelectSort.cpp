#include <bits/stdc++.h>
using namespace std;
template <class DataType>
void SelecSort(DataType a[], int n){
    for (int i = 0; i < n - 1; i++){
        int min = i;
        for (int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if(min != i){
            swap(a[i], a[min]);
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
    SelecSort(arr, n);
    cout << "mang sau khi SelectSort:\n";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << "  ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int a[], int n){
    for (int i = 0; i < n - 1; i ++){
        for (int j = n - 1; j > i;j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
            }
        }
    }
}
int main(){
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
         cin >> a[i] ;
    }

    bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
    return 0;
}
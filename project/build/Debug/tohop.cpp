#include<bits/stdc++.h>
using namespace std;
int n, k;
int x[100];
bool used[100] = {false};

void print(){
    for(int i = 1 ; i <= k; i++){
        cout << x[i] <<" ";
    }
    cout << endl;
}
void Try(int i){
    for(int j = x[i - 1] + 1; j <= n - k + i;j++){
        if(!used[j]){
            x[i] = j;
            if(i == k){
                print();
            }
            else { 
                Try(i+1);
            }
        }
    }
}
int main(){
    cin >> n >> k;
    Try(1);
    return 0;
}
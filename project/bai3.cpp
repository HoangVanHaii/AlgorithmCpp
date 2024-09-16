#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0 ; i < n; i++){
        cin>>a[i];
    }
    long long cnt =0 ;
    long long cnt1 = 0;
    for(int i = 0 ;i < n ; i++){
        if(a[i] % 2 == 0){
             return 0;
        }   
        if(a[i] % 2 == 1){
            while(a[i] != 0){
                int tmp = a[i] % 10;
                if(tmp % 2 == 0) cnt1++;
                else cnt++;
                a[i] /= 10;
            }
                 if(cnt > cnt1 ) cout << "YES"<< endl;
                else if(cnt <= cnt1)cout << "NO"<< endl;
        }
        cnt = 0;
        cnt1 = 0;
    }
   
    
    
}
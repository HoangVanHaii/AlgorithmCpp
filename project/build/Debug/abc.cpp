#include<bits/stdc++.h>
using namespace std;
char a[1000][1000];
int n, m;
void nhap(){
    cin >> n ;
    m = n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j  < m ; j++) {
            cin >> a[i][j];
        }
        
    }
}
bool check(string &a){
    string b = a;
    reverse(b.begin(), b.end());
    return b == a;
}

int cnt = 0;
set<string> s;
void Try(int i, int j,string sum){
    sum += a[i][j];
   if(i == n - 1 && j == n - 1){
       if(check(sum)){
            s.insert(sum);
           cnt++;
           return;
       }
   }
   if(i < n -1) Try(i + 1, j, sum);
   if(j < n - 1) Try(i , j + 1, sum);
   sum.pop_back();
}
int main(){
    nhap();
    Try(0,0,"");
    cout << s.size() << endl;
    for(auto i : s){
        cout << i << endl;
    }
    
    return 0;
}
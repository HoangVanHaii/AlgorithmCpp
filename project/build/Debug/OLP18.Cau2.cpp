#include<bits/stdc++.h>
using namespace std;
int n, m;
char a[1000][1000];
string s = "";
bool used[1000];
char x[1000];
int cnt = 0;

void nhap(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            s += a[i][j];
        }
    }
}
set<string> se;
void in(){
    
    string b = "";
    for(int i = 0;i < s.size() ; i++){
        b+=x[i];
    }
    se.insert(b);
}
void Try(int i){
    for(int j = 0 ; j < s.size(); j++){
        if(!used[j]){
            used[j] = true;
            x[i] = s[j];
            if(i == s.size() - 1){
                cnt++;
                in();
            }
            else Try(i + 1);
            used[j] = false;
        } 
    }
}
int main(){
    nhap();
    Try(0);
    cout << se.size() << endl;
    for(auto i : se) cout << i << endl;
    return 0;
    
}
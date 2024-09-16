/*Creator Hoang : Hai :_: */
#include<iostream>
#include<algorithm>

using namespace std;
string n;
char x[100], c, d;
bool used[100];
void khoitao(){
    sort(n.begin(), n.end());
    c = n[0];
    d = n[n.size() - 1];
}
void in(){
    for(int i = 0  ; i < n.size() ; i++){
        cout << x[i] ;
    }
    cout << endl;
}
void Try(int i){
    for(char j = c; j <= d ; j++){
        if(!used[j]){
            x[i] = j;
            used[j] = true;
            if(i == n.size() - 1){
                in();
            }
            else Try(i + 1);
            used[j] = false;
        }
    }
}
int main(){
    cin >> n;    
    khoitao();
    Try(0);
    return 0;
}
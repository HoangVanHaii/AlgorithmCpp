#include<bits/stdc++.h>
using namespace std;
bool check(int a){
    string b = to_string(a);
    string c = b;
    reverse(c.begin(), c.end());
    return c == b;
}
int main(){
    // ifstream cin("vector_inp.txt");
    // ofstream cout("vector_out.txt");
    vector <int> a;
    int x;
    vector <int> sodoi;
    vector <int> sothuong;

    while(cin >> x){
        if(x == -1) break;
        a.push_back(x);
        if(check(x)){
            sodoi.push_back(x);
        }
        else sothuong.push_back(x);
    }
    sort(sodoi.begin(), sodoi.end());
    sort(sothuong.begin(), sothuong.end());

    int tongDoi = 0, tongThuong = 0;
    for(auto i : sothuong) tongThuong+=i;
    for(auto i : sodoi) tongDoi+=i;
    cout << sodoi[sodoi.size() - 1]<<" " << tongDoi;
    cout << endl;
    for(int i = sodoi.size() - 1; i >= 0 ; i--){
        cout << sodoi[i] << " ";
    }
    cout << endl;
    cout << sothuong[0] << " " << tongThuong << endl;
    for(auto i : sothuong) cout << i << " ";
    return 0; 
}
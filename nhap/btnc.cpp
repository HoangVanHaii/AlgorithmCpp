#include<bits/stdc++.h>
using namespace std;
 
map<int, int> mp;
void readGraph(string fn){
    ifstream f(fn);
    if(f.is_open()){
        int x, y, z;
        while(f >> x >> y >> z){
            mp[x]++;
            mp[y]++;
        }
        f.close();

    }
    else
        cout << " khong mo dc file";
}
int main(){
    readGraph("dothi.txt");
    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }
    int Max = -1;
    for(auto i: mp){
        Max = max(i.second, Max);
    }
    cout <<"dinh co bac lon nhat la: ";
    for(auto i : mp){
        if(i.second == Max){
            cout << i.first << " ";
        }        
    }
    return 0;
}
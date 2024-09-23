#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int Max = 100;
struct Graph{
    int sodinh;
    int a[Max][Max];
};

void Read_Graph(string fn, Graph &a){
    ifstream fi(fn);
    if(fi.is_open()){
        fi >> a.sodinh;
        for (int i = 0; i < a.sodinh; i++){
            for (int j = 0; j < a.sodinh; j++){
                fi >> a.a[i][j];
            }
        }
        fi.close();
    }
    else {
        cout << "khong mo dc file!";
    }
}
int mienLienthong = 0;
int visited[Max] = {0};
void visit(Graph &a, int i, int &mienLienthong){
    visited[i] = mienLienthong;
    for (int j = 0; j < a.sodinh;j++){
        if(visited[j] == 0 && a.a[i][j] != 0){
            visit(a, j, mienLienthong);
        }
    }
}
void xetTinhLienThong(Graph &a){
    for (int j = 0; j < a.sodinh;j++){
        if(visited[j] == 0){
            mienLienthong++;
            visit(a, j, mienLienthong);
        }
    }
}
void inThanhPhanLienThong(string fn, Graph &a){
    ofstream fo(fn);
    xetTinhLienThong(a);
    if(mienLienthong == 1){
        fo << "LIENTHONG";
        return;
    }
    fo << "KHONGLIENTHONG\n";
    vector<vector<int>> v;
    fo << mienLienthong << endl;
    for (int i = 1; i <= mienLienthong;i++){
        vector<int> tmp;
        for (int j = 0; j < a.sodinh;j++){
            if(visited[j] ==i ){
                tmp.push_back(j);
            }
        }
        v.push_back(tmp);
        tmp.clear();
    }
    for (int i = 0; i < v.size();i++){
        for (int j = i + 1; j < v.size();j++){
            if(v[i].size() > v[j].size()){
                swap(v[i], v[j]);
            }
        }
    }
    for(auto i : v){
        for(int j : i){
            fo << j <<" ";
        }
        fo << endl;
    }

}
int main(){
    Graph a;
    Read_Graph("input.txt", a);    
    inThanhPhanLienThong("output.txt",a);
    return 0;
}
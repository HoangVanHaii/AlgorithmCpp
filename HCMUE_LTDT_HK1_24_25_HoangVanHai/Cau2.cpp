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
void inThanhPhanLienThong( Graph &a){
    xetTinhLienThong(a);
    vector<vector<int>> v;
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
    cout << "So canh toi thieu de do thi lien thong: " << mienLienthong - 1 << endl;
    for (int i = 0; i < v[1].size();i++){
        for (int j = 0; j < v[0].size();j++){
            cout << v[1][i] << " - " << v[0][j] << endl;
        }
    }
}
int main(){
    Graph a;
    Read_Graph("input.txt", a);    
    inThanhPhanLienThong(a);
    return 0;
}
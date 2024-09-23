#include<bits/stdc++.h>
using namespace std;
const int Max = 100;
struct QUEUE {
    int size;
    int A[Max];
};

void KhoiTao(QUEUE& q) { q.size = 0; }
bool Them(int k, QUEUE& q) {
    if (q.size + 1 > Max) return false;
    q.A[q.size] = k;
    q.size++;
    return true;
}

bool KiemTraRong(QUEUE q) {
    return (q.size == 0);
}

bool Lay(int &v, QUEUE& q) {
    if (KiemTraRong(q)) return false;
    v = q.A[0];
    for (int i = 0; i < q.size - 1; i++) {
        q.A[i] = q.A[i + 1];
    }
    q.size--;
    return true;
}

struct Graph{
    int sodinh;
    int a[Max][Max];
};
void readGraph(string fn, Graph &a){
    ifstream f;
    f.open(fn);
    if(f.is_open()){
        f >> a.sodinh;
        for (int i = 0; i < a.sodinh;i++){
            for (int j = 0; j < a.sodinh; j++){
                f >> a.a[i][j];
            }
        }
        f.close();
    }
    else
        cout << "khong mo duoc file";
}
vector<bool> visited(Max, false);

void BFS(int i, Graph a){
    QUEUE q;
    Them(i, q);
    visited[i] = true;
    while(!KiemTraRong(q)){
        int key;
        Lay(key, q);
        cout << key << " ";
        for (int j = 0; j < a.sodinh; j++){
            if(!visited[j] && a.a[key][j] != 0){
                visited[j] = true;
                Them(j, q);
            }
        }
    }
}
int main(){
    Graph a;
    readGraph("dothi.txt", a);
    BFS(0, a);
    return 0;
}
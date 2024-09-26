#include <bits/stdc++.h>
using namespace std;
const int Max = 100;

struct Queue {
    int size;
    int A[Max];
};

void KhoiTao(Queue& q) { 
    q.size = 0;
}
bool Them(int k, Queue& q) {
    if (q.size + 1 > Max) {
        return false;
    }
    q.A[q.size] = k;
    q.size++;
    return true;
}

bool KiemTraRong(Queue q) {
    return (q.size == 0);
}

bool Lay(int &v, Queue& q) {
    if (KiemTraRong(q)) return false;
    v = q.A[0];
    for (int i = 0; i < q.size - 1; i++) {
        q.A[i] = q.A[i + 1];
    }
    q.size--;
    return true;
}

struct Graph {
    int sodinh;
    int a[Max][Max];
};

void Read_graph(const string& f, Graph& g) {
    ifstream fs(f);
    if (fs.is_open()) {
        fs >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                fs >> g.a[i][j];
            }
        }
        fs.close();
    } else {
        cout << "Khong mo duoc file" << endl;
    }
}
int visited[Max] = {0};

void BFS(int i, Graph a, string fn){
    ofstream fo(fn);
    
    Queue q;
    Them(i, q);
    visited[i] = 1;
    while(!KiemTraRong(q)){
        int key;
        Lay(key, q);
        fo << key + 1 << " ";
        for (int j = 0; j < a.sodinh; j++){
            if(!visited[j] && a.a[key][j] != 0){
                visited[j] = 1;
                Them(j, q);
            }
        }
    }
}
int main(){
    Graph a;
    Read_graph("dothi.txt", a);
    BFS(0, a, "output.txt");
    return 0;
}
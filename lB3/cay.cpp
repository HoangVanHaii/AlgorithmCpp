#include <iostream>
#include <fstream>
#include <iomanip> 
#include <queue>
using namespace std;

const int MAX = 100;
int mienLienThong, visited[MAX],luuvet[MAX];

struct GRAPH {
    int sodinh, a[MAX][MAX];
};

struct QUEUE {
    int size;
    int A[MAX];
};

void KhoiTao(QUEUE& q) { q.size = 0; }
bool Them(int k, QUEUE& q) {
    if (q.size + 1 > MAX) return false;
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

void readfile(const string& fn, GRAPH& g) {
    ifstream f(fn);
    if (f.is_open()) {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                f >> g.a[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Không mở được file" << endl;
    }
}
void BFS(int s, GRAPH& g) {
    // QUEUE q;
    queue<int> q;
    q.push(s);
    visited[s] = 1; 
    while (!q.empty()) {
        int key = q.front();
        q.pop();
        cout << key << " ";
        for (int i = 0; i < g.sodinh; i++) {
            if (visited[i] == 0 && g.a[key][i] != 0) {
                visited[i] = 1;
                luuvet[i] = key;
                q.push(i);
            }
        }
    }
}

void duyetBFS(int s, int f, GRAPH g) {
    for (int i = 0; i < g.sodinh; i++) {
        visited[i] = 0;
        luuvet[i] = -1;
    }
    BFS(s, g);
    // if(visited[f] == 0){
    //     cout << "khong co duong di den " << f;
    // }
    // else {
    //     int current = f;
    //     while(current != -1) {
    //         cout << current << " ";
    //         current = luuvet[current];
    //     }
    // }
}



int main() {
    GRAPH g;
    readfile("dothi.txt", g); 
    duyetBFS(0, 4, g);

        return 0;
}
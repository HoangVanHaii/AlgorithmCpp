#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
const int Max = 100;
struct graph {
    int sodinh;
    int a[Max][Max];
    int Luuvet[Max];
};
int visit[Max] = { 0 };
struct Queue {
    int size;
    int a[Max];
};
void KhoiTao(Queue& q) {
    q.size = 0;
}
bool Them(int k, Queue& q) {
    if (q.size + 1 > Max) return false;
    q.a[q.size] = k;
    q.size++;
    return true;
}
bool KiemTraRong(Queue q) {
    return (q.size == 0);
}
bool Lay(int& v, Queue& q) {
    if (KiemTraRong(q)) return false;
    v = q.a[0];
    for (int i = 0; i < q.size - 1; i++) {
        q.a[i] = q.a[i + 1];
    }
    q.size--;
    return true;
}
void BFS(int j, graph& g, string fn) {
    ofstream f(fn);
    Queue q;
    KhoiTao(q);
    Them(j, q);
    visit[j] = 1;
    while (!KiemTraRong(q)) {
        int s;
        Lay(s, q);
        f << s + 1 << " ";
        for (int i = 0; i < g.sodinh; i++) {
            if (visit[i] == 0 && g.a[s][i] != 0) {
                Them(i, q);
                visit[i] = 1;
                g.Luuvet[i] = s;
            }
        }
    }
}
void readgraph(string fn, graph& g) {
    ifstream f;
    f.open(fn);
    if (f.is_open()) {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++)
            for (int j = 0; j < g.sodinh; j++)
                f >> g.a[i][j];
        f.close();
    }
    else {
        cout << "khong mo duoc file";
    }
}
int main() {
    graph a;
    readgraph("dothi.txt", a);
    BFS(0, a, "output.txt");
}
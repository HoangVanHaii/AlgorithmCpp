#include <bits/stdc++.h>
using namespace std;
const int Max = 100;

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
        cout << "Không mở được file" << endl;
    }
}

void print_graph(Graph& g) {
    cout << "Số đỉnh: " << g.sodinh << endl;
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            cout << setw(4) << g.a[i][j];
        }
        cout << endl;
    }
}

int visited[Max];
int mienLienThong = 1;
void visit(Graph &g, int i, int mienLienThong) {
    visited[i] = mienLienThong;
    for (int j = 0; j < g.sodinh; j++) {
        if (!visited[j] && g.a[i][j] != 0) {
            visit(g, j,mienLienThong);
        }
    }
}

void xetTinhLienThong(Graph &g) {
    for (int i = 0; i < g.sodinh;i++){
        visited[i] = 0;
    }
    for (int i = 0; i < g.sodinh; i++) {
        if (visited[i] == 0) {
            visit(g, i, mienLienThong++);
        }
    }
    // return count;
}
void inThanhphanLienThong(Graph &g){
    cout << "So mien lien thong " << mienLienThong - 1 << endl;

    for(int i = 1;i <= mienLienThong; i++){
        for (int j = 0; j < g.sodinh;j++){
            if(visited[j] == i){
                cout  << j <<" ";
            }
        }
        cout << endl;
    }
}
int main() {
    Graph a;
    Read_graph("dothi.txt", a);
    xetTinhLienThong(a);
    inThanhphanLienThong(a);
    return 0;
}

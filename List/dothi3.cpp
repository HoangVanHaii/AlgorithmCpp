#include <bits/stdc++.h>
using namespace std;
const int Max = 100;

struct Graph {
    int sodinh;
    int a[Max][Max];
};

void Read_graph(string f, Graph& g) {
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

int main() {
    Graph a;
    Read_graph("dothi3.txt", a);
    print_graph(a);
    return 0;
}

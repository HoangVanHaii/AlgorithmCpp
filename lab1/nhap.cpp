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

void print_graph(const Graph& g) {
    cout << "So dinh: " << g.sodinh << endl;
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            cout << setw(4) << g.a[i][j];
        }
        cout << endl;
    }
}
void Save_graph(string fn,const Graph &a){
    ofstream of(fn);

}
vector<int> lienthong;
void visit(Graph &g, int i, vector<bool> &visited) {
    queue<int> q;
    q.push(i);
    visited[i] = true;
    

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        lienthong.push_back(u);
        for (int j = 0; j < g.sodinh; j++) {
            if (g.a[u][j] != 0 && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
    
}

vector<int> visit2(Graph &a, int i, vector<bool> &visited){
    queue<int> q;
    q.push(i);
    visited[i] = true;
    vector<int> lt;

    while(!q.empty()){
        int key = q.front();
        q.pop();
        lt.push_back(key);
        for (int j = 0; j < a.sodinh;j++){
            if(!visited[j] && a.a[key][j] != 0){
                visited[j] = true;
                q.push(j);
            }
        }
    }
    return lt;
}
void output(Graph a){
    vector<bool> visited(a.sodinh, false);
    for (int i = 0; i < a.sodinh;i++){
        if(!visited[i]){
            vector<int> result = visit2(a, i, visited);
            for(int i: result){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}
void inThanhphanLienThong(string fn, Graph &g) {
    ofstream of(fn);
    vector<bool> visited(g.sodinh, false);
    int lienThongCount = 0;

    for (int i = 0; i < g.sodinh; i++) {
        if (!visited[i]) {
            cout << "Thanh phan lt: ";
            visit(g, i, visited);
            for(int i: lienthong){
                // cout << i << " ";
                of << i << " ";
            }
            lienthong.clear();
            cout << endl;
        }
    }
}

int main() {
    Graph a;
    Read_graph("dothi.txt", a);
    print_graph(a);
    inThanhphanLienThong("output.txt", a);

    return 0;
}

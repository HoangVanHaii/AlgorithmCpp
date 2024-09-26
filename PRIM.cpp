#include<iostream>
#include<fstream>
#include<vector>
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
struct Edge{
    int u, v, w;
};

struct Graph{
    int sodinh;
    int a[Max][Max];
    Edge T[Max];
    int sumT;
    vector <Edge> e;
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

Edge findminEdge(Edge arr[], int n) {
    Edge canhnhonhat;
    canhnhonhat.w = -1;  
    for (int i = 0; i < n; i++) {
        if (canhnhonhat.w == -1 || arr[i].w < canhnhonhat.w) {
            canhnhonhat = arr[i];
        }
    }
    
    return canhnhonhat;
}
int visited[Max] = {0};
void Prim(Graph &a){
    int nT = 0;
    visited[0] = 1;
    
    while(nT < a.sodinh - 1){
        Edge arr[Max];
        int n = 0;
        int min = -1;
        for (int i = 0; i < a.sodinh;i++){
            if(visited[i] == 0){
                for (int j = 0; j < a.sodinh;j++){
                    if(visited[j] == 1 && a.a[i][j] != 0){
                        Edge e = {i, j, a.a[i][j]};
                        arr[n] = e;
                        n++;
                    }
                }
                
            }
            
        }
        Edge canhnhonnhat;
        canhnhonnhat = findminEdge(arr, n);
        a.T[nT] = canhnhonnhat;
        nT++;
        visited[canhnhonnhat.u] = 1;

    }
    a.sumT = 0;
    for (int i = 0; i < nT;i++){
        a.sumT += a.T[i].w;
    }
}
Edge timCanhMin(vector<Edge> vt){
    Edge canhmin = vt[0];
    for (int i = 0; i < vt.size();i++){
        if(vt[i].w < canhmin.w){
            canhmin = vt[i];
        }
    }
    return canhmin;
}
void prim1(Graph &a){
    visited[0] = 1;

    while(a.e.size() < a.sodinh - 1){
        vector<Edge> DsCanh;
        for (int i = 0; i < a.sodinh;i++){
            if(visited[i] == 0){
                for (int j = 0; j < a.sodinh;j++){
                    if(visited[j] == 1 && a.a[i][j] != 0){
                        Edge tmp = {i, j, a.a[i][j]};
                        DsCanh.push_back(tmp);
                    }
                }
            }
        }
        Edge canhmin = timCanhMin(DsCanh);
        a.e.push_back(canhmin);
        visited[canhmin.u] = 1;
    }
    a.sumT = 0;
    for (int i = 0; i < a.e.size(); i++){
        a.sumT += a.e[i].w;
    }
    int b = a.sumT;
}

void printSpanningTree(Graph a){
    for (int i = 0; i < a.e.size(); i++) {
        cout << a.e[i].v + 1 << " " << a.e[i].u + 1<< endl;
    }
    cout << a.sumT;
}
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
    readGraph("prim.txt", a);
    prim1(a);
    printSpanningTree(a);
    return 0;
}
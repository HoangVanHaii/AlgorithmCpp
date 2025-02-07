#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;
const int FOUND = 1;
const int NOT_FOUND = 0;

struct GRAPH {
    int sodinh;
    int a[MAX][MAX];
};

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

int visit(int u, int visited[], int& count, int& flag, int path[], GRAPH g, bool& check) {
    if (flag == FOUND) return flag;

    for (int v = 0; v < g.sodinh; v++) {
        if (visited[v] == 0 && g.a[u][v] != 0) {
            visited[v] = 1;
            path[count] = v;
            count++;
            if (count == g.sodinh && g.a[v][path[0]] != 0) {
                flag = FOUND;
                return flag;
            }
            visit(v, visited, count, flag, path, g, check);
            if (flag == NOT_FOUND) {
                visited[v] = 0;
                count--;
            }
        }
    }
    if (count == g.sodinh && flag == NOT_FOUND) {
        check = true;
    }

    return flag;
}

int dfsHamilton(int path[], GRAPH g, bool& check) {
    int start = 0;
    int flag = NOT_FOUND;
    int visited[MAX] = { 0 };
    int count = 0;
    path[count] = start;
    count++;
    visited[start] = 1;

    flag = visit(start, visited, count, flag, path, g, check);

    if (flag == FOUND) {
        return FOUND;
    }

    return NOT_FOUND;
}

int main() {
    GRAPH g;
    readfile("g4.txt", g);
    cout << "G4\n";
    int path[MAX];
    bool check = false;

    int result = dfsHamilton(path, g, check);

    if (result == FOUND) {
        cout << "Co Chu trinh Hamilton \nCo duong di Hamilton\n";
        for (int i = 0; i < g.sodinh; i++) {
            cout << path[i]  << "  ";
        }
        cout << path[0] << endl;
    }
    else if (check) {
        cout << "Khong co Chu trinh Hamilton \nCo duong di Hamilton \n ";
        for (int i = 0; i < g.sodinh; i++) {
            cout << path[i]  << "  ";
        }
        cout << endl;
    }
    else {
        cout << "Khong co Chu trinh Hamilton \nKhong co duong Hamilton." << endl;
    }

    return 0;
}

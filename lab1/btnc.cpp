#include <bits/stdc++.h>
using namespace std;
const int Max = 100;
struct Canh
{
    int dinhdau;
    int dinhcuoi;
    int trongso;
};
struct Graph
{
    vector<Canh> G;
};
void readGraph(string fn, Graph &a)
{
    ifstream f;
    f.open(fn);

    if (f.is_open())
    {
        Canh tmp;
        while (f >> tmp.dinhdau >> tmp.dinhcuoi >> tmp.trongso)
        {
            a.G.push_back(tmp);
        }
        f.close();
    }
    else
        cout << "khog mo dc file!!";
}

void printGr(Graph &g)
{
    cout << "so canh: ";
    cout << g.G.size() << endl;
    map<int, int> mp;

    for (int i = 0; i < g.G.size(); i++)
    {
        mp[g.G[i].dinhdau]++;
        mp[g.G[i].dinhcuoi]++;
    }
    int Max = 0;
    int BacMax = 0;

    for (auto i : mp)
    {
        // cout << i.first << "  " << i.second << endl;
        if (Max < i.second)
        {
            Max = i.second;
            BacMax = i.first;
        }
    }
    cout << "Dinh co bac cao nhat: " << BacMax << endl;
}
int main()
{
    Graph a;
    readGraph("dothi.txt", a);
    printGr(a);
    return 0;
}
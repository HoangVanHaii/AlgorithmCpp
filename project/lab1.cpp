#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
struct GRAPH
{
    int sodinh;
    int a[MAX][MAX];
};

void readGRAPH(string fn, GRAPH &g)
{
    ifstream f;
    f.open(fn);
    if (f.is_open())
    {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++)
        {
            for (int j = 0; j < g.sodinh; j++)
            {
                f >> g.a[i][j];
            }
        }
        f.close();
    }
    else
        cout << "khong mo dc file!!!";
}
void printGRAPH(GRAPH g)
{
    cout << "so dinh cua do thi: " << g.sodinh << endl;
    for (int i = 0; i < g.sodinh; i++)
    {
        for (int j = 0; j < g.sodinh; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << endl;
    }
}

bool KTVoHuong(GRAPH g)
{
    for (int i = 0; i < g.sodinh; i++)
    {
        for (int j = 0; j < g.sodinh; j++)
        {
            if (g.a[i][j] != g.a[j][i])
                return false;
        }
    }
    return true;
}
int DemSoCanh(GRAPH g)
{
    int cnt = 0;
    for (int i = 0; i < g.sodinh; i++)
    {
        for (int j = 0; j < g.sodinh; j++)
        {
            if (g.a[i][j] != 0)
                cnt++;
        }
    }
    if (KTVoHuong(g))
    {
        return cnt / 2;
    }
    else
    {
        return cnt;
    }
}

int Canh_max(GRAPH g)
{
    int Max = 0;

    for (int i = 0; i < g.sodinh; i++)
    {
        for (int j = 0; j < g.sodinh; j++)
        {
            if (Max < g.a[i][j])
            {
                Max = g.a[i][j];
            }
        }
    }
    return Max;
}
vector<int> deg(GRAPH g)
{
    vector<int> a;
    for (int i = 0; i < g.sodinh; i++)
    {
        int cnt = 0;
        for (int j = 0; j < g.sodinh; j++)
        {
            if (g.a[i][j] != 0)
            {
                cnt++;
            }
        }
        a.push_back(cnt);
    }
    return a;
}
void Bac_max(GRAPH g)
{
    vector<int> Bac = deg(g);
    int Max = 0;
    int Min = 999;
    for (auto i : Bac)
    {
        Max = max(Max, i);
        Min = min(Min, i);
    }
    cout << "\nDinh co Bac lon nhat la: ";
    for (int i = 0; i < Bac.size(); i++)
    {
        if (Bac[i] == Max)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\nDinh co Bac be nhat la: ";
    for (int i = 0; i < Bac.size(); i++)
    {
        if (Bac[i] == Min)
        {
            cout << i + 1 << " ";
        }
    }

    cout << "\nDinh co Bac chan la: ";
    for (int i = 0; i < Bac.size(); i++)
    {
        if (Bac[i] % 2 == 0)
        {
            cout << i + 1 << " ";
        }
    }
    cout << "\nDinh co Bac le la: ";
    for (int i = 0; i < Bac.size(); i++)
    {
        if (Bac[i] % 2 == 1)
        {
            cout << i + 1 << " ";
        }
    }
}
// int timDinhTreo(GRAPH a)
// {
//     int check = 0;
//     vector<int> vt = deg(a);
// }
int main()
{
    GRAPH a;
    readGRAPH("Dothi.txt", a);
    cout << endl;
    printGRAPH(a);

    // if (KTVoHuong(a))
    // {
    //     cout << "Do thi la vo huong\n";
    // }
    // else
    //     cout << "Do thi la huu huong\n";
    // int SoCanh = DemSoCanh(a);
    // cout << "So canh cua do thi la: " << SoCanh << endl;

    // int Max = Canh_max(a);
    // cout << "Canh dai nhat cua do thi la: " << Max << endl;

    // // bt2
    // vector<int> Bac = deg(a);
    // cout << "\nBac cua cac dinh lan luot la: ";
    // for (auto i : Bac)
    // {
    //     cout << i << " ";
    // }
    // // bt3;
    // Bac_max(a);

    return 0;
}
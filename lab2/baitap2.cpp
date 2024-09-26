#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;
const int MAX = 100;

struct Graph{
    int sodinh;
    int a[MAX][MAX];
};

void readGraph(string fn, Graph &a) {
    ifstream f;
    f.open(fn);
    f >> a.sodinh;
    if (f.is_open()) {
        for (int i = 0; i < a.sodinh; i++) {
            for (int j = 0; j < a.sodinh; j++) {
                f >> a.a[i][j];
            }
        }
        f.close();
    }
    else{
        cout << "khong mo dc file!!";
    }
}
void printGraph(Graph a) {
    for (int i = 0; i < a.sodinh; i++) {
        for (int j = 0; j < a.sodinh; j++) {
            cout << setw(4) << a.a[i][j] << " ";
        }
        cout << endl;
    }
}
bool KTVoHuong(Graph a) {
    for (int i = 0; i < a.sodinh; i++) {
        for (int j = 0; j < a.sodinh; j++) {
            if (a.a[i][j] != a.a[j][i])
                return false;
        }
    }
    return true;
}
int DemSoCanh(Graph a) {
    int SoCanh = 0;
    for (int i = 0; i < a.sodinh; i++) {
        for (int j = 0; j < a.sodinh; j++) {
            if (a.a[i][j] != 0)
                SoCanh++;
        }
    }
    if (KTVoHuong(a)) {
        return SoCanh / 2;
    }
    else
        return SoCanh;
}
vector<pair<int, int>> CanhMax(Graph a) {
    vector<pair<int, int>> Canh;
    int Max = 0;
    for (int i = 0; i < a.sodinh; i++) {
        for (int j = 0; j < a.sodinh; j++) {
            if (Max < a.a[i][j]) {
                Max = a.a[i][j];
            }
        }
    }
    for (int i = 0; i < a.sodinh; i++) {
        for (int j = 0; j < a.sodinh; j++) {
            if (Max == a.a[i][j]) {
                Canh.push_back({i + 1, j + 1});
            }
        }
    }
    return Canh;
}
vector<pair<int, int>> BanRa_BanVao(Graph a){
    vector<pair<int, int>> BanCuaDinh;
    for (int i = 0; i < a.sodinh; i++) {
        int BanRa = 0;
        int BanVao = 0;
        for (int j = 0; j < a.sodinh; j++) {
            if (a.a[i][j] == 0 && a.a[j][i] != 0){
                BanVao++;
            }
            if (a.a[i][j] != 0 && a.a[j][i] == 0){
                BanRa++;
            }
        }
        BanCuaDinh.push_back({BanRa, BanVao});
    }
    return BanCuaDinh;
}
vector<int> BacCuaDinh(Graph a) {
    vector<int> Bac;
    for (int i = 0; i < a.sodinh; i++) {
        int count = 0;
        for (int j = 0; j < a.sodinh; j++) { 
            if (!KTVoHuong(a)) {
                if (a.a[i][j] != 0 || (a.a[i][j] == 0 && a.a[j][i] != 0))
                    count++;
            }
            else{
                if (a.a[i][j] != 0)
                    count++;
            }
        }
        Bac.push_back(count);
    }
    return Bac;
}
vector<int> BacLonNhat(Graph a) {
    vector<int> Bac = BacCuaDinh(a);
    vector<int> BacMax;
    int Max = 0;
    for (int i = 0; i < Bac.size(); i++) {
        Max = max(Max, Bac[i]);
    }
    for (int i = 0; i < Bac.size(); i++) {
        if (Max == Bac[i])
            BacMax.push_back(i + 1);
    }
    return BacMax;
}
vector<int> BacBeNhat(Graph a) {
    vector<int> Bac = BacCuaDinh(a);
    vector<int> BacMin;
    int Min = 999;
    for (int i = 0; i < Bac.size(); i++){
        Min = min(Min, Bac[i]);
    }
    for (int i = 0; i < Bac.size(); i++) {
        if (Min == Bac[i])
            BacMin.push_back(i + 1);
    }
    return BacMin;
}
vector<int> DinhBacChan(Graph a){
    vector<int> Bac = BacCuaDinh(a);
    vector<int> BacChan;
    for (int i = 0; i < Bac.size(); i++) {
        if (Bac[i] % 2 == 0)
            BacChan.push_back(i + 1);
    }
    return BacChan;
}
vector<int> DinhBacLe(Graph a){
    vector<int> Bac = BacCuaDinh(a);
    vector<int> BacLe;
    for (int i = 0; i < Bac.size(); i++) {
        if (Bac[i] % 2 != 0)
            BacLe.push_back(i + 1);
    }
    return BacLe;
}
vector<int> TimDinhTreo(Graph a){
    vector<int> DinhTreo;
    vector<int> Bac = BacCuaDinh(a);
    for (int i = 0; i < Bac.size(); i++) {
        if (Bac[i] == 1)
            DinhTreo.push_back(i + 1);
    }
    return DinhTreo;
}
vector<int> TimDinhCoLap(Graph a){
    vector<int> DinhCoLap;
    vector<int> Bac = BacCuaDinh(a);
    for (int i = 0; i < Bac.size(); i++) {
        if (Bac[i] == 1)
            DinhCoLap.push_back(i + 1);
    }
    return DinhCoLap;
}
int main(){
    Graph a;
    readGraph("dothi.txt", a);
    // 1
    cout << "1."
         << ((KTVoHuong(a)) ? "Do thi vo huong\n" : "Do thi huu huong\n");
    // 2
    int SoCanh = DemSoCanh(a);
    cout << "2.So canh cua do thi la: " << SoCanh << endl;
    // 3
    vector<pair<int, int>> Canh = CanhMax(a);
    cout << "3.Canh co trong so lon nhat la: ";
    for (pair<int, int> i : Canh) {
        cout << i.first << i.second << endl;
    }
    // 4
    cout << "4.\n";
    if (!KTVoHuong(a)) {
        vector<pair<int, int>> BanCuaDinh = BanRa_BanVao(a);
        int j = 1;
        for (pair<int, int> i : BanCuaDinh) {
            cout << "Dinh " << j << ": Ban bac Ra: " << i.first << "  Ban bac Vao: " << i.second << endl;
            j++;
        }
    }
    else {
        cout << "Khong co ban bac ra, ban bac vao!!!\n";
    }
    // 5
    vector<int> LonNhat = BacLonNhat(a);
    vector<int> BeNhat = BacBeNhat(a);
    vector<int> BacChan = DinhBacChan(a);
    vector<int> BacLe = DinhBacLe(a);
    cout << "5.\nDinh co bac lon nhat la: ";
    for (int i : LonNhat) {
        cout << i << " ";
    }
    cout << "\nDinh co bac be nhat la: ";
    for (int i : BeNhat) {
        cout << i << " ";
    }
    cout << "\nDinh bac chan la: ";
    for (int i : BacChan) {
        cout << i << " ";
    }
    cout << "\nDinh bac le la: ";
    for (int i : BacLe) {
        cout << i << " ";
    }
    // 6
    cout << "\n6.";
    vector<int> DinhTreo = TimDinhTreo(a);
    if (!DinhTreo.empty()) {
        cout << "\nDinh treo cua do thi: ";
        for (int i : DinhTreo) {
            cout << i << " ";
        }
    }
    else {
        cout << "\nKhong co dinh treo";
    }
    vector<int> DinhCoLap = TimDinhCoLap(a);
    if (!DinhCoLap.empty()) {
        cout << "\nDinh co lap cua do thi: ";
        for (int i : DinhCoLap) {
            cout << i << " ";
        }
    }
    else {
        cout << "\nKhong co dinh co lap";
    }
    
    return 0;
}
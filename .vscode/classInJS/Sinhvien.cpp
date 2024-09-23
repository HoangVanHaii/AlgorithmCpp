#include <iostream>
#include <List>

using namespace std;
class SinhVien
{
private:
    int Mssv;
    string Ten;

public:
    SinhVien(int maso, string ten)
    {
        Mssv = maso;
        Ten = ten;
    }
    void output()
    {
        cout << Ten << " " << Mssv << endl;
    }
};

int main()
{
    list<SinhVien> the_list;
    SinhVien a = {123, "hoang van a"};
    SinhVien b = {124, "Hoang van b"};
    SinhVien c = {125, "Hoang van c"};
    SinhVien d = {126, "Hoang van d"};
    the_list.push_back(a);
    the_list.push_back(b);
    the_list.push_back(c);
    the_list.push_front(d);

    for (list<SinhVien>::iterator it = the_list.begin(); it != the_list.end(); it++)
    {
        it->output();
    }
    return 0;
}
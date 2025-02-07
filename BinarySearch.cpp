#include <bits/stdc++.h>
using namespace std;
class Key {
    private:
        int value;

    public:
        Key() {
            value = 0;
        };
        Key(int _value) {
            value = _value;
        }
        friend bool operator>(Key a, Key b) {
            return a.value > b.value;
        }
        friend bool operator<(Key a, Key b) {
            return a.value < b.value;
        }
        friend bool operator==(Key a, Key b) {
            return a.value == b.value;
        }
        friend bool operator!=(Key a, Key b) {
            return a.value != b.value;
        }
        friend bool operator<=(Key a, Key b) {
            return a.value <= b.value;
        }
        friend bool operator>=(Key a, Key b) {
            return a.value >= b.value;
        }
        int getValue() { return value; }
};
class Record {
    private:
        Key key;
    public:
        Record();
        Record(int value)
        {
            key = Key(value);
        }

        operator Key()
        {
            return key;
        }
        void output(){
            cout << key.getValue() << " ";
        }

};
Record Retrieve(list <Record> &lt,int &value){
    int position = 0;
    for(Record &data : lt){
        if(position == value){
            return data;
        }
        position++;
    }
    Record tmp(0);
    return tmp;
}
enum ErrorCode {success, not_present};
ErrorCode Binary_search(list<Record> &the_list, const Key &target, int &position){
    int mid, top, bottom;
    top = the_list.size() - 1;
    bottom = 0;

    while(bottom <= top){
        mid = (top + bottom) / 2;
        Record data = Retrieve(the_list, mid);
        if(data == target){
            position = mid;
            return success;
        }
        else if (data < target){
            bottom = mid + 1;
        }
        else {
            top = mid - 1;
        }
    }
    return not_present;
}
int main()
{
     list<Record> my_list;
    int x, position = 0;
    cout << "nhap danh sach list: \n";
    do{
        cin >> x;
        Record data(x);
        if (x != 0)
            my_list.push_back(data);

    } while (x != 0);
    int target;
   
    do {
        cout << "nhap so can tim: ";
        cin >> target;
        ErrorCode result = Binary_search(my_list, target, position);
        if (result == success) {
            cout << "Vi tri tim thay " << target << " la: " << position + 1 << endl;
        }
        else
            cout << "Khong tim thay " << target << endl;
    } while (target != -1);
    return 0;
}
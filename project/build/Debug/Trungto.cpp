#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

bool checkTH(char a) {
    return a >= '0' && a <= '9';
}

bool checkTT(char a) {
    return a == '+' || a == '-' || a == '*' || a == '/' || a == '%';
}

int uuTien(char a) {
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/' || a == '%')
        return 2;
    if(a == '^') return 3;
    return 0;
}

void change(string a){
    stack <char> st;
    queue <char> q;

    for(int i = 0 ; i < a.size() ; i++){
        if(checkTH(a[i])) {
            q.push(a[i]);
        }
        else if(a[i] == '('){
            st.push(a[i]);
        }
        else if(a[i] == ')'){
            while(st.top() != '('){
                q.push(st.top());
                st.pop();
            }
            if(st.top() == '('){
                st.pop();
            }
        }
        else if(checkTT(a[i])){
            while(!st.empty() && uuTien(a[i]) <= uuTien(st.top())){
                if(st.empty()){
                    st.push(a[i]);
                }
                if(st.top() == '('){
                    st.push(a[i]);
                }
                if(uuTien(a[i]) > uuTien(st.top())){
                    st.push(a[i]);
                }
                if(uuTien(a[i]) <= uuTien(st.top())){
                    q.push(st.top());
                    st.pop();
                }
            }
            st.push(a[i]);
        }
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        cout << q.front();
        q.pop();
    }
    cout << endl;
}

string s ="";
void chuyenHauTo(string a) {
    stack<char> st;
    queue<char> q;

    for (int i = 0; i < a.length(); i++) {
        if (checkTH(a[i])) {
            q.push(a[i]);
        }
         else if (a[i] == '(') {
            st.push(a[i]);
        } 
        else if (a[i] == ')') {
            while ( st.top() != '(') {
                q.push(st.top());
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            
        } else if (checkTT(a[i])) {
            while(!st.empty() && uuTien(a[i]) <= uuTien(st.top())){
                if(st.top() == '('){
                    st.push(st.top());
                }
                if(uuTien(a[i]) > uuTien(st.top())){
                    st.push(a[i]);
                }
                if(uuTien(a[i]) <= uuTien(st.top())){
                    q.push(st.top());
                    st.pop();
                }
            }
            st.push(a[i]);
        }
    }

    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty()) {
        // cout << q.front();
        s += q.front();
        q.pop();
    }
    cout << endl;
}
void tinhGiaTri(string s){
    stack <int> stk;
    for(int i = 0 ; i < s.size() ; i++){
        if(checkTH(s[i])){
            stk.push(s[i] - 48);
        }
        else {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            switch (s[i])
            {
            case '+':
                stk.push(b + a);
                break;
            case '-':
                stk.push(b - a);
                break;
            case '*':
                stk.push(b * a);
                break;
            case '/':
                stk.push(b / a);
                break;
            default:
                break;
            }
        }
    }
   cout << stk.top();
}
int main() {
    string a;
    getline(cin, a);
    chuyenHauTo(a);
    cout << s << endl;
    tinhGiaTri(s);
    return 0;
}

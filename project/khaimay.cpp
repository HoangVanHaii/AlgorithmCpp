#include<iostream>
#include<iomanip>
using namespace std;
struct HCN{
    int a,b;
};
typedef struct HCN hcn;
istream& operator>>(istream &in,hcn &x){
    in>>x.a>>x.b;
    return in;
}
ostream& operator<<(ostream &out,hcn x){
    out<<x.a<<","<<x.b;
    return out;
}
float chuvi(hcn x){
    return (x.a+x.b);
}
bool operator<(hcn x,hcn y){
    return (chuvi(x)<chuvi(y));
}
bool operator>(hcn x,hcn y){
    return (chuvi(x)>chuvi(y));
}
bool operator==(hcn x,hcn y){
    return (chuvi(x)==chuvi(y));
}
hcn operator+(hcn x,hcn y){
    hcn c;
    float k=chuvi(x);
    float l=chuvi(y);
    c.a=(k+l);
    c.b=0;
    return c;
    
    //return k+l;
}
float operator+(hcn x,float y){
    return (chuvi(x)+y);
}
template<typename T>
struct Mang{
    int n;
    T a[100];
    T &operator[](int i){
        return a[i];
    }
};
template<typename T>
T minval(Mang<T> a){
    T min=a[0];
    for(int i=0;i<a.n;i++){
        if(min>a[i])min=a[i];
    }
    return min;
}
template<typename T>
T sumval(Mang<T> a){
    T sum=a[0];
    for(int i=1;i<a.n;i++){
        sum=sum+a[i];
    }
    return sum;
}
// template<typename T>
// void xuly(){
//     T a;
//     while(cin>>a[a.n]){
//         a.n++;
//     }
//     cout<<minval(a)<<endl<<sumval(a);
// }
float operator*(hcn x,float n){
    return (chuvi(x)*n);
}
int main(){
    char c;
    Mang <int> a;a.n=0;
    Mang <hcn> b;b.n=0;
    cin>>c;
    if(c=='N'){
        while(cin>>a[a.n]){
            a.n++;
        }
        cout<<minval(a)<<endl<<sumval(a);
        
    }
  
    else if(c=='H'){
        while(cin>>b[b.n]){
            b.n++;
        }
            cout<<"[HCN] "<<minval(b)<<endl<<setprecision(1)<<fixed<<sumval(b)*2;

    }
    return 0;
}
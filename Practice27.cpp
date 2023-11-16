#include<iostream>
using namespace std;

class Int{
    int a, b, c;

    public:
    Int(): a(0){}
    Int(Int m, Int n){
        cin >> m.a;
        b = m.a;
        cin >> n.a;
        c = n.a;
    }
    void add(){
        cout << b+c << endl;
    }
};

int main(){
    Int a, b;
    Int sum(a, b);
    sum.add();
    return 0;
}
//Friend Class
#include<iostream>
#include<string>
using namespace std;

class A{
    int a;
    public:
        A(){a=10;}
        void print(){cout << "Print a = " << a;}
        friend class B;
};

class B{
    int b;
    public:
        B(){b=10;}
        void print_A(A obj){cout << "Print b = " << b << " From a = " << obj.a; }
};

int main(){
    A t1;
    t1.print();
    B t2;
    t2.print_A(t1);
    return 0;
}

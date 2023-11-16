//Demo on multipath inheritance
#include<iostream>
using namespace std;

class A{
    public:
    A(){cout<<"I am from class A"<<endl;}
    void put(){cout<<"I'm the put() function of class A"<<endl;}
};

class B:virtual public A{
    public:
    B(){cout<<"I am from class B"<<endl;}
    void put(){cout<<"I'm the put() function of class B"<<endl;}
};

class C:virtual public A{
    public:
    C(){cout<<"I am from class C"<<endl;}
    void put(){cout<<"I'm the put() function of class C"<<endl;}
};

class D: public B, public C{
    public:
    D(){cout<<"I am from class D"<<endl;}
    void put(){cout<<"I'm the put() function of class D"<<endl;}
};

int main(){
    D d1;
    d1.put();
    d1.B::put();
    d1.C::put();
    d1.A::put();
    return 0;
}
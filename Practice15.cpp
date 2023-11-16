//Demo of Single Inheritance
#include<iostream>
using namespace std;

class Base{
    private: int b1;
    protected: int b2;
    public: int b3;
    Base(){cout << "constructior from base class"<< endl;b1=10;b2=20;b3=30;}
    friend class Derived;
};

class Derived: public Base{
    private: int d1;
    protected: int d2;
    public: int d3;
    Derived(){cout << "constructior from derived class"<< endl; d1=100; d2=200; d3=300;}
    void print(){
        cout << "Base class" << endl;
        cout << b1 << "\t" << b2 << "\t" << b3 << endl;
        cout << "Derived class" << endl;
        cout << d1 << "\t" << d2 << "\t" << d3 << endl;
    }
};

int main(){
    Derived d;
    d.print();
    cout << "Size = " << sizeof(d);
    return 0;
}
//Demo on Multilevel inheritance
#include<iostream>
using namespace std;

class A{
    int a1;
    public: //Constructors & Destructors
    A(){cout << "I'm from class A" << endl;}
    ~A(){cout << "I'm from class A (Destructor)" << endl;}
};

class B: public A{
    int b1;
    public:
    B(){cout << "I'm from class B" << endl;}
    ~B(){cout << "I'm from class B (Destructor)" << endl;}
};

class C: public B{
    int c1;
    public:
    C(){cout << "I'm from class C" << endl;}
    ~C(){cout << "I'm from class C (Destructor)" << endl;}
};

int main(){
    cout << "a1 object:" << endl;
    A a1;
    cout << "The size of a object: " << sizeof(a1) << " bytes" << endl;
    cout << "b1 object:" << endl;
    B b1;
    cout << "The size of b object: " << sizeof(b1) << " bytes" << endl;
    cout << "c1 object:" << endl;
    C c1;
    cout << "The size of c object: " << sizeof(c1) << " bytes" << endl;
    return 0;
}
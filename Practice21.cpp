//Demo on pure virtual function
#include<iostream>
using namespace std;

class Base{
    public:
    virtual void fun1()=0; //Pure virtual function
    virtual void display(){cout<<"I'm from the base class"<<endl;}
    virtual void fun(){cout<<"I'm from the fun() function"<<endl;}
};

class Derived: public Base{
    public:
    void display(){cout<<"I'm from the derived class"<<endl;}
    virtual void fun1(){cout<<"Implemented pure fun1()"<<endl;}
};

int main(){
    Derived d1;
    d1.display();
    Base *ptr = &d1; //Virtual --binding...
    ptr->display();
    ptr->fun(); 
    ptr->fun1();
    return 0;
}
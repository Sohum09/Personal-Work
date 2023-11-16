//Demo on Multiple Inheritance
#include<iostream>
using namespace std;

class Base_1{ //Base class
    public:
    Base_1(){cout << "I'm from Base 1!" << endl;}
    void print_data(){cout << "I am from Base 1 too!" << endl;}
    void print_data(double x){cout << "Me too from Base 1!" << x << endl;}
    void fun(){cout << "Chaos, chaos!" << endl;}
};

class Base_2{
    public:
    Base_2(){cout << "I'm from Base 2!" << endl;}
    void print_data(){cout << "I am from Base 2 too!" << endl;}
};

class Derived: public Base_1, public Base_2{
    public:
    Derived(){cout << "I'm from Derived!" << endl;}
    void print_data(){cout << "I am from Derived too!" << endl;}
};

int main(){
    Derived d1;
    d1.Base_1::print_data(); //Keyword for calling base class using derived class object
    d1.Base_1::print_data(2.43);
    d1.fun();
    d1.Base_2::print_data();
    d1.print_data();
    return 0;
}
//Demo on creation of a pointer object
#include<iostream>
using namespace std;

class Test{
    int a;
    public:
    Test(){cout << "Default Constructor" <<endl; a=10;}
    void print(){cout << "The value of a: " << a++ << endl;}
};
int main(){
    cout << "Object t1 is created" << endl;
    Test t1;
    t1.print();
    cout << "Pointer ptr is created" << endl;
    Test *ptr;
    ptr=&t1; //Referencing the address of t1, which is now 11 from 10+1=11
    ptr->print(); //points to print() of t1 object
    cout << "Object t2 is created" << endl;
    Test t2; //Resets value to 10
    ptr=&t2; //Referencing the address of t2
    ptr->print(); //points to print() of t2 object
    cout << "Now creating new object dynamically" << endl;
    ptr = new Test();
    ptr->print();
    delete ptr;
    return 0;
}
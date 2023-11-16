//Demonstration of static variables
#include<iostream>
using namespace std;

class Test{
    int a;
    static int b;
    public:
    Test(){a=10; ++b;}
    void print();
};

int Test::b=0;
void Test::print(){
    cout << "\na=" << a << endl << "b=" << b;
}

int main(){
    Test t1;
    t1.print();
    Test t2;
    t2.print();
    return 0;
}
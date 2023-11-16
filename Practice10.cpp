//Demonstration of pointers
#include<iostream>
using namespace std;

class Test{
    int *i;
    public:
        Test();
        Test(const Test &temp); //copy constructor
        void print();
};

Test::Test(){i=new int(100);}
Test::Test(const Test &temp){i=new int(200);}
void Test::print(){
    cout << *i << endl; //Value at address of i, aka dereferencing operator
    cout << i << endl;
}

int main(){
    Test t1;
    t1.print();
    Test t2(t1); //t2=t1;
    t2.print();
    return 0;
}
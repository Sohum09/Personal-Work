//Demonstration of constructors and destructors
#include <iostream>
using namespace std;

class Test{
    int x;
    public: 
        Test(){x=2000;print_data();} //Default Constructor
        void print_data();
        Test(int i){x=i; print_data();} //Parameterized Constructor
        ~Test(){cout << "YEET";} //Destructor
};


void Test::print_data(){
    cout << "X Value = " << x;
    cout << "\nX Address Value = " << &x << "\n";
}


int main(){
    Test t1;
    Test t2(100);
    return 0;
}
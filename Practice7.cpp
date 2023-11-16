//example for passing object as an argument
#include <iostream>
using namespace std;

class Test{
    int x;
    public: 
        void get_data();
        void print_data();
        void add(Test, Test);
};

void Test::get_data(){
    cin >> x;
}

void Test::print_data(){
    cout << "X Value = " << x;
    cout << "\nX Address Value = " << &x << endl;
}

void Test::add(Test ob1, Test ob2){
    this->x = ob1.x + ob2.x; //this optional
}

int main(){
    Test t1, t2, t3;
    t1.get_data();
    t1.print_data();
    t2.get_data();
    t2.print_data();
    t3.add(t1, t2);
    t3.print_data();
    return 0;
}
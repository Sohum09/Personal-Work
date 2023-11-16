//Demo on Unary operator overloading
#include<iostream>
using namespace std;

class Test{
    int a;
    public:
    Test():a(10){cout << "Default Constructor" << endl;}
    void operator ++(){cout << "Prefix add" << endl; ++a;} //Operator to increment every data member by one, via the pre-fix method
    void operator ++(int){cout << "Postfix add" << endl; a++;} //Operator to increment every data member by one, via the post-fix method
    void operator --(){cout << "Prefix subtract" << endl; --a;} //Operator to decrement every data member by one, via the pre-fix method
    void operator --(int){cout << "Postfix subtract" << endl; a--;} //Operator to decrement every data member by one, via the post-fix method
    void display(){cout << "The value of a = " << a << endl;}
};

int main(){
    Test t1; //Pre-fix
    ++t1; ++t1; ++t1; //Incrementing every data member by one, aka, t1.operator ++() is called here, three times, so 10 + 3 = 13.
    t1.display(); 
    Test t2; 
    t2++; //Incrementing every data member by one, aka, t1.operator ++(int) is called here, one time, so 10 + 1 = 11.
    t2.display();
    Test t3; 
    --t3; --t3; //Decrementing every data member by one, aka, t1.operator --() is called here, two times, so 10 - 2 = 9.
    t3.display();
    Test t4; 
    t4--; //Decrementing every data member by one, aka, t1.operator --(int) is called here, one time, so 10 - 1 = 9.
    t4.display();
    return 0;
}
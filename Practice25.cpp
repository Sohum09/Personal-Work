//Demo on binary operator overloading
#include<iostream>
using namespace std;

class Test{
    int a;
    public:
    Test(): a(0){}
    Test(int x): a(x){} //Test(int x)"{a=x};"
    void display(){cout << "Value of a=" << a << endl;}
    Test operator +(Test t){Test temp; temp.a = a + t.a; return temp;} //a---->t1 object, t.a---->t2 object
    Test operator -(Test t){Test temp; temp.a = a - t.a; return temp;} //a---->t1 object, t.a---->t2 object
    Test operator *(Test t){Test temp; temp.a = a * t.a; return temp;} //a---->t1 object, t.a---->t2 object
    bool operator <(Test t){return (a<t.a)? true : false;} 
};

int main(){
    Test t1(5), t2(10), t3, t4, t5;
    t3 = t1+t2; //t3 = t1.operator + (t2)
    t4 = t1+t2-t3;
    t5 = t1+t2-t3*t4;
    bool flag = t5<t2;
    t1.display(); t2.display(); t3.display(); t4.display();t5.display();
    cout << flag <<endl;
    return 0;
}
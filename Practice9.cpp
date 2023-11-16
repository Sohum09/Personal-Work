//Basic pointer demonstration
#include<iostream>
using namespace std;
int main(){
    int a=100;
    int &ptr = a;
    int *y;
    y = new int;
    cout << "Value = " << a;
    cout << "\nAddress = " << &a;
    cout << "\nReference Value = " << ptr;
    cout << "\nReference's pointing to = " << &ptr;
    cout << "\nPointer Value = " << y;
    cout << "\nPointers pointing to = " << *y;
    return 0;
}
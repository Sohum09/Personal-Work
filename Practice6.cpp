#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void manipulate(double *n){
    double x = log(*n);
    *n = x + pow(2, x);
}

int main() {
    double a;
    cout << "Enter value: ";
    cin >> a;
    double *ptr = &a;
    cout << *ptr << "\n";
    manipulate(&a);
    cout << *ptr << "\n";
    manipulate(ptr);
    cout << *ptr;
    return 0;
}
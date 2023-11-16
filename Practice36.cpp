//Basic demo of Template
#include<iostream>
using namespace std;

template<class T1, class T2, class T3>
T3 max(T1 x, T2 y){ //Basic variable of any data type; but it belongs to the class it is associated with.
    return (x>y)? x: y;
};

int main(){
    cout << max(17, 19) << endl;
    cout << max(1.5, 6.7) << endl;
    cout << max('A', 'B');
    return 0;
}
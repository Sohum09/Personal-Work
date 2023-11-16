//Basic demo of Template pt.2
#include<iostream>
using namespace std;

template<class T1>
T1 max(T1 x, T1 y, T1 z){ //Basic variable of any data type; but it belongs to the class it is associated with.
    if (x>y && x>z){
        return x;
    }
    else if(y>x && y>z){
        return y;
    }
    else if (z>x && z>y){
        return z;
    }
    return x;
};  

int main(){
    cout << max(17, 19, 21) << endl;
    cout << max(1.5, 6.7, -12.2) << endl;
    cout << max('A', 'B', 'F');
    return 0;
}
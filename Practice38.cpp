#include<iostream>
using namespace std;

template<class T1, class T2>
int add(T1 x, T2 y){ //Basic variable of any data type; but it belongs to the class it is associated with.
    return x+y;
};
template<class T3, class T4>
int sub(T3 x, T4 y){
    return x-y;
};

int main(){
    int x1, x2, y1, y2;
    cin >> x1; cin >> y1;
    cin >> x2; cin >> y2;
    cout << add(x1, x2) << " + " << add(y1, y2) << "i" << endl;
    cout << sub(x1, x2) << " + " << sub(y1, y2) << "i";
    return 0;
}
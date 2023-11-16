#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    float x, y;
    cin >> x;
    cin >> y;
    cout << max(x, y) << "\n";
    cout << min(x, y) << "\n";
    cout << sqrt(x) << " " << sqrt(y) << "\n";
    cout << round(x) << " " << round(y) << "\n";
    cout << log(x) << " " << log(y) << "\n";
    cout << (x>y);
    string result = (x>=18)? "Voter" : "Illegal voter";
    cout << "\n" << result;
    return 0;
}
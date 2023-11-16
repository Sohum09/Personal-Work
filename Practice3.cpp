#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int num, dig, sum=0, i=0;
    cout << "Enter: ";
    cin >> num;
    do{
        i++;
        if (i==3)
            continue;
        cout << i;
        num /= 10;
    } while (num>0);
    cout << num;
    for(int j=0; j<=i; j++){
        cout << j;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    int num[n];
    for(int i=0; i<n; i++){
        cin >> x;
        num[i] = x;
    }
    cout << sizeof(num) << " " << sizeof(x) << "\n";
    for(int i=0; i<n; i++){
        cout << num[i] << "\n";
    }
    int sum=0;
    int mat[3][3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++){
            cin >> x;
            mat[i][j]=x;
            sum += mat[i][j];
        }
    cout << sum;
    return 0;
}
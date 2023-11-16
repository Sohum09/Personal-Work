#include<iostream>
using namespace std;

int maxint(int *arr, int n){
    int i, largest=arr[0], indx=0;
    for(i=0; i<n; i++)
        if(arr[i]>largest){
            largest = arr[i];
            indx=i;
        }
    return indx;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int index = maxint(a, n);
    cout << a[index] << " at " << index;
    return 0;
}

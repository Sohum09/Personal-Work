#include <iostream>
using namespace std;

int max(int a, int b, int c){
    if(a>b){
        if(a>c)
            return a;
        else
            return c;
    }
    else{
        if(b>c)
            return b;
        else    
            return c;
    }
}

int maxi(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int findLMax(int x[], int lower, int middle){
    int lmax = INT_MIN, sum=0;
    for(int i=middle; i>=lower; i--){
        sum += x[i];
        lmax = maxi(lmax, sum);
    }
    return lmax;
}

int findUMax(int x[], int middle1, int upper){
    int umax = INT_MIN, sum=0;
    for(int i=middle1; i<=upper; i++){
        sum += x[i];
        umax = maxi(umax, sum);
    }
    return umax;
}

int MSS(int x[], int lower, int upper){
    if(lower>upper)
        return 0;
    if(lower==upper)
        return x[lower];
    
    int middle = (lower+upper)/2;
    int lmax = findLMax(x, lower, middle);
    int umax = findUMax(x, middle+1, upper);

    return max(MSS(x, lower, middle), MSS(x, middle+1, upper), lmax+umax);
}

int main(){
    int x[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int finalResult = MSS(x, 0, 7);
    cout << "The final result: " << finalResult;
    return 0;
}
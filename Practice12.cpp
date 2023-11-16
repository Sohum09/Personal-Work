#include<iostream>
using namespace std;

int main(){
    for(int i=2000; i<=3200; i++){
        if(i%7==0 && i%5!=0)
            cout << i << ", ";
    }
}
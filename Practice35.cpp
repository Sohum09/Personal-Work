#include<iostream>
using namespace std;

class Bank{
    float balance;
    public:
    float getBalance(){return 0;}
};

class KVB: public Bank{
    public:
    float getBalance(){return 10000;}
};

class IB: public Bank{
    public:
    float getBalance(){return 15000;}
};

class SBI: public Bank{
    public:
    float getBalance(){return 20000;}
};

int main(){
    int ch;
    cout << "Enter the Bank you would like to see the deposit of: \n1. KVB Bank\n2. IB Bank\n3. SBI Bank\n";
    cin >> ch;
    float amt;
    switch(ch){
        case 1:
        KVB ob;
        amt=ob.getBalance(); break;
        case 2:
        amt=ob.getBalance(); break;
        case 3:
        amt=ob.getBalance();
    }
    cout << "Balance in Rs: " << amt;
    return 0;
}
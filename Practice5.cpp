#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kerbal{
    int courage;
    int stupidity;
}Jeb, Bob, Bill;

string ifCourageous(int *ptr){
    return (*ptr >= 5)? "courageous" : "not courageous";
}

string ifStupid(int *ptr){
    return (*ptr >= 5)? "stupid" : "not stupid";
}

int main() {
    cin >> Jeb.courage;
    cin >> Jeb.stupidity;
    cin >> Bob.courage;
    cin >> Bob.stupidity;
    cin >> Bill.courage;
    cin >> Bill.stupidity;

    cout << "\n" << Jeb.courage << "\t" << Jeb.stupidity;
    cout << "\n" << Bob.courage << "\t" << Bob.stupidity;
    cout << "\n" << Bill.courage << "\t" << Bill.stupidity;

    string kerb = "Courage and stupidity indeed.";
    string &game = kerb;

    cout << "\nSuch wonderful Kerbals! " << game; 
    cout << "\nNow let us see its address. " << &kerb;
    cout << "\n" << &game;

    int *ptr1 = &Jeb.courage, *ptr2 = &Bob.courage, *ptr3 = &Bill.courage;
    string res1 = ifCourageous(ptr1), res2 = ifCourageous(ptr2), res3 = ifCourageous(ptr3);
    string res4 = ifStupid(&Jeb.stupidity), res5 = ifStupid(&Bob.stupidity), res6 = ifStupid(&Bill.stupidity);
    cout << "\nJeb is " << res1 << " and " << res4;
    cout << "\nBob is " << res2 << " and " << res5;
    cout << "\nBill is " << res3 << " and " << res6;
    return 0;
}
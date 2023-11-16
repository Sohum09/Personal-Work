#include<iostream>
#include<string>
using namespace std;

struct Account{
    string bank;
    float amt;
};

int main(){
    int n, i, j;
    char ch;
    float amt;
    cout << "Enter total accounts the man has: ";
    cin >> n;
    Account acc[n];

    for(i=0; i<n; i++){
        cout << "Enter Bank name for Account" << (i+1) << ": ";
        cin >> acc[i].bank;
        cout << "Enter Bank balance for Account" << (i+1) << ": ";
        cin >> acc[i].amt;
    }

    do{
        cout << "Enter the account to deposit money in: ";
            cin >> i;
        if(acc[i-1].amt==0){
            cout << "This account has no balance and hence does not exist."<<endl;
        }
        else{
            cout<<"1. To deposit money\n2. To withdraw money\n3. To transfer money\n0. To finish.\nEnter choice[1-4]: ";
            cin >> ch;
            switch(ch){
                case 1:
                cout << "Enter the amount to deposit money in Rs: ";
                cin >> amt;
                acc[i-1].amt+=amt;
                break;

                case 2:
                cout << "Enter the amount to withdraw money in Rs: ";
                cin >> amt;
                if(amt<acc[i-1].amt)
                    cout << "Not enough balance!"<<endl;
                else
                    acc[i-1].amt-=amt;
                break;

                case 3:
                cout << "Enter the account to transfer money to: ";
                cin >> j;
                cout << "Enter the amount to transfer money in Rs: ";
                cin >> amt;
                if(amt<acc[i-1].amt)
                    cout << "Not enough balance!"<<endl;
                else{
                    acc[i-1].amt-=amt;
                    acc[j-1].amt+=amt;
                }
            }
        }
    }while(ch!='4');

    cout << "Thank you for using the program!"<<endl;
    for(i=0; i<n && acc[i].amt!=0; i++){
        cout << "Bank name for Account "<< (i+1) <<": " << acc[i].bank;
        cout << "Bank balance for Account " << (i+1) << " in Rs: "<< acc[i].amt;
    }
}
#include<iostream>
#include<string>
using namespace std;

class Account{
    private:
    string name, accType, status;
    int accNo, days;
    float balance, amt;

    public:
    void input(){
        cout << "Enter account no.: ";
        cin >> accNo;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account type: ";
        cin >> accType;
        cout << "Enter days since last transaction: ";
        cin >> days;
        cout << "Enter balance in Rs: ";
        cin >> balance;
        status = (days>365)? "dormant": "active";
    }

    void display(){
        cout << "Status of account: " << status;
        cout << "Enter withdrawal amount in Rs: ";
        cin >> amt;
        if((balance-amt)<1000)
            cout << "Denied!";
        else
            balance-=amt;
    }
};

int main(){
    Account obj;
    obj.input();
    obj.display();
    return 0;
}

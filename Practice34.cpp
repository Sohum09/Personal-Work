#include<iostream>
#include<string>
using namespace std;

class Account{
    private:
    string name, accType;
    int accNo;
    public:
    float balance;
    void inp(){
        cout << "Enter account name: ";
        cin >> name;
        cout << "Enter account type: ";
        cin >> accType;
        cout << "Enter account balance in Rs: ";
        cin >> balance;
    }
};

class sav_acct: public Account{
    private:
    float minBalance, penalty, amt, interest;
    public:
    void inputSav(){
        minBalance = 500;
        penalty = 0.05*balance;
        cout << "Enter amount you wish to withdraw in Rs: ";
        cin >> amt;
        if((balance-amt)<0)
            cout << "Not enough balance";
        else
            balance -= amt;
    }

    void updateBalanceSav(){
        if((balance-amt)<500){
            cout << "A Penalty of Rs "<< penalty << " is imposed accordingly.";
        }
        interest = penalty;
        cout << "The total penalty (if applicable) will be subtracted from the balance accordingly";
        balance -= interest;
    }

    void balSav(){
        cout << "Balance: " << balance;
    }
};

class cur_acct: public Account{
    private:
    float minBalance, penalty, amt, interest;
    public:
    void inputCur(){
        minBalance = 500;
        penalty = 0.05*balance;
        cout << "Enter amount you wish to withdraw in Rs: ";
        cin >> amt;
        if((balance-amt)<0)
            cout << "Not enough balance";
        else
            balance -= amt;
    }

    void updateBalanceCur(){
        interest = 0.07*balance;
        cout << "The total interest of 7% will be subtracted from the balance accordingly";
        balance -= interest;
    }

    void balCur(){
        cout << "Balance: " << balance;
    }
};

int main(){
    Account acc;
    acc.inp();
    sav_acct ob1;
    cur_acct ob2;
    int ch;
    do{
        cout<<"1. Savings account\n2. Current account\n3. Exit\n";
        cin >> ch;
        switch(ch){
            case 1:
            ob1.inputSav();
            ob1.updateBalanceSav();
            ob1.balSav();
            case 2:
            ob2.inputCur();
            ob2.updateBalanceCur();
            ob2.balCur();
        }
    }while(ch!='3');
}
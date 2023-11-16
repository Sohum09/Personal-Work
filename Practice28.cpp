#include<iostream>
using namespace std;

class TollBooth{
    private:
    unsigned int cars;
    double amt;
    const double amount = 0.50;
    public:
    TollBooth(): cars(0), amt(0.0){}
    void payingCar(){
        cars++; amt+=amount;
    }
    void noPayCar(){
        cars++;
    }
    void display(){
        double payCar = amt/amount;
        double noPayCar = cars - payCar;
        cout << "Total cars which paid: " << payCar << endl;
        cout << "Total cars which did not pay: " << noPayCar << endl;
        cout << "Final amount: " << amt << endl;
    }
};

int main(){
    TollBooth booth;
    char ch;
    do{
        cout << "0 - Did not pay\n1 - Paid\nN - Exit program;" << endl;
        cin >> ch;

        switch(ch){
            case '0': booth.noPayCar(); break;
            case '1': booth.payingCar(); break;
            default: continue;
        }
    }while(ch!='N');
    booth.display();
    return 0;
}
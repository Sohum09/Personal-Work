#include<iostream>
using namespace std;

enum etype {labourer, secretary, manager, accountant, executive,
researcher};

class Employee{
    private:
    int empNum;
    float compensation;
    class Date{
        int day, month, year;
        public:
        void getdate(){
            cin >> day;
            cin >> month;
            cin >> year; 
        }
        void showdate(){
            cout << "Date: " << day << "/" << month << "/" << year << endl;
        }
    } obj;
    etype emp;

    public:
    void enterInfo(){
        char ch;
        cout << "Enter Employee Number: ";
        cin >> empNum;
        cout << "Enter compensation in USD: ";
        cin >> compensation;
        obj.getdate();
        cout << "Enter Employee type (first letter only): ";
        cin >> ch;
        switch(ch){
            case 'l': emp=labourer; break;
            case 's': emp=secretary; break;
            case 'm': emp=manager; break;
            case 'a': emp=accountant; break;
            case 'e': emp=executive; break;
            case 'r': emp=researcher;
        }
    }

    void display(){
        cout << "Employee Number: " << empNum << endl;
        cout << "Compensation in USD: " << compensation << endl;
        obj.showdate();
        switch(emp){
            case labourer: cout << "The type of profession: Labourer"; break;
            case secretary: cout << "The type of profession: Secretary"; break;
            case manager: cout << "The type of profession: Manager"; break;
            case accountant: cout << "The type of profession: Accountant"; break;
            case executive: cout << "The type of profession: Executive"; break;
            case researcher: cout << "The type of profession: Researcher";
        }
    }
};

int main(){
    int num;
    cout << "Enter total employees: ";
    cin >> num;
    Employee emp[num];

    for(int i=0; i<num; i++)
        emp[i].enterInfo();
    for(int i=0; i<num; i++)
        emp[i].display();
    return 0;
}
//Basic Multiple Inheritance program
#include<iostream>
#include <string>
using namespace std;

//Basic info of employee, Base class
class basicInfo{
    protected:
    int empID;
    string gender, name;
    public:
    void getInfo(){
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter gender [M/F]";
        getline(cin, gender);
        cout << "Enter employee ID";
        cin >> empID;
    }
};

class deptInfo{
    protected:
    int time;
    string work, dept;
    public:
    void getDeptInfo(){
        cin.ignore(); //Ignores the newline character at the end of the cout calling for department info in enterInfo()
        cout << "Enter name of department: ";
        getline(cin, dept);
        cout << "Enter Assigned Work: ";
        getline(cin, work);
        cout << "Enter time";
        cin >> time;
    }
};

class Employee: public basicInfo, public deptInfo{
    public:
    void enterInfo(){
        cout << "Enter basic info" << endl;
        getInfo();
        cout << "Enter department info" << endl;
        getDeptInfo();
    }

    void printInfo(){
        cout << "Employee's Information is: "     << endl;
        cout << "Basic Information...:"       << endl;
        cout << "Name: "      << name   << endl;      //accessing protected data
        cout << "Employee ID: " << empID  << endl;        //accessing protected data
        cout << "Gender: "        << gender << endl << endl;//accessing protected data
             
        cout << "Department Information...:"  << endl;
        cout << "Department Name: "           << dept  << endl; //accessing protected data
        cout << "Assigned Work: "             << work << endl; //accessing protected data
        cout << "Time to complete work: "     << time << endl; //accessing protected data
    }
};

int main(){
    Employee emp;
    emp.enterInfo();
    emp.printInfo();
    return 0;
}
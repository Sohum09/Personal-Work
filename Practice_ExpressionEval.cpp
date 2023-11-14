#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(int op1, int op2, char op){
    switch(op){
        case '+' : return op1+op2;
        case '-' : return op1-op2;
        case '*' : return op1*op2;
        default: cout << "Invalid operator encountered." << endl; return 0;
    }
}

int evalExpression(const string& str){
    stack<int> operands;
    stack<int> operators;

    int i=0;

    while(i < str.length()){
        if(isdigit(str[i])){
            int operand = 0;
            while(i < str.length() && isdigit(str[i])){
                operand = operand * 10 + (str[i] - '0'); //Building the number
                i++;
            }
            operands.push(operand);
            cout << "Pushed operand " << operand << endl;
        }
        else if(str[i] == '+' || str[i] == '*'){
            if(!operators.empty() && operators.top() == '*'){
                int oper2 = operands.top();
                operands.pop();
                int oper1 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                int result = calculate(oper1, oper2, op);
                operands.push(result);
                cout << "Calculated and pushed intermediate result: " << oper1 << " " << op << " " << oper2 << " = " << result << endl; 
            }
            operators.push(str[i]);
            cout << "Pushed operator: " << str[i] << endl;
            i++;
        }
        else{
            cout << "Invalid operator encountered: " << str[i] << endl;
            return -1;
        }

        while(!operators.empty()){
            int oper2 = operands.top(); 
            operands.pop(); 
            int oper1 = operands.top(); 
            operands.pop(); 
            char op = operators.top(); 
            operators.pop(); 
            int result = calculate(oper1, oper2, op); 
            operands.push(result); 
            cout << "Calculated and pushed intermediate result: " << oper1 << " " << op << " " << oper2 << " = " << result << endl; 
        }
    }
    return operands.top();
}

int main(){
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);
    int result = evalExpression(expression); 
    if(result != -1) 
        cout << endl << "The value of the expression " << expression << " is: " << result << endl; 
    return 0; 
}
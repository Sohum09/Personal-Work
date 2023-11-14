#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluateExpression(const string& expression) {
    stack<int> operandStack;
    stack<char> operatorStack;

    for (char ch : expression) {
        if (isdigit(ch)) {
            operandStack.push(ch - '0');
        } else if (ch == '*' || ch == '+' || ch == '-') {
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   ((ch != '*' && operatorStack.top() == '+') || (ch == '-'))) {
                char op = operatorStack.top();
                operatorStack.pop();

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                if (op == '+') {
                    operandStack.push(operand1 + operand2);
                } else if (op == '-') {
                    operandStack.push(operand1 - operand2);
                } else if (op == '*') {
                    operandStack.push(operand1 * operand2);
                }
            }

            operatorStack.push(ch);
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                char op = operatorStack.top();
                operatorStack.pop();

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                if (op == '+') {
                    operandStack.push(operand1 + operand2);
                } else if (op == '-') {
                    operandStack.push(operand1 - operand2);
                } else if (op == '*') {
                    operandStack.push(operand1 * operand2);
                }
            }

            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            }
        }
    }

    while (!operatorStack.empty()) {
        char op = operatorStack.top();
        operatorStack.pop();

        int operand2 = operandStack.top();
        operandStack.pop();
        int operand1 = operandStack.top();
        operandStack.pop();

        if (op == '+') {
            operandStack.push(operand1 + operand2);
        } else if (op == '-') {
            operandStack.push(operand1 - operand2);
        } else if (op == '*') {
            operandStack.push(operand1 * operand2);
        }
    }

    return operandStack.top();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    int result = evaluateExpression(expression);
    cout << "Result: " << result << endl;

    return 0;
}

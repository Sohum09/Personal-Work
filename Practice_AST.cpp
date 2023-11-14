#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;
struct tree
{
    string value;
    tree *left;
    tree *right;
    tree(string val) : value(val), left(nullptr), right(nullptr) {}
};
bool isOp(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void displayTree(tree *node, string indent = "", bool isLeft = false)
{
    if (node == nullptr)
        return;
    displayTree(node->right, indent + (isLeft ? " " : " "), false);
    cout << indent;
    if (isLeft)
        cout << "|-";
    else
        cout << "\\-";
    cout << node->value << endl;
    displayTree(node->left, indent + (isLeft ? " " : " "), true);
}
void threeAddCode(const string &str)
{
    stack<string> code;
    stack<tree *> operands;
    stack<char> operators;
    for (char c : str)
    {
        if (c == ' ')
            continue;
        if (isOp(c))
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c))
            {
                char op = operators.top();
                operators.pop();
                tree *op2 = operands.top();
                operands.pop();
                tree *op1 = operands.top();
                operands.pop();
                string tempVar = "t" + to_string(code.size() + 1);
                code.push(tempVar + " = " + op1->value + " " + op + " " + op2->value);
                tree *temp = new tree(tempVar);
                temp->left = op1;
                temp->right = op2;
                operands.push(temp);
            }
            operators.push(c);
        }
        else
        {
            stringstream ss;
            ss << c;
            while (isdigit(str[ss.tellg()]))
                ss << str[ss.tellg()];
            string operand = ss.str();
            tree *operandNode = new tree(operand);
            operands.push(operandNode);
        }
    }
    while (!operators.empty())
    {
        char op = operators.top();
        operators.pop();
        tree *op2 = operands.top();
        operands.pop();
        tree *op1 = operands.top();
        operands.pop();
        string tempVar = "t" + to_string(code.size() + 1);
        code.push(tempVar + " = " + op1->value + " " + op + " " + op2->value);
        tree *temp = new tree(tempVar);
        temp->left = op1;
        temp->right = op2;
        operands.push(temp);
    }
    tree *root = operands.top();
    cout << "\nAbstract Syntax Tree (AST) for the given Expression:\n";
    displayTree(root);
    cout << "\nThree Address Code for the given Expression:\n";
    stack<string> dispCode;
    while (!code.empty())
    {
        dispCode.push(code.top());
        code.pop();
    }
    while (!dispCode.empty())
    {
        cout << dispCode.top() << endl;
        dispCode.pop();
    }
}
int main()
{
    string str;
    cout << "Enter an expression starting with 'x = ': ";
    getline(cin, str);
    threeAddCode(str);
    return 0;
}
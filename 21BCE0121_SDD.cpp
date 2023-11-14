#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

// Node of Abstract Syntax Tree (AST)
struct ASTNode {
    string value;
    ASTNode* left;
    ASTNode* right;
};

// Generate Three Address Code (TAC) instruction
struct TACInstruction {
    string result;
    string op;
    string arg1;
    string arg2;
};

class ExpressionEvaluator {
private:
    stack<char> opStack;                // Operator stack
    vector<TACInstruction> tacCode;     // Three Address Code (TAC)

    int tempCount;                      // Counter for generating temporary variables

public:
    stack<ASTNode*> exprStack; // Expression stack (AST)
    ExpressionEvaluator() {
        tempCount = 0;
    }

    // Check if the character is an operator (+, -, *, /)
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    // Get the precedence of an operator
    int getPrecedence(char op) {
        if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    // Create a new AST node
    ASTNode* createNode(const string& value, ASTNode* left = nullptr, ASTNode* right = nullptr) {
        ASTNode* node = new ASTNode;
        node->value = value;
        node->left = left;
        node->right = right;
        return node;
    }

    // Generate a new temporary variable name
    string generateTemp() {
        string temp = "t" + to_string(tempCount);
        tempCount++;
        return temp;
    }

    // Process the current operator on the top of the operator stack
    void processOperator() {
        char op = opStack.top();
        opStack.pop();

        ASTNode* right = exprStack.top();
        exprStack.pop();

        ASTNode* left = exprStack.top();
        exprStack.pop();

        string result = generateTemp();
        exprStack.push(createNode(result, left, right));

        // Generate TAC instruction
        TACInstruction tac;
        tac.result = result;
        tac.op = op;
        tac.arg1 = left->value;
        tac.arg2 = right->value;
        tacCode.push_back(tac);
    }

    // Evaluate the expression and generate AST and TAC
    void evaluateExpression(const string& expression) {
        for (char ch : expression) {
            if (isdigit(ch)) {
                string operand(1, ch);
                exprStack.push(createNode(operand));
            } else if (isOperator(ch)) {
                while (!opStack.empty() && isOperator(opStack.top()) &&
                       getPrecedence(opStack.top()) >= getPrecedence(ch)) {
                    processOperator();
                }
                opStack.push(ch);
            } else if (ch == '(') {
                opStack.push(ch);
            } else if (ch == ')') {
                while (!opStack.empty() && opStack.top() != '(') {
                    processOperator();
                }
                opStack.pop();  // Discard the opening parenthesis
            }
        }

        while (!opStack.empty()) {
            processOperator();
        }
    }

    // Display the Abstract Syntax Tree (AST)
    void displayAST(ASTNode* node, int indent = 0) {
        if (node != nullptr) {
            cout << string(indent, ' ') << node->value << endl;
            displayAST(node->left, indent + 2);
            displayAST(node->right, indent + 2);
        }
    }

    // Display the Three Address Code (TAC)
    void displayTAC() {
        for (const auto& tac : tacCode) {
            cout << tac.result << " = " << tac.arg1 << " " << tac.op << " " << tac.arg2 << endl;
        }
    }
};

int main() {
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);

    ExpressionEvaluator evaluator;
    evaluator.evaluateExpression(expression);

    cout << "\nAbstract Syntax Tree (AST):\n";
    evaluator.displayAST(evaluator.exprStack.top());

    cout << "\nThree Address Code (TAC):\n";
    evaluator.displayTAC();

    return 0;
}

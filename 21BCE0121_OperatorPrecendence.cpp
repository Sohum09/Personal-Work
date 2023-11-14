#include <iostream>
#include <stack>
#include <string>

using namespace std;

enum class TokenType {
    Plus,
    Multiply,
    LeftParenthesis,
    RightParenthesis,
    Identifier
};

struct Token {
    TokenType type;
    string lexeme;
};

Token getNextToken(const string& input, size_t& index) {
    while (index < input.length() && isspace(input[index])) {
        index++;
    }

    if (index >= input.length()) {
        return {TokenType::Identifier, ""};
    }

    switch (input[index]) {
        case '+':
            return {TokenType::Plus, "+"};
        case '*':
            return {TokenType::Multiply, "*"};
        case '(':
            return {TokenType::LeftParenthesis, "("};
        case ')':
            return {TokenType::RightParenthesis, ")"};
        default:
            {
                size_t lexemeEnd = index;
                while (lexemeEnd < input.length() && isalnum(input[lexemeEnd])) {
                    lexemeEnd++;
                }
                string lexeme = input.substr(index, lexemeEnd - index);
                return {TokenType::Identifier, lexeme};
            }
    }
}

bool highPreced(const Token& op1, const Token& op2) {
    static const int precedence[][2] = {
        // Plus, Multiply
        {1, -1},  // Plus
        {1, 1},   // Multiply
        {-1, -1}  // Others
    };

    int op1Index, op2Index;
    switch (op1.type) {
        case TokenType::Plus:
            op1Index = 0;
            break;
        case TokenType::Multiply:
            op1Index = 1;
            break;
        default:
            op1Index = 2;
            break;
    }

    switch (op2.type) {
        case TokenType::Plus:
            op2Index = 0;
            break;
        case TokenType::Multiply:
            op2Index = 1;
            break;
        default:
            op2Index = 2;
            break;
    }

    return precedence[op1Index][op2Index] >= 0;
}

bool operatorPrecedenceParsing(const string& input) {
    stack<Token> operatorStack;
    stack<Token> opStack;

    size_t index = 0;
    Token curTok = getNextToken(input, index);

    while (curTok.type != TokenType::Identifier && index < input.length()) {
        if (curTok.type == TokenType::Identifier) {
            opStack.push(curTok);
            curTok = getNextToken(input, index);
        } else {
            if (operatorStack.empty() || !highPreced(operatorStack.top(), curTok)) {
                operatorStack.push(curTok);
                curTok = getNextToken(input, index);
            } else {
                Token op = operatorStack.top();
                operatorStack.pop();

                if (opStack.size() < 2) {
                    cout << "Invalid expression." << endl;
                    return false;
                }

                Token operand2 = opStack.top();
                opStack.pop();
                Token operand1 = opStack.top();
                opStack.pop();

                string expression = "(" + operand1.lexeme + op.lexeme + operand2.lexeme + ")";
                opStack.push({TokenType::Identifier, expression});
            }
        }
    }

    while (!operatorStack.empty()) {
        Token op = operatorStack.top();
        operatorStack.pop();

        if (opStack.size() < 2) {
            cout << "Invalid expression." << endl;
            return false;
        }

        Token operand2 = opStack.top();
        opStack.pop();
        Token operand1 = opStack.top();
        opStack.pop();

        string expression = "(" + operand1.lexeme + op.lexeme + operand2.lexeme + ")";
        opStack.push({TokenType::Identifier, expression});
    }

    if (opStack.size() != 1) {
        cout << "Invalid expression." << endl;
        return false;
    }

    cout << "Parsed expression: " << opStack.top().lexeme << endl;
    return true;
}

int main() {
    string input = "(i*i)+(i*i)+i";
    cout << "Input: " << input << endl;

    bool parsingResult = operatorPrecedenceParsing(input);

    if (!parsingResult) 
        cout << "Parsing failed." << endl;
    return 0;
}

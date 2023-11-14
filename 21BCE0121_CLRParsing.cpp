#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

enum class SymbolType {
    TERMINAL,
    NON_TERMINAL
};

enum class Terminal {
    PLUS,
    MULTIPLY,
    LEFT_PAREN,
    RIGHT_PAREN,
    ID,
    END_OF_INPUT
};

struct Symbol {
    SymbolType type;
    Terminal terminal;
};

struct Production {
    char lhs;
    string rhs;
};

class CLRParser {
private:
    unordered_map<Terminal, unordered_map<char, string>> action;
    unordered_map<Terminal, unordered_map<char, int>> goTo;
    vector<Production> productions;

public:
    CLRParser() {
        initializeProductions();
        initializeActionTable();
        initializeGoToTable();
    }

    void initializeProductions() {
        productions = {
            {'E', "E+T"},
            {'E', "T"},
            {'T', "T+F"},
            {'T', "F"},
            {'F', "(E)"},
            {'F', "i"}
        };
    }

    void initializeActionTable() {
        action[Terminal::PLUS] = {
            {'E', "s5"},
            {'T', ""},
            {'F', ""},
            {'+', ""},
            {'*', ""}
        };
        action[Terminal::MULTIPLY] = {
            {'E', ""},
            {'T', "s6"},
            {'F', ""},
            {'+', ""},
            {'*', ""}
        };
        action[Terminal::LEFT_PAREN] = {
            {'E', "s4"},
            {'T', ""},
            {'F', ""},
            {'+', ""},
            {'*', ""}
        };
        action[Terminal::RIGHT_PAREN] = {
            {'E', ""},
            {'T', ""},
            {'F', ""},
            {'+', "r2"},
            {'*', "r2"}
        };
        action[Terminal::ID] = {
            {'E', ""},
            {'T', ""},
            {'F', ""},
            {'+', "r4"},
            {'*', "r4"}
        };
        action[Terminal::END_OF_INPUT] = {
            {'E', ""},
            {'T', ""},
            {'F', ""},
            {'+', "r6"},
            {'*', "r6"}
        };
    }

    void initializeGoToTable() {
        goTo[Terminal::PLUS] = {
            {'E', 7},
            {'T', 0},
            {'F', 0}
        };
        goTo[Terminal::MULTIPLY] = {
            {'E', 0},
            {'T', 8},
            {'F', 0}
        };
        goTo[Terminal::LEFT_PAREN] = {
            {'E', 0},
            {'T', 0},
            {'F', 9}
        };
        goTo[Terminal::RIGHT_PAREN] = {
            {'E', 0},
            {'T', 0},
            {'F', 0}
        };
        goTo[Terminal::ID] = {
            {'E', 0},
            {'T', 0},
            {'F', 0}
        };
        goTo[Terminal::END_OF_INPUT] = {
            {'E', 0},
            {'T', 0},
            {'F', 0}
        };
    }

    bool performCLRParsing(const string& input) {
        stack<int> stateStack;
        stack<Symbol> symbolStack;
        stateStack.push(0);

        size_t index = 0;
        while (index < input.size()) {
            int currentState = stateStack.top();
            char currentChar = input[index];
            SymbolType currentCharType = getSymbolType(currentChar);
            Terminal currentTerminal = getTerminal(currentCharType, currentChar);

            string actionEntry = action[currentTerminal][currentState];
            if (actionEntry.empty()) {
                cout << "Error: Invalid input\n";
                return false;
            }

            if (actionEntry[0] == 's') {
                int nextState = stoi(actionEntry.substr(1));
                stateStack.push(nextState);
                Symbol symbol;
                symbol.type = SymbolType::TERMINAL;
                symbol.terminal = currentTerminal;
                symbolStack.push(symbol);
                index++;
            } else if (actionEntry[0] == 'r') {
                int productionIndex = stoi(actionEntry.substr(1));
                const Production& production = productions[productionIndex];
                int popCount = production.rhs.size();

                for (int i = 0; i < popCount; i++) {
                    stateStack.pop();
                    symbolStack.pop();
                }

                Symbol lhsSymbol;
                lhsSymbol.type = SymbolType::NON_TERMINAL;
                lhsSymbol.terminal = static_cast<Terminal>(production.lhs);
                symbolStack.push(lhsSymbol);

                int newState = goTo[currentTerminal][stateStack.top()];
                stateStack.push(newState);
            } else if (actionEntry == "acc") {
                cout << "Input accepted\n";
                return true;
            }
        }

        cout << "Error: Invalid input\n";
        return false;
    }

    SymbolType getSymbolType(char symbol) {
        if (symbol == 'E' || symbol == 'T' || symbol == 'F') {
            return SymbolType::NON_TERMINAL;
        }
        return SymbolType::TERMINAL;
    }

    Terminal getTerminal(SymbolType symbolType, char symbol) {
        if (symbolType == SymbolType::TERMINAL) {
            switch (symbol) {
                case '+':
                    return Terminal::PLUS;
                case '*':
                    return Terminal::MULTIPLY;
                case '(':
                    return Terminal::LEFT_PAREN;
                case ')':
                    return Terminal::RIGHT_PAREN;
                case 'i':
                    return Terminal::ID;
                default:
                    return Terminal::END_OF_INPUT;
            }
        }
        return Terminal::END_OF_INPUT;
    }
};

int main() {
    CLRParser parser;
    string input = "(i * i) + i * (i + i)";
    parser.performCLRParsing(input);

    return 0;
}

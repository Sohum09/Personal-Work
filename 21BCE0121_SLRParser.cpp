#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

enum SymbolType {
    TERMINAL,
    NON_TERMINAL
};

enum NonTerminal {
    Q, A, B
};

enum Terminal {
    a, b, END_OF_INPUT
};

struct Symbol {
    SymbolType type;
    union {
        NonTerminal nonTerminal;
        Terminal terminal;
    } value;
};

struct ActionEntry {
    char actionType;
    int actionValue;
};

struct ParsingTable {
    unordered_map<int, unordered_map<Terminal, ActionEntry>> action;
};

ParsingTable buildParsingTable() {
    ParsingTable parsingTable;

    parsingTable.action[0][a] = {'S', 3};
    parsingTable.action[0][b] = {'S', 4};
    parsingTable.action[0][END_OF_INPUT] = {'R', 2};
    parsingTable.action[1][END_OF_INPUT] = {'A', 0};
    parsingTable.action[2][a] = {'R', 4};
    parsingTable.action[2][b] = {'R', 4};
    parsingTable.action[2][END_OF_INPUT] = {'R', 4};
    parsingTable.action[3][a] = {'S', 3};
    parsingTable.action[3][b] = {'S', 4};
    parsingTable.action[3][END_OF_INPUT] = {'R', 1};
    parsingTable.action[4][a] = {'R', 6};
    parsingTable.action[4][b] = {'R', 6};
    parsingTable.action[4][END_OF_INPUT] = {'R', 6};

    return parsingTable;
}

bool performSLRParsing(const string& input) {
    ParsingTable parsingTable = buildParsingTable();

    stack<int> stateStack;
    stack<Symbol> symbolStack;
    stateStack.push(0);

    int inputIndex = 0;

    while (true) {
        int currentState = stateStack.top();
        Symbol currentSymbol;

        if (inputIndex < input.length()) {
            char c = input[inputIndex];

            if (c == 'a')
                currentSymbol = {TERMINAL, {.terminal = a}};
            else if (c == 'b')
                currentSymbol = {TERMINAL, {.terminal = b}};
            else
                return false;  // Invalid input character

            inputIndex++;
        } else {
            currentSymbol = {TERMINAL, {.terminal = END_OF_INPUT}};
        }

        ActionEntry actionEntry = parsingTable.action[currentState][currentSymbol.value.terminal];

        if (actionEntry.actionType == 'S') {
            stateStack.push(actionEntry.actionValue);
            symbolStack.push(currentSymbol);
        } else if (actionEntry.actionType == 'R') {
            int productionIndex = actionEntry.actionValue;
            int productionSize;

            switch (productionIndex) {
                case 1: productionSize = 3; break;
                case 2: productionSize = 2; break;
                case 3: productionSize = 2; break;
                case 4: productionSize = 1; break;
                case 6: productionSize = 1; break;
                default: return false;  // Invalid production index
            }

            for (int i = 0; i < productionSize; i++) {
                stateStack.pop();
                symbolStack.pop();
            }

            currentState = stateStack.top();
            Symbol nonTerminalSymbol;

            switch (productionIndex) {
                case 1: nonTerminalSymbol = {NON_TERMINAL, {.nonTerminal = Q}}; break;
                case 2: nonTerminalSymbol = {NON_TERMINAL, {.nonTerminal = A}}; break;
                case 3: nonTerminalSymbol = {NON_TERMINAL, {.nonTerminal = B}}; break;
                default: return false;  // Invalid production index
            }

            symbolStack.push(nonTerminalSymbol);

            ActionEntry goToEntry = parsingTable.action[currentState][nonTerminalSymbol.value.terminal];

            if (goToEntry.actionType != 'G') {
                return false;  // Invalid action entry
            }

            stateStack.push(goToEntry.actionValue);
        } else if (actionEntry.actionType == 'A') {
            return true;  // Parsing succeeded
        } else {
            return false;  // Parsing failed
        }
    }
}

int main() {
    string input = "abbab";

    if (performSLRParsing(input)) {
        cout << "Parsing succeeded." << endl;
    } else {
        cout << "Parsing failed." << endl;
    }

    return 0;
}

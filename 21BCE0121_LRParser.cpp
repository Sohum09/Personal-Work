#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char stack[50];
int top = -1;

void push(char c) {
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (top != -1) {
        c = stack[top];
        top--;
        return c;
    }
    return 'x';
}

void printStack() {
    cout << "\n\t\t\t $";
    for (int i = 0; i <= top; i++)
        cout << stack[i];
}

int main() {
    ifstream file("21BCE0121_Input.txt");
    if (!file) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    string inStr;
    if (!getline(file, inStr)) {
        cout << "Failed to read the file." << endl;
        file.close();
        return 1;
    }

    file.close();

    cout << "\nInput: " << inStr;
    int l = inStr.length();
    cout << "\n\t\t $";
    for (int i = 0; i < l; i++) {
        if (inStr[i] == 'i' && inStr[i + 1] == 'd') {
            inStr[i] = ' ';
            inStr[i + 1] = 'E';
            printStack();
            cout << "id";
            push('E');
            printStack();
        } else if (inStr[i] == '+' || inStr[i] == '-' || inStr[i] == '*' || inStr[i] == '/') {
            push(inStr[i]);
            printStack();
        }
    }
    printStack();
    while (top >= 0) {
        char popper = pop();
        if (popper == 'x') {
            cout << "\n\t\t\t $";
            break;
        }
        if (popper == '+' || popper == '-' || popper == '*' || popper == '/') {
            char pusher = pop();
            if (pusher != 'E') {
                cout << "error in parsing" << endl;
                return 1;
            } else {
                push('E');
                printStack();
            }
        }
    }
    return 0;
}

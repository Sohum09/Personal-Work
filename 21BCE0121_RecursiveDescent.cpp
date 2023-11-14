/*
Q -> QAB | Ab
A -> Ab | B
B -> a | b

Convert to right recursion:
Q -> AbX
X -> ABX | null
A -> BY
Y -> bY | null
B -> a | b
*/
#include <iostream>
#include <string>

using namespace std;

string input;
size_t index = 0;
bool success = true;

void match(char expected) {
    if (input[index] == expected) {
        index++;
    } else {
        success = false;
    }
}

void Q();
void X();
void A();
void Y();
void B();

void Q() {
    A();
    B();
    X();
}

void X() {
    if (input[index] == 'a' || input[index] == 'b') {
        B();
        X();
    }
}

void A() {
    B();
    Y();
}

void Y() {
    if (input[index] == 'b') {
        match('b');
        Y();
    }
}

void B() {
    if (input[index] == 'a' || input[index] == 'b') {
        match(input[index]);
    } else {
        success = false;
    }
}

int main() {
    cout << "Enter an input string: ";
    cin >> input;

    Q();

    if (success && index == input.length()) {
        cout << "Input successfully parsed!" << endl;
    } else {
        cout << "Parsing failed." << endl;
    }

    return 0;
}
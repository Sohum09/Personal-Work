#include <iostream>
#include <string>
using namespace std;

int main() {
    string greeting, lol="John Doe";
    cout << "\nType a string: ";
    //"cin >> greeting;" is not applicable for multiword strings
    getline(cin, greeting);
    cout << "\n" << greeting.append(lol) << " " << greeting.length();
    cout << "\n" << greeting[0] << greeting[greeting.length()-1];
    greeting[0] = 's';
    cout << "\n" << greeting;
    return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

string input;
int n;

string getNextToken(){
    while(n < input.length() && isspace(input[n]))
        n++;
    if(n < input.length()){
        string token;
        if(isalnum(input[n])){
            while(n < input.length() && (isalpha(input[n]) || isdigit(input[n])))
                token += input[n++];
            return token;
        }
    }
    else
        return string(1, input[n++]);
}

void match(const string& expected){
    string token = getNextToken();
    if(token != expected)
        cout << "Parsing failed." << endl;
}

void parseX(); 
void parseT(); 
void parseZ(); 
void parseF(); 

void parseE(){
    parseT();
    parseX();
}

void parseT(){
    parseF();
    parseZ();
}

void parseX(){
    if(n < input.length()){
        string token = getNextToken();
        if(token == "*"){
            parseT();
            parseX();
        }
        else
            n -= token.length();
    }
}


void parseZ(){
    if(n < input.length()){
        string token = getNextToken();
        if(token == "+"){
            parseF();
            parseZ();
        }
        else
            n -= token.length();
    }
}

void parseF(){
    if(n < input.length()){
        string token = getNextToken();

        if(token == "("){
            parseE();
            match(")");
        }
        else if(token == "id" && token.length()==2){}
        else
            cout << "Parsing failed." << endl;
    }
}

int main(){
    ifstream file("TestFile.txt");
    string line;

    while(getline(file, line)){
        input = line;
        n = 0;
        parseE();

        string nextLine = getNextToken(); 
        if (nextLine.empty()) 
            cout << "Parsing successful." << endl; 
        else 
            cout << "Parsing failed." << endl; 
    }
    return 0;
}
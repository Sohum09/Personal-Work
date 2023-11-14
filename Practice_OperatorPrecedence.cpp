#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char *input;
int i = 0;
char lasthandle[6], stack[50], handles[][5] = {")E(", "E*E", "E+E", "i", "E^E"};
int top = 0, l;
char prec[6][6] = { 
 /*       +    *    i    (    )    $ */ 
 /* + */ '>', '<', '<', '<', '>', '>', 
 /* * */ '>', '>', '<', '<', '>', '>', 
 /* i */ '>', '>', 'e', 'e', '>', '>', 
 /* ( */ '<', '<', '<', '<', '>', 'e', 
 /* ) */ '>', '>', 'e', 'e', '>', '>', 
 /* $ */ '<', '<', '<', '<', '<', '>', 
}; 
int getindex(char c)
{
    switch (c)
    {
    case '+':
        return 0;
    case '*':
        return 1;
    case 'i':
        return 2;
    case '(':
        return 3;
    case ')':
        return 4;
    case '$':
        return 5;
    }
    return -1;
}
int shift()
{
    stack[++top] = *(input + i++);
    stack[top + 1] = '\0';
    return 0;
}
int reduce()
{
    int len, found, t;
    int i = 0;
    while (i < 5)
    {
        len = strlen(handles[i]);
        if (stack[top] == handles[i][0] && top + 1 >= len)
        {
            found = 1;
            for (t = 0; t < len; t++)
            {
                if (stack[top - t] != handles[i][t])
                {
                    found = 0;
                    break;
                }
            }
            if (found == 1)
            {
                stack[top - t + 1] = 'E';
                top = top - t + 1;
                strcpy(lasthandle, handles[i]);
                stack[top + 1] = '\0';
                return 1; // successful reduction
            }
        }
        i++;
    }
    return 0;
}
void dispstack()
{
    int j = 0;
    while (j <= top)
    {
        cout << stack[j];
        j++;
    }
}
void display_input()
{
    for (int j = i; j < l; j++)
        cout << *(input + j);
}
int main()
{
    input = new char[50];
    ifstream inputFile;
    inputFile.open("labL3q3.txt");
    inputFile >> input;
    inputFile.close();
    input = strcat(input, "$");
    l = strlen(input);
    strcpy(stack, "$");
    cout << "\nSTACK\tINPUT\tACTION";
    while (i <= l)
    {
        shift();
        cout << "\n";
        dispstack();
        cout << "\t";
        display_input();
        cout << "\tShift";
        if (prec[getindex(stack[top])][getindex(input[i])] == '>')
        {
            while (reduce())
            {
                cout << "\n";
                dispstack();
                cout << "\t";
                display_input();
                cout << "\tReduced: E->" << lasthandle;
            }
        }
    }
    if (strcmp(stack, "$E$") == 0)
        cout << "\nAccepted";
    else
        cout << "\nNot Accepted";
    delete[] input;
    return 0;
}
//Basic outline of a stack class
#include<iostream>
using namespace std;

class Stack{
    enum{max=10};
    int stack[max];
    int top;
    public:
    Stack(): top(0) {}
    void push(int s){
        stack[++top] = s; //Pushing the element into the stack
    }
    int pop(){
        return stack[top--]; //Popping out the element from the stack
    }
};

int main(){
    Stack s1;
    s1.push(11);
    s1.push(22);
    cout << s1.pop() << endl;
    cout << s1.pop();
}
/*
#include<iostream>

class Test{
    //Random operator shenanigans
};

int main(){
    Test *ptr, t1;
    ptr = &t1;
    t1++;
    ptr++; //Posible to ignore pointer arithmetic here, the operator would act like a normal unary operator.
    //Would be okay if it were "Test *ptr = new Test[5];", THEN pointer arithmetic would apply.
}
*/
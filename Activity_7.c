//Demo on Pass by Reference
#include<stdio.h> 
void swap(int *i, int *j){
    int *temp;
    *temp = *i;
    *i = *j;
    *j = *temp;
}

int main(){
    int i, j;
    printf("Enter two numbers i & j:\n");
    scanf("%d", &i);
    scanf("%d", &j);
    printf("The original pointers: *i = %d, *j = %d", i, j);
    swap(&i, &j);
    printf("The swapped pointers: *i = %d, *j = %d", i, j);
    return 0;
}
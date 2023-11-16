//Q19.
#include <stdio.h>
#include <stdlib.h>

int main(){
    int hr, min, bill=0;

    printf("Enter Hours spent browsing: ");
    scanf("%d", &hr);
    printf("Enter Minutes spent browsing: ");
    scanf("%d", &min);

    if(hr>7 || min>59)
        printf("\nInvalid Input!");
    else{
        if(hr>=5)
            bill += 200;
        bill += hr*50 + min;

        printf("\nTotal Bill: Rs %d", bill);
    }

    return 0;
}
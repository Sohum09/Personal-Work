//Q16.
#include <stdio.h>
#include <string.h>

int main(){
    char alpha[] = "ABCDEF";
    int cnt=1, i, j;

    for(i=strlen(alpha)-1; i>=0; i--){
        for(j=0; j<=i; j++)
            printf("%c", alpha[j]);
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<6; i++){
        for(j=0; j<=i; j++)
            printf("%d", cnt);
        cnt++;
        printf("\n");
    }

    return 0;
}
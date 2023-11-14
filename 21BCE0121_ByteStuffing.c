#include <stdio.h>
#include <string.h>

int main(){
    char frame[50][50], str[50][50];
    char esc[10], flag[10];
    strcpy(flag, "f");
    strcpy(esc, "e");

    int i, k=0, n;
    strcpy(frame[k++], flag);

    printf("Enter length of string: ");
    scanf("%d", &n);
    printf("Enter byte sequences: \n");
    for(i=0; i<=n; i++)
        gets(str[i]);
    printf("You entered: \n");
    for(i=0; i<n; i++)
        puts(str[i]);
    for(i=0; i<n; i++){
        if(strcmp(str[i], flag)!=0 && strcmp(str[i], esc)!=0)
            strcpy(frame[k++], str[i]);
        else{
            strcpy(frame[k++], esc);
            strcpy(frame[k++], str[i]);
        }
    }
    strcpy(frame[k++], flag);
    printf("\nSender receives the following byte-stuffed data: ");
    for(i=0; i<k; i++)
        printf("%s\t", frame[i]);
    return 0;
}
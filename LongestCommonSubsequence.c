#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a>b)? a: b;
}

int main(){
    char ch1[] = "abaaba";
    char ch2[] = "babbab";
    int x = strlen(ch1);
    int y = strlen(ch2);

    int i, j;
    int mat[10][10];

    for(i=0; i<=x; i++)
        mat[i][0] = 0;
    for(i=0; i<=y; i++)
        mat[0][i] = 0;

    for(i=1; i<=x; i++){
        for(j=1; j<=y; j++){
            if(ch1[i-1]==ch2[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    

    for(i=0; i<=x; i++){
        for(j=0; j<=y; j++)
            printf("%d\t", mat[i][j]);
        printf("\n");
    }

    printf("\n\nLength of longest common subsequence: %d", mat[i-1][j-1]);
    return 0;
}

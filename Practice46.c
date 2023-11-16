//Q18.
#include <stdio.h>

int main(){

    float C, N, M, choco;
    scanf("%f", &C);
    scanf("%f", &N);
    scanf("%f", &M);

    choco = (N/C) + M;
    printf("Chocolates he got: %f", choco);
    return 0;
}
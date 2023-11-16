//Q8.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int accident[50];
    int accDeviation[50];
    int n, sum=0;
    float avg;
    printf("Enter no. of days: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nAccidents on day %d: ",i+1);
        scanf("%d", &accident[i]);
        sum += accident[i];
    }
    avg = (float) sum/n;

    printf("\nAverage of all accidents per day: %f", avg);

    for(int i=0; i<n; i++){
        accDeviation[i] = abs(accident[i] - (int)(avg));
        printf("\nAccident Deviation from mean on day %d: %d", i+1, accDeviation[i]);
    }
    return 0;
}
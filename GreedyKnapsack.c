#include<stdio.h>

#define MAX 5

struct Item{
    int id;
    int value;
    int weight;
    float frac;
}bag[MAX];

void sort(){
    int i, j;
    struct Item temp;
    for(i=0; i<MAX; i++)
        for(j=0; j<MAX-1-i; j++)
            if(bag[j].frac<bag[j+1].frac){
                temp=bag[j];
                bag[j]=bag[j+1];
                bag[j+1]=temp;
            }
}

void greedyKnapsack(int W){
    int weight=0;
    float x[MAX];
    for(int i=0; i<MAX; i++)
        x[i]=0;
    for(int i=0; i<MAX; i++){
        if(W > (bag[i].weight+weight)){
            x[bag[i].id]=1;
            weight += bag[i].weight;
        }
        else{
            x[bag[i].id] = ((float)(W-weight)/bag[i].weight);
            weight=W;
            break;
        }
    }
    printf("\nValues of knapsack: \n");
    for(int i=0; i<MAX; i++)
        printf("%f ", x[i]);
}

int main(){
    for(int i=0; i<MAX; i++){
        bag[i].id = i;
        printf("\nEnter weight for %d: ", i+1);
        scanf("%d", &bag[i].weight);
        printf("\nEnter value for %d: ", i+1);
        scanf("%d", &bag[i].value);
        bag[i].frac = (float)bag[i].value/bag[i].weight;
    }
    printf("ID\tWeight\tValue\tFraction");
    for(int i=0; i<MAX; i++){
        printf("\n%d\t%d\t%d\t%f", bag[i].id, bag[i].weight, bag[i].value, bag[i].frac);
    }
    sort();
    printf("\nID\tWeight\tValue\tFraction");
    for(int i=0; i<MAX; i++){
        printf("\n%d\t%d\t%d\t%f", bag[i].id, bag[i].weight, bag[i].value, bag[i].frac);
    }
    greedyKnapsack(20);
    return 0;
}
//Pointers with arrays
#include <stdio.h>
int max=20;
void get_size(int *size){
    do{
        printf("How many numbers? ");
        scanf("%d", size);
    }while(*size<0 || *size>max);
}

void get_array(int array[], int size){
    int i;
    for (i=0; i<size; i++){
        scanf("%d", array+i);
    }
}

void print_array(int array[], int size, int message){
    int i;
    if(message==0)
        printf("\nThe original array: ");
    else if(message==1)
        printf("\nThe sorted array: ");
    for(i=0; i<size; i++)
        printf("%d ", array[i]);
}
void element_swap(int array[], int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void sort (int array[], int size){
    int i, j;
    for(i=0; i<size; i++)
        for(j=0; j<size-1-i; j++)
            if(array[j]>array[j+1])
                element_swap(array, j, j+1);
}

int main(){
    int numbers[max], array_size;
    get_size(&array_size);
    get_array(numbers, array_size);

    //Pre-sort:
    print_array(numbers, array_size, 0);
    sort(numbers, array_size);

    //Post-sort:
    print_array(numbers, array_size, 1);
    return 0;
}
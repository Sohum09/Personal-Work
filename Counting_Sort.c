#include<stdio.h>
#include<stdlib.h>

void countingSort(int arr[], int size, int max)
{
    int count[10], output[size], i, key;
    for(i=0; i<10; i++)
        count[i]=0;
        
    for(i=0; i<size; i++) //Count every instance of an element in the input array
    {
        key = arr[i];
        count[key]++;
    }

    for(i=0; i<max+1; i++) //Store the cumulative sum of each element in the array
        count[i] += count[i-1];

    for(i=size-1; i>=0; i--)
    {
        key = arr[i];
        count[key]--;
        output[count[key]] = arr[i];
    }

    for(i=0; i<size; i++)
        printf("%d ", output[i]);
}

int main()
{
    int arr[12] = {1, 4, 2, 5, 6, 3, 5, 6, 2, 6, 9, 8};
    countingSort(arr, 12, 9);
    return 0;
}
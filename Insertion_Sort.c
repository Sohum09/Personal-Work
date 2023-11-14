#include<stdio.h>
int main()
{
    int num, i, j, temp=0;
    scanf("%d", &num);
    int arr[num];

    for(i=0; i<num; i++)
        scanf("%d", &arr[i]);
    
    for(i=0; i<num; i++) //Pre Insertion-Sort
        printf("%d ", arr[i]);
    printf("\n");

    for(i=1; i<num; i++)
    {
        temp = arr[i];
        j=i-1;
        while(j>0 && arr[j]>temp) //Insert by shifting the array whenever the number is smaller than the temp
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for(i=0; i<num; i++) //Post Insertion-Sort
        printf("%d ", arr[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int arr[100];
int capacity;
int heap_size;
void getArray()
{
    printf("Enter the array:\n");
    for (int i=0; i<capacity; i++)
        scanf("%d", &arr[i]);
}
void printArray()
{
    for (int i=0; i<=heap_size-1; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int parentNode(int i)
{
    return (i-1)/2;
}
int leftNode(int i)
{
    return (2*i+1);
}
int rightNode(int i)
{
    return (2*i+2);
}
int getMin()
{
    return arr[0];
}
void minHeapify(int i)
{
    int temp;
    int l = leftNode(i);
    int r = rightNode(i);
    int minNode = i;
    if (l < heap_size && arr[l] < arr[i])
        minNode = l;
    if (r < heap_size && arr[r] < arr[minNode])
        minNode = r;
    if (minNode != i)
    {
        temp = arr[i];
        arr[i] = arr[minNode];
        arr[minNode] = temp;
        minHeapify(minNode);
    }
}
int extractMin()
{
    if (heap_size<=0)
        return INT_MAX;
    if (heap_size==1)
    {
        heap_size--;
        return arr[0];
    }
    // Store the minimum value, and remove it from heap
    int root = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    minHeapify(0);
    return root;
}
void heapSort()
{
    int temp[capacity];
    for (int j = 0; j <= capacity - 1; j++)
    {
        temp[j] = extractMin();
        printf("%d ", temp[j]);
    }
    printf("\n");
}
int main()
{
    printf("Enter Array size: ");
    scanf("%d", &capacity);
    getArray();
    heap_size = capacity;
    printf("\nOriginal array:\n");
    printArray();
    for (int i=capacity/2-1; i>=0; i--)
        minHeapify(i);
    printf("\nHeapified array:\n");
    printArray();
    printf("\nSorted array:\n");
    heapSort();
}
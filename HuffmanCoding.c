#include <stdio.h>
#include <stdlib.h>

int MAX_TREE_HT = 100;

//Huffman Tree Node:
struct MinHeapNode{
	char data;
	int freq;
	struct minHeapNode *left, *right;
};

//Huffman tree (min-heap):
struct MinHeap{
	int size;
	int capacity;
	struct MinHeapNode **array;
};

//Allocating new min heap node:
struct MinHeapNode* newNode(char data, int freq){
	struct MinHeapNode *temp = malloc(sizeof(struct MinHeapNode));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

//Creating a new min-heap of given capacity:
struct MinHeap* createMinHeap(int capacity){
	struct MinHeap* minHeap = malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}

//To perform swapping of node values:
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

//Standard heapify code:
void minHeapify(struct MinHeap *minHeap, int idx){
	int smallest = idx, left = 2*idx+1, right = 2*idx+2;
	if(left<minHeap->size && minHeap->array[left]<minHeap->array[smallest])
		smallest = left;
	if(left<minHeap->size && minHeap->array[right]<minHeap->array[smallest])
		smallest = right;
	if(smallest!=idx)
	{
		swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}

//Find if minHeap size = 1
int isSizeOne(struct MinHeap* minHeap){
	return (minHeap->size==1);
}

//Extract min value from min-heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
	struct MinHeapNode *temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size-1];
	--minHeap->size;
	minHeapify(minHeap, 0);
}

//Inserting a node into the minHeap:
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size-1;
    while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq){
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

//Building the min-heap:
void buildMinHeap(struct MinHeap* minHeap){
    int n = minHeap->size-1;
    for(int i = (n-1)/2; i>=0; i--)
        minHeapify(minHeap, i);
}

//Print the array tbh
void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct MinHeapNode* root){
    return !(root->left) && !(root->right);
}

struct MinHeap* buildAndCreateMinHeap(char data[], unsigned size, int freq[]){
    struct MinHeap *minHeap = createMinHeap(size);

    for(int i=0; i<size; i++)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;

    buildMinHeap(minHeap);
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* MinHeap = buildAndCreateMinHeap(data, size, freq);

    while(!isSizeOne(MinHeap)){
        left = extractMin(MinHeap);
        right = extractMin(MinHeap);

        top = newNode('$', left->data+right->data);
        top->left = left;
        top->right = right;

        insertMinHeap(MinHeap, top);
    }
    return extractMin(MinHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(isLeaf(root)){
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void HuffmanCode(char data[], int freq[], int size){
    struct MinHeap* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top=0;
    printCodes(root, arr, top);
}

int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCode(arr, freq, size);
 
    return 0;
}
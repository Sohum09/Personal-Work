#include<stdio.h>
#include<stdlib.h>

struct course{
    int marks;
    char subject[30];
};

int main(){
    struct course *ptr;
    int noOfRecords;
    printf("Enter no. of records: ");
    scanf("%d", &noOfRecords);
    ptr = (struct course*)malloc(noOfRecords*sizeof(struct course)); //Dynamic memory allocation
    
    for(int i=0; i<noOfRecords; i++){
        printf("\nEnter subject and marks: ");
        scanf("%s %d", (ptr+i)->subject, &(ptr+i)->marks);
    }

    //Displaying Information
    for(int i=0; i<noOfRecords; i++){
        printf("\n%d %s", (ptr+i)->marks, (ptr+i)->subject);
    }

    free(ptr);
    return 0;
}
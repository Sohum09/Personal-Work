//Q9.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[100];
    char regno[50];
    char block[10];
    int roomNo;
    int stuCnt;
}stu1, stu2;



void initializeStudentDetails(struct Student s){
    printf("\nEnter name of student: ");
    scanf("%s", &s.name);
    printf("Enter registration no.: ");
    scanf("%s", &s.regno);
    printf("Enter count no. (Student entry No.): ");
    scanf("%d", &s.stuCnt);
}

void allocateBlockAndRoom(struct Student s){
    int blockNum = s.stuCnt/1000;
    int roomAllocate = s.stuCnt%1000;

    switch(blockNum){
        case 0:
        s.block[0] = 'A';
        s.roomNo = roomAllocate;
        break;

        case 1:
        s.block[0] = 'B';
        s.roomNo = roomAllocate;
        break;

        case 2:
        s.block[0] = 'C';
        s.roomNo = roomAllocate;
        break;

        case 3:
        s.block[0] = 'D';
        s.roomNo = roomAllocate;
        break;

        case 4:
        s.block[0] = 'E';
        s.roomNo = roomAllocate;
        break;

        default:
        s.block[0] = 'R';
        s.roomNo = 0;
    }
}

void display(struct Student s){
    printf("\n\nRegistration No.: %s", s.regno);
    printf("\nBlock Allocated: %c", s.block[0]);
    printf("\nRoom Number: %d", s.roomNo);
}

int main(){
    initializeStudentDetails(stu1);
    allocateBlockAndRoom(stu1);
    display(stu1);

    printf("\n\n\n");

    initializeStudentDetails(stu2);
    allocateBlockAndRoom(stu2);
    display(stu2);

    return 0;
}
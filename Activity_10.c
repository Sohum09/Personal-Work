#include<stdio.h>
struct student{
    char name[50];
    int roll;
    float marks;
}s[5];

int main(){
    int i;
    printf("Enter information on each student's credentials: ");
    for(i=0; i<5; i++){
        s[i].roll = i+1;
        printf("\nFor roll no. %d: ", s[i].roll);
        printf("\nStudent name: ");
        scanf("%s", &s[i].name);
        printf("\nStudent Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("Display information: ");

    for (i = 0; i < 5; ++i) {
        printf("\nRoll number: %d\n", i + 1);
        printf("First name: ");
        puts(s[i].name);
        printf("Marks: %.1f", s[i].marks);
        printf("\n");
    }
    return 0;
}

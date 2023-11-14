#include<stdio.h>

struct Time{
    int seconds;
    int minutes;
    int hours;
};

void differenceBetweenTimePeriod(struct Time start, struct Time stop, struct Time *diff);

int main(){
    struct Time startTime, stopTime, diff;

    printf("Enter the start time:\n");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    printf("Enter the stop time:\n");
    scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

    differenceBetweenTimePeriod(startTime, stopTime, &diff); //Pass by reference

    printf("Difference: %d:%d:%d - ", startTime.hours, startTime.minutes, startTime.seconds);
    printf("%d:%d:%d = ", stopTime.hours, stopTime.minutes, stopTime.seconds);
    printf("%d:%d:%d", diff.hours, diff.minutes, diff.seconds);
    return 0;
}

void differenceBetweenTimePeriod(struct Time start, struct Time stop, struct Time *diff){
    while(stop.seconds > start.seconds){ //For carry over when the subtracting number on top is less than the one at bottom
        start.minutes--;
        start.seconds += 60;
    }
    diff->seconds = start.seconds - stop.seconds;

    while(stop.minutes > stop.minutes){ //For carry over when the subtracting number on top is less than the one at bottom
        start.hours--;
        start.minutes += 60;
    }
    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;
}
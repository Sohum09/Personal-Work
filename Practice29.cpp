#include<iostream>
using namespace std;

class Time{
    private:
    int hours, minutes, seconds;
    
    public:
    Time(): hours(0), minutes(0), seconds(0) {}
    Time(int h, int min, int sec): hours(h), minutes(min), seconds(sec) {}
    void display(){
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
    Time add(const Time t1, const Time t2){
        Time sum;

        sum.seconds = t1.seconds + t2.seconds;
        if(sum.seconds>=60){ //Carry action
            sum.seconds -= 60;
            sum.minutes++;
        }

        sum.minutes = t1.minutes + t2.minutes;
        if(sum.minutes>=60){ //Carry action
            sum.minutes -= 60;
            sum.hours++;
        }

        sum.hours = t1.hours + t2.hours;
        return sum;
    }
};

int main(){
    Time sum;
    int h, min, sec;
    cout << "Enter time t1 in HH:MM:SS - " << endl;
    cin >> h;
    cin >> min;
    cin >> sec;
    Time t1(h, min, sec);
    cout << "Enter time t2 in HH:MM:SS - " << endl;
    cin >> h;
    cin >> min;
    cin >> sec;
    Time t2(h, min, sec);

    sum = sum.add(t1, t2);
    sum.display();

    return 0;
}
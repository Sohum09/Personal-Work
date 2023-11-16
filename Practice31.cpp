#include<iostream>
using namespace std;

class Fraction{
    private:
    int num, dem, GCD;

    public:
    Fraction(): GCD(1) {}
    void enterFrac(){
        cout << "\nEnter fraction: ";
        cin >> num;
        cin >> dem;
    }

    void findGCD(int n, int d){
        int larg = (n > d)? n : d;
        int smol = (n > d)? d : n;
        for(int i=1; i<=smol; i++)
            GCD = (smol%i==0 && larg%i==0)? i: GCD;
    }

    void add(Fraction frac1, Fraction frac2){
        num = frac1.num*frac2.dem + frac2.num*frac1.dem;
        dem = frac1.dem*frac2.dem;
        findGCD(num, dem);
        if(GCD>1){
            num /= GCD;
            dem /= GCD;
        }
    }

    void display(){
        cout << "\nThe sum: " << num << "/" << dem << endl;
    }
};

int main(){
    Fraction frac1, frac2, sumFrac;
    cout << "Enter the two fractions accordingly:";
    frac1.enterFrac();
    frac2.enterFrac();
    sumFrac.add(frac1, frac2);
    sumFrac.display();
}
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string words[n], wrd="";

    for(int i=0; i<n; i++){
        cin >> wrd;
        words[i] = wrd;
    }
    char ch1, ch;
    for(int i=0; i<n; i++){
        ch1 = words[i].at(0);
        for(int j=1; j<words[i].length(); j++){
            ch = words[i].at(j);
            if(ch1==ch || ch1==(ch-32)){
                cout << words[i] << endl;
                break;
            }
        }
    }
    return 0;
}
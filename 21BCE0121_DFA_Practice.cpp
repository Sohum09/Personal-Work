#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

int isA(string str){
    if(str.compare("a")==0)
        return 1;
    else
        return 0;
}

int isABB(string str){
    if(str.compare("abb")==0)
        return 1;
    else
        return 0;
}

int isAStarBPlus(string str, int n){
    if(str[0]=='a'){
        int i=0;
        while(str[i]=='a' && i<n)
            i++;
        if(i==n){return 0;}
        else if(str[i]!='b'){return 0;}
        else if(i<n)
            while (i<n)
                if(str[i++]!='b'){return 0;}
        return 1;
    }
    else if(str[0]=='b'){
        int i=0;
        while(i<n)
            if(str[i++]!='b'){return 0;}
        return 1;
    }
    else
        return 0;
}

int main(){
    fstream FileName;
    FileName.open("21BCE0121_2.txt", ios::in);
    if (!FileName)
    {
        cout << "File doesn't exist.";
    }
    else
    {
        string x, wrd = "";
        while (getline(FileName, x))
        {
            for (int i = 0; i < x.length(); i++)
            {
                if(x[i] >= 'a' && x[i] <= 'z')
                    wrd+=x[i];
                else if (x[i]=='/'){
                    if(isA(wrd)){cout << wrd << " is accepted by the machine for a\n";}
                    else if(isABB(wrd)){cout << wrd << " is accepted by the machine for abb\n";}
                    else if(isAStarBPlus(wrd, wrd.length())){cout << wrd << " is accepted by the machine for a*b+\n";}
                    else if(wrd!=""){ cout << wrd << " is not accepted by any machine.\n";}
                    wrd = "";
                }
                else
                    continue;
            }
        }
    }
    FileName.close();
    return 0;
}
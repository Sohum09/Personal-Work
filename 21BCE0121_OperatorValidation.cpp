#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

string removeComments(string prgm)
{
    int n = prgm.length();
    bool cnt = false;
    string res;
    for (int i = 0; i < n; i++)
    {
        if (cnt == true && prgm[i] == '*' && prgm[i + 1] == '/')
        {
            cnt = false;
            i++;
        }
        else if (cnt)
            continue;
        else if (prgm[i] == '/' && prgm[i + 1] == '*')
        {
            cnt = true;
            i++;
        }
        else
            res += prgm[i];
    }
    return res;
}

int isOper(char x){
	if(x=='+' || x== '-' || x=='*' || x=='/' || x=='.' || x=='&' || x=='|' || x=='<' || x=='>' || x=='=')
		return 1;
	return 0;
}

int operatorValidation(string str){
    if(str.compare("+")==0 || str.compare("-")==0 || str.compare("/")==0 || str.compare("*")==0 
    || str.compare("+=")==0 || str.compare("-=")==0 || str.compare("*=")==0 || str.compare("/=")==0 
    || str.compare("&&")==0 || str.compare("||")==0 || str.compare("!=")==0 || str.compare("==")==0
    || str.compare("!")==0 || str.compare(">")==0 || str.compare("<")==0 || str.compare(">=")==0 || str.compare("<=")==0 || str.compare("=")==0)
        return 1;
    return 0;
}

int main(){
    fstream FileName;
    FileName.open("21BCE0121.txt", ios::in);
    if (!FileName)
    {
        cout << "File doesn't exist.";
    }
    else
    {
        string x, x1, wrd = "";
        while (getline(FileName, x))
        {
            x1 = removeComments(x);
            for (int i = 0; i < x1.length(); i++)
            {
                if(isOper(x1[i]))
                    wrd+=x1[i];
                else if(operatorValidation(wrd) && wrd.compare("")!=0){
                    cout << wrd << " is a valid operator.\n";
                    wrd = "";
                }
                else if(!operatorValidation(x1) && wrd.compare("")!=0){
                    cout << wrd << " is not a valid operator.\n";
                    wrd = "";
                }
                else
                    continue;
            }
        }
    }
    FileName.close();
    
}
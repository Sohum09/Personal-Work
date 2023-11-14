#include <bits/stdc++.h>
using namespace std;

string removeComments(string x){
    int n = x.length();
    bool flag = false;
    string prgm = "";

    for(int i=0; i<n; i++){
        if(flag && x[i]=='*' && x[i+1]=='/'){
            flag = false;
            i++;
        }
        else if (flag)
            continue;
        else if (x[i]=='/' && x[i+1]=='*'){
            flag = true;
            i++;
        }
        else
            prgm += x[i];
    }
    
    return prgm;
}

string removeSpacesAndTabs(string x){
    int n = x.length();
    string prgm = "";

    for(int i=0; i<n; i++){
        if(x[i]=='\\' && x[i+1]=='t'){
            continue;
        }
        else if (x[i] == ' ' ){
            i++;
            continue;
        }
        else
            prgm += x[i];
    }
    return prgm;
}

int isDelimiter(char x){
	if(x=='(' || x== ')' || x==';' || x=='{' || x=='}' || x==',' || x=='[' || x==']')
		return 1;
	return 0;
}

int isOper(char x){
	if(x=='+' || x== '-' || x=='*' || x=='/' || x=='.' || x=='&' || x=='|' || x=='<' || x=='>' || x=='=')
		return 1;
	return 0;
}

int isConstant(char x){
	if(x>='0' && x<='9')
		return 1;
	return 0;
}

int isKeyword(string str){
	if(str=="for" || str=="while" || str=="char" || str=="int" || str=="break" || str=="struct" || str=="float" || str=="if" || str=="else" || str=="default" || str=="case" || str=="long" || str=="do" || str=="void" || str=="class" || str=="sizeof" || str=="friend")
		return 1;
	return 0;
}

int main(){
    fstream fileName;
    fileName.open("21BCE0121.txt", ios::in);

    stack<char> op, delim;
    vector<string> constant, keywordCnt, idCnt;
    if(!fileName){
        cout << "File not found.";
    }
    else{
        int wrdCnt=0, numCnt=0;
        string x, x1, wrd = "";

        while(getline(fileName, x)){
            x1 = removeComments(x);
            for(int i=0; i<x1.length(); i++){
                if(isOper(x1[i])){
                    op.push(x1[i]);
                    x1[i] = ' ';
                }
                else if(isDelimiter(x1[i])){
                    delim.push(x1[i]);
                    x1[i] = ' ';
                }
            }

            for(int i=0; i<x1.length(); i++){
                if((x1[i] >= 'a' && x1[i] <= 'z') || (x1[i] >= 'A' && x1[i] <= 'Z') || (x1[i] >= '0' && x1[i] <= '9') || x1[i]=='_'){
                    if(isConstant(x1[i]))
                        numCnt++;
                    wrdCnt++;
                    wrd += x1[i];
                }
                else{
                    if(numCnt==wrdCnt)
                        constant.push_back(wrd);
                    else if(isKeyword(wrd))
                        keywordCnt.push_back(wrd);   
                    else
                        idCnt.push_back(wrd);
                    wrd = "";
                    numCnt = 0;
                    wrdCnt = 0;
                }
            }
        }

        cout << "Operators: ";
        while(!op.empty()){
            cout << op.top();
            op.pop();
        }
        cout << "\nDelimiters: ";
        while(!delim.empty()){
            cout << delim.top();
            delim.pop();
        }
        cout << "\nKeywords: ";
        for(vector<string>::iterator itr = keywordCnt.begin(); itr != keywordCnt.end(); ++itr){
            cout << *itr << " ";
        }
        cout << "\nConstants: ";
        for(vector<string>::iterator itr = constant.begin(); itr != constant.end(); ++itr){
            cout << *itr << " ";
        }
        cout << "\nIdentifiers: ";
        for(vector<string>::iterator itr = idCnt.begin(); itr != idCnt.end(); ++itr){
            cout << *itr << " ";
        }
    }
    fileName.close();
}
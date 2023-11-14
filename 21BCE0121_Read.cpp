#include <iostream>                        
#include <fstream>     
#include <string> 
#include <stack>   
#include <vector>               
using namespace std;

string removeComments(string prgm){
	int n = prgm.length();
	bool cnt = false;
	string res;
	
	for(int i=0; i<n; i++){
		if(cnt==true && prgm[i]=='*' && prgm[i+1]=='/'){
			cnt = false; 
			i++;
		}
		else if(cnt)
			continue;
		else if(prgm[i]=='/' && prgm[i+1]=='*'){
			cnt = true;
			i++;
		}
		else
			res += prgm[i];
	}
	return res;
}

string removeSpacesAndTabs(string prgm){
	int n = prgm.length();
	bool cnt = false;
	string res;
	
	for(int i=0; i<n; i++){
		if(prgm[i]=='/' && prgm[i+1]=='t'){
			i++;
			continue;
		}
		else if(prgm[i]==' '){
			continue;
		}
		else
			res += prgm[i];
	}
	return res;
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

int main() {
    fstream FileName;                   
    FileName.open("21BCE0121.txt", ios::in);    
	
	stack<char> op, delim, constant;
	vector<string> keywordCnt, idCnt;

    if (!FileName) {                        
        cout<<"File doesn't exist.";          
    }
    else {
        string x, x1, res, wrd="";                     
        while (getline(FileName, x)){  
			res = removeComments(x);
			res = removeSpacesAndTabs(res);    
			x1 = removeComments(x);	               
            cout<<res;   
			for(int i=0; i<x1.length(); i++){
				if(isOper(x1[i])){op.push(x1[i]); x1[i] = ' ';}
				if(isDelimiter(x1[i])){delim.push(x1[i]); x1[i] = ' ';} 
				if(isConstant(x1[i])){constant.push(x1[i]);} 
			}               
			
			for(int i=0; i<x1.length(); i++){
				if((x1[i]>='a' && x1[i]<='z') || (x1[i]>='A' && x1[i]<='Z') || (x1[i]>='0' && x1[i]<='9')) {wrd += x1[i];}
				else if(wrd=="") {continue;}
				else if(isKeyword(wrd)) {keywordCnt.push_back(wrd); wrd="";}	
				else {idCnt.push_back(wrd); wrd="";}
			}
        }
		cout << "\n\nLexemes found by the compiler: \n";
		cout << "\nOperators: ";
		while (!op.empty()){
			cout << op.top();
			op.pop();
		}
		cout << "\nDelimiters: ";
		while (!delim.empty()){
			cout << delim.top();
			delim.pop();
		}
		cout << "\nConstants: ";
		while (!constant.empty()){
			cout << constant.top() << " ";
			constant.pop();
		}
		cout << "\nKeywords: ";
		for(vector<string>::iterator itr=keywordCnt.begin(); itr!=keywordCnt.end(); ++itr)
			cout << *itr << " ";
		cout << "\nIdentifiers: ";
		for(vector<string>::iterator itr=idCnt.begin(); itr!=idCnt.end(); ++itr)
			cout << *itr << " ";
    }
    FileName.close();                   
    return 0;
}

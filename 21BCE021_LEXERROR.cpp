#include <iostream>
#include <fstream>
#include <string>

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

int isKeyword(string str){
	if(str=="for" || str=="while" || str=="char" || str=="int" || str=="break" || str=="struct" || str=="float" || str=="if" || str=="else" || str=="default" || str=="case" || str=="long" || str=="do" || str=="void" || str=="class" || str=="sizeof" || str=="friend")
		return 1;
	return 0;
}

int isDelimiter(char x)
{
    if (x == '(' || x == ')' || x == ';' || x == '{' || x == '}' || x == ',' || x == '[' || x == ']')
        return 1;
    return 0;
}

int isOper(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '.' || x == '&' || x == '|' || x == '<' || x == '>' || x == '=')
        return 1;
    return 0;
}

int isConstant(char x)
{
    if (x >= '0' && x <= '9')
        return 1;
    return 0;
}

void checkConstantError(string str){
	if(str.length()>7)
		cout << str << " length too large! Memory overflow!";
}

int isSpecial(char x){
	if(x=='@' || x=='#' || x=='&' || x=='!' || x=='$' || x=='~')
		return 1;
	return 0;
}
void checkIdentifierError(string str){
    if(isKeyword(str))
        cout << str << " is a keyword, and hence not an identifier.";
	if(isConstant(str[0]))
		cout << str << " is not a valid identifier.";
	for(int i=0; i<str.length(); i++)
		if(isSpecial(str[i]))
			cout << str[i] << " in " << str << " is a special character, which is not allowed.";
}

int main()
{
    fstream FileName;
    FileName.open("21BCE0121.txt", ios::in);
    if (!FileName)
    {
        cout << "File doesn't exist.";
    }
    else
    {
    	int wrdCnt=0, numCnt=0;
        string x, x1, wrd = "";
        while (getline(FileName, x))
        {
            x1 = removeComments(x);
            for (int i = 0; i < x1.length(); i++)
            {
                if (isOper(x1[i]))
                    x1[i] = ' ';
                
                if (isDelimiter(x1[i]))
                    x1[i] = ' ';
                
            }
			
            for (int i = 0; i < x1.length(); i++)
            {
                if ((x1[i] >= 'a' && x1[i] <= 'z') || (x1[i] >= 'A' && x1[i] <= 'Z') || (x1[i] >= '0' && x1[i] <= '9') || x1[i]=='_' || isSpecial(x1[i]))
                {
                	if(isConstant(x1[i]))
                		numCnt++;
                    wrd += x1[i];
                    wrdCnt++;
                }
                else if (wrd == "")
                    continue;
                else{
                	if(numCnt==wrdCnt){checkConstantError(wrd); cout << "\n";}
                	else {checkIdentifierError(wrd); cout <<"\n";}
					numCnt=0; wrdCnt=0;
					wrd="";
				}
			}   		
		}
    }
    FileName.close();
    return 0;
}

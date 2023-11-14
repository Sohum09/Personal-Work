#include <iostream>
#include <cstring>
#include <string>

std::string removeComments(std::string prgm){
	int n = prgm.length();
	bool CommentCheck = false;
	int flag = 0;
	std::string res;
	
	for(int i=0; i<n; i++){
		if(CommentCheck==true && prgm[i]=='*' && prgm[i+1]=='/'){
			CommentCheck = false;
			i++;
		}
		else if(CommentCheck)
			continue;
		else if(prgm[i]=='/' && prgm[i+1]=='*'){
			CommentCheck = true;
			flag++;
			i++;
		}
		else
			res += prgm[i];
	}
	if(flag>0)
		std::cout << "Yes, it contains a comment." << std::endl;
	else
		std::cout << "No, it does not contain a comment." << std::endl;
	return res;
}

int main(){
	std::string prgm;
	std::cout << "Enter a line: ";
	getline(std::cin, prgm);
	std::cout << "Given string: " << prgm << std::endl;
	std::string res = removeComments(prgm);
	std::cout << "\nModified: " << res;
	return 0;
}

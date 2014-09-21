/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>

void print(const std::string &s){
	std::cout << s << std::endl;
}

void trim(std::string &s){ //Delete leading and trailing spaces of a string
	std::size_t len = s.size();
	if(len == 0){
		return;
	}
	std::size_t i = 0;
	while(i < len){
		if(s[i] != ' '){
			break;
		}
	}
	if(i == len){
		s = "";
		return;
	}
	s.erase(0, i); //Delete leading spaces
	len = s.size();

	std::size_t j = len - 1;
	while(j > i){
		if(s[j] != ' '){
			break;
		}
	}
	if(j != len - 1){
		s.erase(j + 1, len - j - 1); //Delete trailing spaces
	}
}

class Solution {
public:
    bool isValid(std::string s) {
		int len = s.size();
		if(len % 2 != 0){
			return false;
		}
		std::stack<char> tmp;
		for(int i = 0; i < len; ++i){
			switch(s[i]){
				case '(':
				case '[':
				case '{':
					tmp.push(s[i]);
					break;
				case ')':
					if(tmp.empty() || tmp.top() != '('){
						return false;
					}
					tmp.pop();
					break;
				case ']':
					if(tmp.empty() || tmp.top() != '['){
						return false;
					}
					tmp.pop();
					break;
				case '}':
					if(tmp.empty() || tmp.top() != '{'){
						return false;
					}
					tmp.pop();
					break;
				default:
					return false;
					break;
			}
		}
		if(tmp.empty()){
			return true;
		}else{
			return false;
		}
    }
};

int main(){
	std::string value;
	std::cin >> value;
	Solution s;
	if(s.isValid(value)){
		std::cout << "true" << std::endl;
	}else{
		std::cout << "false" << std::endl;
	}
	return 0;
}

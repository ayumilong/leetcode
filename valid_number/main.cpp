/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cctype>

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
    bool isNumber(const char *s) {
		int index = 0;
		bool hasDot = false;
		bool hasE = false;
		bool hasDigit = false;
		bool hasCharacter = false;
		bool hasDigitAfterE = false;
		while(*s != '\0'){
			bool isSpace = false;
			if(' ' == *s){
				isSpace = true;
			}
			while(' ' == *s){
				++s;
			}
			if(index == 0 && (*s == '-' || *s == '+')){
				hasCharacter = true;
				++index;
				++s;
				continue;
			}
			if(hasDigit && (*s == 'e' || *s == 'E')){
				if((*(s + 1) == '-' || *(s + 1) == '+') && *(s + 2) != '\0'){
					s += 2;
					continue;
				}
			}
			if(hasCharacter && isSpace && *s != '\0'){
				return false;
			}
			if(*s == '\0'){
				if(index == 0 || (hasE && not hasDigitAfterE)){
					return false;
				}
				break;
			}
			if(hasE && not hasDigitAfterE && isdigit(*s)){
				hasDigitAfterE = true;
			}
			if(not hasDigit && isdigit(*s)){
				hasDigit = true;
			}
			if(isdigit(*s) == 0 && *s != 'e' && *s != 'E' && *s != '.'){
				return false;
			}
			if((*s == 'e' || *s == 'E') && (index == 0 || *(s + 1) == '\0' || hasE || not hasDigit)){
				return false;
			}
			if(*s == '.' && ((*(s + 1) == '\0' && index == 0) || hasDot || hasE)){
				return false;
			}
			if(*s == '.'){
				hasDot = true;
			}
			if(*s == 'e' || *s == 'E'){
				hasE = true;
			}
			++index;
			hasCharacter = true;
			++s;
		}
		if(not hasDigit){
			return false;
		}
		return true;
    }
};

int main(){
	std::string value;
	Solution s;
	while(std::getline(std::cin, value)){
		if(s.isNumber(value.c_str())){
			std::cout << "True" << std::endl;
		}else{
			std::cout << "False" << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}

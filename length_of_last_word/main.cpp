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
    int lengthOfLastWord(const char *s) {
		if(s == NULL || *s == '\0'){
			return 0;
		}
		const char *t = s;
		while(*t != '\0'){
			++t;
		}
		while(t != s && not isalpha(*t)){//Skip the trailing space
			--t;
		}
		int len = 0;
		while(t != s && *t != ' '){//Compute the length of the last word
			++len;
			--t;
		}
		if(t == s && *t != ' '){//If the first word is the last word
			++len;
		}
		return len;
    }
};

int main(){
	std::string value;
	Solution s;
	while(std::getline(std::cin, value)){
		std::cout << s.lengthOfLastWord(value.c_str()) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

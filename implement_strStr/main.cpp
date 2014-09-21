/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

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
    char *strStr(char *haystack, char *needle) {
		int len1 = 0;
		int len2 = 0;
		char *h = haystack;
		while(*h != '\0'){
			++len1;
			++h;
		}
		char *n = needle;
		while(*n != '\0'){
			++len2;
			++n;
		}
		if(len1 < len2){
			return NULL;
		}
		if((len1 == len2 && len1 == 0) || len2 == 0){
			return haystack;
		}

		while(*haystack != '\0' && *needle != '\0'){
			if(len1 < len2){
				return NULL;
			}
			char *result = haystack;
			char *dst = needle;
			while(*result != '\0' && dst != '\0' && *result == *dst){
				++result;
				++dst;
			}
			if(*dst == '\0'){
				return haystack;
			}
			++haystack;
			--len1;
		}
		return NULL;
    }
};

int main(){
	Solution s;
	char *result = s.strStr("a", "");
	if(result != NULL){
		std::cout << *result << std::endl;
	}else{
		std::cout << "Null" << std::endl;
	}
	return 0;
}

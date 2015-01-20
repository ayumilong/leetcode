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
    bool isPalindrome(std::string s) {
		if(s == ""){
			return true;
		}
		int len = s.size();
		for(int i = 0, j = len - 1; i < j; ++i, --j){
			while(i< len && not isalnum(s[i])){
				++i;
			}
			while(j >= 0 && not isalnum(s[j])){
				--j;
			}
			if(i < j && tolower(s[i]) != tolower(s[j])){
				return false;	
			}
		}
		return true;
    }
};
int main(){
	std::string value;
	Solution s;
	while(std::getline(std::cin, value)){
		if(s.isPalindrome(value)){
			std::cout << "True" << std::endl;
		}else{
			std::cout << "False" << std::endl;
		}
	}
	return 0;
}

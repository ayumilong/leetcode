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
	std::string countAndSay(int n) {
		std::string str1 = "1";
		for(int i = 2; i <= n; ++i){
			std::string str2 = "";
			int len = str1.size();
			for(int i = 0; i < len;){
				int same = 1;
				char c = str1[i++];
			   	while(i < len && str1[i] == c){
					++i;
					++same;
				}	
				str2 += (same + '0');
				str2 += c; 
			}
			str1 = str2;
		}
		return str1;
    }
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::cout << s.countAndSay(value) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

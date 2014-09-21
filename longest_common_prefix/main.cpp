/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

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
	std::string longestCommonPrefix(std::vector<std::string> &strs) {
		int size = strs.size();
		if(size == 0){
			return "";
		}
		int  pos = 0;
		std::string lcp;
		int firstLen = strs[0].size();
		while(true){
			if(pos == firstLen){
				return lcp;
			}
			char cur = strs[0][pos];
			bool common = true;
			for(int i = 1; i < size; ++i){
				int curLen = strs[i].size();
				if(pos == curLen){
					return lcp;
				}
				if(strs[i][pos] != cur){
					common = false;
					break;
				}
			}
			if(common){
				lcp += cur;
			}else{
				return lcp;
			}
			++pos;
		}
    }
};

int main(){
	std::string value;
	std::vector<std::string> strs;
	while(std::cin >> value){
		strs.push_back(value);
	}
	Solution s;
	std::cout << s.longestCommonPrefix(strs) << std::endl;
	return 0;
}

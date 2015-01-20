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
#include <cmath>

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
	std::vector<int> grayCode(int n){
		std::vector<int> result;
		if(n == 0){
			result.push_back(0);
			return result;
		}
		result.push_back(0);
		for(int i = 1; i <= n; ++i){
			int len = result.size();
			for(int j = len - 1; j >= 0; --j){
				result.push_back(result[j] + pow(2, i - 1));
			}
		}
		return result;
		/*
		std::vector<int> subResult = grayCode(n - 1);
		int len = subResult.size();
		for(int i = 0; i < len; ++i){
			result.push_back(subResult[i]);
		}
		for(int i = len - 1; i >= 0; --i){
			result.push_back(subResult[i] + pow(2, n - 1));
		}
		return result;
		*/
    }
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::vector<int> result = s.grayCode(value);
		int len = result.size();
		for(int i = 0; i < len; ++i){
			std::cout << result[i] << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}

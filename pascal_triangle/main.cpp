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
	std::vector<std::vector<int> > generate(int numRows) {
		std::vector<std::vector<int> > result(numRows);
		if(numRows == 0){
			return result;
		}
		result[0].push_back(1);
		if(numRows == 1){
			return result;
		}
		result[1].push_back(1);
		result[1].push_back(1);
		for(int i = 2; i < numRows; ++i){
			int len = result[i - 1].size();
			result[i].resize(len + 1);
			result[i][0] = 1;
			result[i][len] = 1;
			for(int j = 1; j < len; ++j){
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
			}
		}
		return result;
    }
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::vector<std::vector<int> > result = s.generate(value);
		for(int i = 0; i < value; ++i){
			int len = result[i].size();
			for(int j = 0; j < len; ++j){
				std::cout << result[i][j] << " ";
			}
			std::cout << std::endl;
		}	
	}
	std::cout << std::endl;
	return 0;
}

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
	std::vector<int> getRow(int rowIndex){
		std::vector<int> result(rowIndex + 1);
		result[0] = 1;
		for(int i = 0; i < rowIndex; ++i){
			int pre = result[0];
			for(int j = 1; j <= i + 1; ++j){
				int tmp = result[j];
				result[j] = pre + result[j];
				pre = tmp; 
			}
		}
		return result;
    }
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::vector<int> result = s.getRow(value);
		for(int i = 0; i < value + 1; ++i){
			std::cout << result[i] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

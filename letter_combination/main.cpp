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
private:
	std::vector<std::string> numToChars;
public:
	Solution(): numToChars(10) {
		numToChars[0] = " ";
		numToChars[1] = "";
		numToChars[2] = "abc";
		numToChars[3] = "def";
		numToChars[4] = "ghi";
		numToChars[5] = "jkl";
		numToChars[6] = "mno";
		numToChars[7] = "pqrs";
		numToChars[8] = "tuv";
		numToChars[9] = "wxyz";
	}
	std::vector<std::string> combination(int digit, const std::vector<std::string>& middleResult){
		std::vector<std::string> result;
		if(digit < 0 || digit > 9){
			return result;
		}
		int len = middleResult.size();
		for(int i = 0; i < len; ++i){
			int tmpLen = numToChars[digit].size();
			for(int j = 0; j < tmpLen; ++j){
				result.push_back(numToChars[digit][j] + middleResult[i]);
			}
		}
		return result;
	}
	std::vector<std::string> letterCombinations(std::string digits){
		int len = digits.size();
		std::vector<std::string> result;
		if(len == 0){
			result.push_back("");
			return result;
		}else if(len == 1){
			int tmpLen = numToChars[digits[0] - '0'].size();
			for(int i = 0; i < tmpLen; ++i){
				result.push_back(std::string(1, numToChars[digits[0] - '0'][i]));
			}
			return result;
		}
		
		std::vector<std::string> middleResult = letterCombinations(digits.substr(1));
		if(digits[0] == '1'){ //1 means empty
			return middleResult;
		}
		result = combination(digits[0] - '0', middleResult);
		return result;
    }
};

int main(){
	std::string value;
	std::cin >> value;
	Solution s;
	std::vector<std::string> result = s.letterCombinations(value);
	int len = result.size();
	std::cout << "len = " << len << std::endl;
	for(int i = 0; i < len; ++i){
		std::cout << result[i] << std::endl;
	}
	return 0;
}

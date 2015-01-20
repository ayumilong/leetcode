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
	std::vector<int> plusOne(std::vector<int> &digits){
		std::vector<int> result;
		int len = digits.size();
		if(len == 0){
			return result;
		}
		int carry = 0;
		carry = digits[len - 1] + 1;
		if(carry < 10){
			for(int i = 0; i < len - 1; ++i){
				result.push_back(digits[i]);
			}
			result.push_back(carry);
			return result;
		}else{
			result.push_back(carry - 10);
			carry = 1;
		}
		for(int i = len - 2; i >= 0; --i){
			int cur = digits[i] + carry;
			if(cur < 10){
				result.push_back(cur);
				carry = 0;
			}else{
				carry = 1;
				result.push_back(cur - 10);
			}
		}
		if(carry == 1){
			result.push_back(1);
		}
		len = result.size();
		for(int i = 0; i < len / 2; ++i){
			int tmp = result[i];
			result[i] = result[len - i - 1];
			result[len - i - 1] = tmp;
		}
		return result;
    }
};

int main(){
	int value;
	std::vector<int> num;
	while(std::cin >> value){
		num.push_back(value);
	}
	Solution s;
	std::vector<int> result = s.plusOne(num);
	int len = result.size();
	for(int i = 0; i < len; ++i){
		std::cout << result[i];
	}
	std::cout << std::endl;
	return 0;
}

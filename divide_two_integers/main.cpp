/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <climits>

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
    int divide(int dividend, int divisor){
		if(divisor == 0){
			return INT_MAX;
		}
		if(divisor == 1){
			return dividend;
		}
		int flag1 = dividend < 0 ? -1 : 1;
		int flag2 = divisor < 0 ? -1 : 1;
		long long d = flag1 * (long long)dividend;
		long long ded = flag2 * (long long)divisor;

		long long result = 0;
		long long cur = 0;
		for(int i = 31; i >= 0; --i){
			cur <<= 1;
			cur |= ((d >> i) & 1);
			result <<= 1;
			if(cur >= ded){
				cur -= ded;
				result |= 1;
			}
		}
		return flag1 * flag2 * result;
    }
};

int main(){
	int dividend, divisor;
	Solution s;
	while(std::cin >> dividend >> divisor){
		std::cout << s.divide(dividend, divisor) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

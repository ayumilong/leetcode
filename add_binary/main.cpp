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
	std::string addBinary(std::string a, std::string b) {
		if("" == a){
			return b;
		}
		if("" == b){
			return a;
		}
		std::string result;
		int aPos = a.size() - 1;
		int bPos = b.size() - 1;
		char carry = 0;
		while(aPos >= 0 && bPos >= 0){
			char cur = a[aPos--] + b[bPos--] + carry - '0';
			carry = 0;
			if(cur > '1'){
				carry = 1;
				cur -= 2;
			}
			result.insert(0, 1, cur);
		}
		while(aPos >= 0){
			char cur = a[aPos--] + carry;
			carry = 0;
			if(cur > '1'){
				carry = 1;
				cur -= 2; 
			}
			result.insert(0, 1, cur);
		}
		while(bPos >= 0){
			char cur = b[bPos--] + carry;
			carry = 0;
			if(cur > '1'){
				carry = 1;
				cur -= 2; 
			}
			result.insert(0, 1, cur);
		}
		if(carry == 1){
			result.insert(0, 1, carry + '0');
		}
		return result;
    }
};

int main(){
	std::string a, b;
	Solution s;
	while(std::cin >> a >> b){
		std::cout << s.addBinary(a, b) << std::endl;
	}
	return 0;
}

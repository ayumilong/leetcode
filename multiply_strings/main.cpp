/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string multiplyBySingle(string &num1, char single){
		if(single == '1'){
			return num1;
		}
		int len = num1.size();
		string result;
		int carry = 0;
		for(int i = len - 1; i >= 0; --i){
			int cur = (num1[i] - '0') * (single - '0') + carry;
			carry = cur / 10;
			cur = cur % 10;
			result = string(1, cur + '0') + result;
		}
		if(carry != 0){
			result = string(1, carry + '0') + result; 
		}
		return result;
	}

	string addTwoString(string &num1, string &num2){
		int pos1 = num1.size() - 1;
		int pos2 = num2.size() - 1;
		int carry = 0;
		string result;
		while(pos1 >= 0 && pos2 >= 0){
			int cur = (num1[pos1--] - '0') + (num2[pos2--] - '0') + carry;
			carry = cur / 10;
			cur = cur % 10;
			result = string(1, cur + '0') + result;
		}	
		while(pos1 >= 0){
			int cur = (num1[pos1--] - '0') + carry;
			carry = cur / 10;
			cur = cur % 10;
			result = string(1, cur + '0') + result;
		}
		while(pos2 >= 0){
			int cur = (num2[pos2--] - '0') + carry;
			carry = cur / 10;
			cur = cur % 10;
			result = string(1, cur + '0') + result;
		}
		if(carry != 0){
			result = string(1, carry + '0') + result;
		}
		return result;
	}

	string multiply(string num1, string num2){
		if(num1 == "0" || num2 == "0"){
			return "0";
		}
		int len2 = num2.size();
		if(len2 == 0){
			return num1;
		}
		string result = multiplyBySingle(num1, num2[len2 - 1]);
		for(int i = len2 - 2; i >=0; --i){
			string cur = multiplyBySingle(num1, num2[i]);
			cur = cur + string(len2 - i - 1, '0');
			result = addTwoString(cur, result);
		}
		return result;
	}
};

int main(){
	string num1, num2;
	Solution s;
	while(std::cin >> num1 >> num2){
		std::cout << s.multiply(num1, num2) << std::endl;
		std::cout << s.addTwoString(num1, num2) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

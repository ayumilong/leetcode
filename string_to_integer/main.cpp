/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 08 Feb 2014 12:29:09 AM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <climits>

class Solution {
private:
	int skipSpaces(const char *str){
		int len = 0;
		if(str != NULL){
			while(*str == ' ' || *str == '\t'){
				++str;
				++len;
			}
		}
		return len;
	}
public:
    int atoi(const char *str) {
		if(str == NULL || *str == '\0'){
			return 0;
		}
		int pos = skipSpaces(str);
		if(str[pos] == '\0'){//str only contain white characters
			return 0;
		}
		int flag = 1;
		/*
		if(str[pos] == '-'){
			flag = -1;
			++pos;
		}else if(str[pos] == '+'){
			++pos;
		}*/
		int minusNum = 0;
		while(str[pos] == '-' || str[pos] == '+'){//Skip all '-' and '+' and decide is this a negative number
			if(str[pos] == '-'){
				++minusNum;
			}
			++pos;
		}
		if(minusNum%2 != 0){
			flag = -1;
		}
		long long num = 0;
		while(str[pos] != '\0' && str[pos] >= '0' && str[pos] <= '9'){
			long long temp = num * 10 + str[pos] - '0';
			if(temp < num){ //Overflow
				if(flag == -1){
					return INT_MIN;
				}else{
					return INT_MAX;
				}
			}else{
				num = temp;
			}
			++pos;
		}
		if(num * flag > INT_MAX){
			return INT_MAX;
		}else if(num * flag < INT_MIN){
			return INT_MIN;
		}else{
			return num * flag;
		}
    }
};

int main(){
	std::string str;
	while(getline(std::cin ,str)){
		Solution s;
		std::cout << s.atoi(str.c_str()) << std::endl;
	}
	return 0;
}

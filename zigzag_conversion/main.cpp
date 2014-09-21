/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <sstream>

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
	std::string convert(std::string s, int nRows) {
		if(nRows < 2){
			return s;
		}
		int firstLastVal = 2 * nRows - 2;
		int middleVal1 = firstLastVal;
		int middleVal2 = 0;
		std::stringstream cs;
		int len = s.size();
		for(int i = 0; i < nRows; ++i){
			int pos = i;
			while(pos < len){
				cs << s[pos];
				if(i == 0 || i == nRows - 1){
					pos += firstLastVal;
				}else{
					if(pos != i){//Not the first value of each row, we need get 1 more
						pos += middleVal2;
						if(pos >= len){
							break;
						}else{
							cs << s[pos];
						}
					}
					pos += middleVal1; //Jump to the next postion
				}
			}
			middleVal2 += 2; //Update the two interval value
			middleVal1 -= 2;
		}
		return cs.str();
    }
};

int main(){
	Solution so;
	std::string s = "ABCDE";
	print(so.convert(s, 4));
	return 0;
}

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
	void transform(std::string& roman, int count, char min, char middle, char max){
		switch(count){
			case 0:
				break;
			case 3:
				roman += min;
			case 2:
				roman += min; 
			case 1:
				roman += min;
				break;
			case 4:
				roman += min;
			case 5:
				roman += middle;
				break;
			case 6:
				roman += middle;
				roman += min;
				break;
			case 7:
				roman += middle;
				roman += min;
				roman += min;
				break;
			case 8:
				roman += middle;
				roman += min;
				roman += min;
				roman += min;
				break;
			case 9:
				roman += min;
				roman += max;
				break;
		}
	}
	std::string intToRoman(int num) {
		char one = 'I';
		char five = 'V';
		char ten = 'X';
		char fifty = 'L';
		char hundred = 'C';
		char fiveHundred = 'D';
		char thousand = 'M';
		std::string roman;
		int ts = num / 1000;
		while(ts > 0){
			roman += thousand;
			--ts;
		}

		num = num % 1000;
		int hs = num / 100;
		transform(roman, hs, hundred, fiveHundred, thousand);
		
		num = num % 100;
		int tens = num / 10;
		transform(roman, tens, ten, fifty, hundred);

		num = num % 10;
		transform(roman, num, one, five, ten);
		return roman;
    }
};

int main(){
	int value = 1;
	Solution s;
	while(value < 4000){
		std::cout << s.intToRoman(value) << std::endl;
		++value;
	}	
	return 0;
}

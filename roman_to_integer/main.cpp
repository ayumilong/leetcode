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
	void transform(std::string& s, int& integer, int& i, int base, const char min, const char middle, const char max){
		int len = s.size();
		if(s[i] == min){
			if(i + 1 == len){
				integer += base;
				i += 1;
			}else{
				if(s[i + 1] == min){
					int j = i + 2;
					while(j < len && s[j] == min){
						++j;
					}
					if(j == i + 2){
						integer += 2 * base;
						i += 2;
					}else if(j == i + 3){
						integer += 3 * base;
						i += 3;
					}else{
						std::cout << "Invalid Roman Number!" << std::endl;
						return;
					}
				}else if(s[i + 1] == middle){
					integer += 4 * base;
					i += 2;
				}else if(s[i + 1] == max){
					integer += 9 * base;
					i += 2;
				}else{
					integer += base;
					i += 1;
				}
			}
		}else if(s[i] == middle){
			if(i + 1 == len){
				integer += 5 * base;
				i += 1;
			}else{
				if(s[i + 1] == min){
					int j = i + 2;
					while(j < len && s[j] == min){
						++j;
					}
					if(j == i + 2){
						integer += 6 * base;
						i += 2;
					}else if(j == i + 3){
						integer += 7 * base;
						i += 3;
					}else if(j == i + 4){
						integer += 8 * base;
						i += 4;
					}else{
						std::cout << "Invalid Roman Number!" << std::endl;
						return;
					}
				}else{
					integer += 5 * base;
					i += 1;
				}
			}
		}
	}
	int romanToInt(std::string s) {
		const char one = 'I';
		const char five = 'V';
		const char ten = 'X';
		const char fifty = 'L';
		const char hundred = 'C';
		const char fiveHundred = 'D';
		const char thousand = 'M';

		int integer;

		int len = s.size();

		//Thousands
		int i = 0;
		while(i < len && s[i] == thousand){
			++i;
		}
		if(i == len){
			return i * 1000;
		}else{
			integer = i * 1000;
		}
		//Hundreds
		if(i < len && (s[i] == hundred || s[i] == fiveHundred)){
			transform(s, integer, i, 100, hundred, fiveHundred, thousand);
		}	
		//Tens
		if(i < len && (s[i] == ten || s[i] == fifty)){
			transform(s, integer, i, 10, ten, fifty, hundred);
		}
		//Single digits
		if(i < len && (s[i] == one || s[i] == five)){
			transform(s, integer, i, 1, one, five, ten);
		}
		if(i != len){
			std::cout << "Invalid Roman Number" << std::endl;
		}
		return integer;
    }
};

int main(){
	std::string value;
	Solution s;
	while(std::cin >> value){
		std::cout << s.romanToInt(value) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
void print(const std::string s){
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
	bool isSpace(const char *p){
		while(*p != '\0'){
			if(*p != '*' && *(p + 1) == '*'){
				p += 2;
			}else{
				return false;
			}
		}
		return true;
	}
    bool isMatch(const char *s, const char *p) {
		char pre = -1;
		while(*s != '\0' && *p != '\0'){
			switch(*p){
				case '.':
					//If the next character is *
					if(*(p + 1) == '*'){
						if(isMatch(s, p + 2)){
							return true;
						}
					}
					++s;
					++p;
					pre = '.';
					break;
				case '*':
					switch(pre){
						case -1:
							return false;
							break;
						case '.':
							if(isSpace(p + 1)){
								return true;
							}else{
								// * means 0 or 1
								const char *t = s;
								while(*t != '\0'){
									if(isMatch(t, p + 1)){
										return true;
									}
									++t;
								}
								return false;
							}
							break;
						default:
							if(*s != pre){
								if(isMatch(s, p + 1)){
									return true;
								}else{
									return false;
								}
							}else{
								//* means 0 or 1
								const char *t = s;
								while(*t == pre){
									if(isMatch(t, p + 1)){
										return true;
									}
									++t;
								}
								if(*t == '\0'){
									if(isSpace(p + 1)){
										return true;
									}else{
										return false;
									}
								}else{
									if(isMatch(t, p + 1)){
											return true;
									}else{
										return false;
									}
								}
							}
							break;
					}
					break;
				default:
					if(*s != *p){
						if(*(p + 1) == '*'){
							p += 2;
						}else{
							return false;
						}
					}else{
						//Another path
						if(*(p + 1) == '*'){
							if(isMatch(s, p + 2)){
								return true;
							}
						}
						pre = *s; 
						++s;
						++p;
					}
					break;
			}
		}
		if(*s == '\0' && *p == '\0'){
			return true;
		}else{	
			if(*p != '\0'){
				switch(*p){
					case '.':
						if(*(p + 1) == '*'){
							if(isSpace(p + 2)){
								return true;
							}else{
								return false;
							}
						}
						return false;
						break;
					case '*':
						if(isSpace(p + 1)){
							return true;
						}else{
							return false;
						}
						break;
					default:
						if(*(p + 1) == '*'){
							if(isSpace(p + 2)){
								return true;
							}else{
								return false;
							}
						}else{
							return false;
						}
						break;
				}
			}else{
				return false;
			}
		}
    }
};

int main(){
	Solution s;
	if(s.isMatch("a", "a*c*a*b*.*aa*c*a*a*")){
		print("Match");
	}else{
		print("Not Match");
	}
	return 0;
}

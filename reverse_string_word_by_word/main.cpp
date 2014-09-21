/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

class Solution{
public:
    void reverseWords(std::string &s){
		int len = s.size();
		if(len == 0){
			return;
		}
		int i = 0;
		while(i < len){
			if(s[i] != ' '){
				break;
			}
			++i;
		}
		if(i == len){
			s = "";
			return;
		}
		s.erase(0, i); //Delete leading spaces

		len = s.size();
		int j = len - 1;
		while(j > i){
			if(s[j] != ' '){
				break;
			}
			--j;
		}
		if(j != len - 1){
			s.erase(j + 1, len - j - 1); //Delete trailing spaces
		}
		len = s.size();

		std::size_t pos = -1; 
		int spaceCount = 0;
		while((pos = s.find(' ', pos + 1)) != std::string::npos){
			++spaceCount;
		}
		std::size_t lastPos = 0;
		while(spaceCount > 0){
			pos = s.find_last_of(' ');
			--spaceCount;
			if(pos == len - 1){
				s.erase(pos, 1);
				--len;
				continue;
			}	
			s = s.substr(0, lastPos) + s.substr(pos + 1, len - pos - 1) + " " + s.substr(lastPos, pos - lastPos);
			lastPos = lastPos + len - pos;
		}
    }
};

int main(){
	Solution s;
	std::string str = " ";
	s.reverseWords(str);
	std::cout << str.size() << std::endl;
	return 0;
}

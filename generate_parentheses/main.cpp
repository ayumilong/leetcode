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
#include <map>

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
private:
	std::vector<std::vector<std::string> > middleResults;
public:
	//This solution is still slow......
	std::vector<std::string> generateParenthesis(int n){
		if(middleResults.size() != n){
			middleResults.clear();
			middleResults.resize(n);
		}
		std::vector<std::string> result;
		std::map<std::string, int> counts;
		if(n == 0){
			return result;
		}else if(n == 1){
			result.push_back("()");
			return result;
		}
		int half = n / 2;
		for(int i = 1; i <= half; ++i){
			std::vector<std::string> firstResult;
			if(middleResults[i].size() == 0){
				firstResult = generateParenthesis(i);
				middleResults[i] = firstResult;
			}else{
				firstResult = middleResults[i];
			}

			std::vector<std::string> secondResult;
			if(middleResults[n - i].size() == 0){
				secondResult = generateParenthesis(n - i);
				middleResults[n - i] = secondResult;
			}else{
				secondResult = middleResults[n - i];
			}
			int firstLen = firstResult.size();
			int secondLen = secondResult.size();
			for(int m = 0; m < firstLen; ++m){
				for(int n = 0; n < secondLen; ++n){
					int strLen = secondResult[n].size();
					for(int k = 0; k < strLen; ++k){
						std::string tmp = secondResult[n];
						tmp.insert(k, firstResult[m]);
						if(counts[tmp] == 0){
							counts[tmp] = 1;
							result.push_back(tmp);
						}
					}
				}
			}
			for(int m = 0; m < secondLen; ++m){
				for(int n = 0; n < firstLen; ++n){
					int strLen = firstResult[n].size();
					for(int k = 0; k < strLen; ++k){
						std::string tmp = firstResult[n];
						tmp.insert(k, secondResult[m]);
						if(counts[tmp] == 0){
							counts[tmp] = 1;
							result.push_back(tmp);
						}
					}
				}
			}
		}
		return result;
	}
	/*
	 //This is pretty slow
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result;
		if(n == 0){
			return result;
		}else if(n == 1){
			result.push_back("()");
			return result;
		}

		std::map<std::string, int> counts;
		std::vector<std::string> middleResult = generateParenthesis(n - 1);
		int len = middleResult.size();
		for(int i = 0; i < len; ++i){
			int strLen = middleResult[i].size();
			for(int j = 0; j <= strLen; ++j){
				std::string tmp = middleResult[i];
				tmp.insert(j, "()");
				if(counts[tmp] == 0){
					counts[tmp] = 1;
					result.push_back(tmp);
				}
			}
		}
		
		return result;
    }
	*/
};

int main(){
	int value;
	std::cin >> value;
	Solution s;
	std::vector<std::string> result = s.generateParenthesis(value);
	std::cout << result.size() << std::endl;
	int len = result.size();
	for(int i = 0; i < len; ++i){
		std::cout << result[i] << std::endl;
	}
	return 0;
}

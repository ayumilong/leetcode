/*************************************************************************
    > File Name: main.cpp
    > Subject: Catalan Number 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

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
	std::unordered_map<int, int> treesNum;
public:
	Solution(): treesNum() {}
	int numTrees(int n){
		if(n < 2){
			return 1;
		}
		long long result = 0;
		for(int i = 0; i < n; ++i){
			if(treesNum.count(i) == 0){
				treesNum[i] = numTrees(i);
			}
			if(treesNum.count(n - 1 - i) == 0){
				treesNum[n - 1 - i] = numTrees(n - 1 - i);
			}
			result += (treesNum[i] * treesNum[n - 1 - i]); 
		}
		return result;
	}
	/*
	//Catalan Number
    int numTrees(int n) {
		int num = 2 * n;
		long long result = 1;
		long long divide = 1;
		for(int i = 1; i <= n; ++i){
			result *= num;
			divide *= i;
		    --num;	
		}
		result /= divide;
		return result / (n + 1);
    }
	*/
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::cout << s.numTrees(value) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

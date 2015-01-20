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
#include <algorithm>

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
	std::vector<std::vector<int> > computeSum(const std::vector<int> &candidates, int start, int target){
		int len = candidates.size();
		std::vector<std::vector<int> > result;
		int factor = 0;
		while(start < len - 1 && candidates[start + 1] == candidates[start]){//Skip all the same element
			++start;
		}
		while(candidates[start] * factor < target){
			if(start != len - 1){//not the last element, then need to recurse
				std::vector<std::vector<int> > middleResult = computeSum(candidates, start + 1, target - candidates[start] * factor);
				int middleLen = middleResult.size();
				for(int i = 0; i < middleLen; ++i){
					int tmp = factor;
					while(tmp-- > 0){
						middleResult[i].push_back(candidates[start]);
					}
					sort(middleResult[i].begin(), middleResult[i].end());
					result.push_back(middleResult[i]);
				}
			}
			++factor;
		}
		if(candidates[start] * factor == target){
			std::vector<int> tmp(factor, candidates[start]);
			result.push_back(tmp);
		}
		return result;
	}
	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return computeSum(candidates, 0, target);
    }
};

int main(){
	int value;
	std::vector<int> candidates;
	while(std::cin >> value){
		candidates.push_back(value);
	}
	Solution s;
	std::vector<std::vector<int> > result = s.combinationSum(candidates, 7);
	int len = result.size();
	for(int i = 0; i < len; ++i){
		int size = result[i].size();
		for(int j = 0; j < size; ++j){
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

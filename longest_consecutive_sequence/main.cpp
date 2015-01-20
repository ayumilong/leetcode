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
#include <unordered_set>

class Solution {
public:
	int longestConsecutive(std::vector<int> &num){
		std::unordered_set<int> numMap;
		int len = num.size();
		for(int i = 0; i < len; ++i){
			numMap.insert(num[i]);
		}
		int max = 1;
		int cur = 1;
		for(int i = 0; i < len; ++i){
			int left = num[i] - 1;
			int right = num[i] + 1;
			while(numMap.find(left) != numMap.end()){
				++cur;
				numMap.erase(left);
				--left;
			}
			while(numMap.find(right) != numMap.end()){
				++cur;
				numMap.erase(right);
				++right;
			}
			max = max > cur ? max : cur;
			cur = 1;
		}
		return max;
	}
	/*
    int longestConsecutive(std::vector<int> &num) {
		std::map<int, bool> numMap;
		int len = num.size();
		for(int i = 0; i < len; ++i){
			numMap[num[i]] = true;
		}
		std::map<int, bool>::iterator iter = numMap.begin();
		int max = 1;
		int cur = 1;
		int pre = iter -> first;
		++iter;
		while(iter != numMap.end()){
			if(iter -> first == pre + 1){
				++cur;
			}else{
				max = max > cur ? max : cur;
				cur = 1;
			}
			pre = iter -> first;
			++iter;
		}
		return max > cur ? max : cur;
    }
	*/
};

int main(){
	int value;
	std::vector<int> num;
	while(std::cin >> value){
		num.push_back(value);
	}
	Solution s;
	std::cout << s.longestConsecutive(num) << std::endl;
	return 0;
}

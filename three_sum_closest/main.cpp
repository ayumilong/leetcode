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
#include <algorithm>
#include <climits>
#include <cstdlib>

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
	int threeSumClosest(std::vector<int> &num, int target){
		int len = num.size();
		sort(num.begin(), num.end());
		int closest = INT_MAX;
		for(int i = 0; i < len - 2; ++i){
			int j = i + 1;
			int k = len - 1;
			while(j < k && j < len && k > i){
				int tmp = num[i] + num[j] + num[k];
				if(tmp == target){//Have found the closest then return
					return target;
				}else if(tmp < target){
					while(j < len && num[j] == num[j + 1]){
						++j;
					}
				}else{
					while(k > i && num[k] == num[k - 1]){
						--k;
					}
				}
				if(closest == INT_MAX){
					closest = tmp;
					continue;
				}
				if(abs(tmp - target) < abs(closest - target)){//Find a closer result
					closest = tmp;
				}
			}
		}	
		return closest;
    }
};

int main(){
	int value;
	std::vector<int> nums;
	while(std::cin >> value){
		nums.push_back(value);
	}
	Solution s;
	int result = s.threeSumClosest(nums, -1);
	std::cout << result << std::endl;
	return 0;
}

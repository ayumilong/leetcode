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
	std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int len = num.size();
		std::vector<std::vector<int> > result;
		for(int i = 0; i < len - 3; ++i){
			for(int j = i + 1; j < len - 2; ++j){
				int k = j + 1;
				int m = len - 1;
				while(k < m && k < len && m > j){
					int tmp = num[i] + num[j] + num[k] + num[m];
					if(tmp == target){
						std::vector<int> instance(4);
						instance[0] = num[i];
						instance[1] = num[j];
						instance[2] = num[k];
						instance[3] = num[m];
						result.push_back(instance);
						while(k < len - 1 && num[k] == num[k + 1]){
							++k;
						}
						++k;
						while(m > j + 1 && num[m] == num [m - 1]){
							--m;
						}
						--m;
					}else if(tmp < target){
						++k;
					}else{
						--m;
					}
				}
				while(j < len - 2 && num[j] == num[j + 1]){
					++j;
				}
			}
			while(i < len - 3 && num[i] == num[i + 1]){
				++i;
			}
		}
		return result;
    }
};

int main(){
	int value;
	std::vector<int> nums;
	while(std::cin >> value){
		nums.push_back(value);
	}
	Solution s;
	std::vector<std::vector<int> > result = s.fourSum(nums, -7);
	int len = result.size();
	std::cout << len << std::endl;
	for(int i = 0; i < len; ++i){
		int tmpLen = result[i].size();
		for(int j = 0; j < tmpLen; ++j){
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

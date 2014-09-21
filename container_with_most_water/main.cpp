/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <random>
#include <ctime>
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
	int maxArea(std::vector<int> &height){
		size_t len = height.size();
		size_t low = 0;
		size_t high = len - 1;
		int max = 0;
		while(low < high){
			int area = (height[low] < height[high] ? height[low] : height[high]) * (high - low);
			if(max < area){
				max = area;
			}
			if(height[low] < height[high]){
				++low;
			}else{
				--high;
			}
		}
		return max;
	}
	//Too slower, O(n2)
    int slowMaxArea(std::vector<int> &height) {
		size_t len = height.size();
		if(len == 0){
			return 0;
		}
		int max = 0;
		for(size_t i = 0; i < len; ++i){
			for(size_t j = i + 1; j < len; ++j){
				int area = (height[i] < height[j] ? height[i] : height[j]) * (j - i);
				if(area > max){
					max = area;
				}
			}
		}
		return max;
    }
};

int main(){
	std::default_random_engine e(time(0));
	std::uniform_int_distribution<unsigned> d(0, 10);
	std::vector<int> height(100000);
	for(int i = 0; i < 100000; ++i){
		height[i] = d(e);
	}
	std::cout << std::endl;
	Solution s;
	std::cout << s.maxArea(height) << std::endl;
	std::cout << s.slowMaxArea(height) << std::endl;
	return 0;
}

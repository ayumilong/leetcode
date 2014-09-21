/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sun 23 Feb 2014 03:38:19 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>

class Solution {
private:
	int findNum(const std::vector<int>& numbers, int target, int pos){
		int len = numbers.size();
		for(int i = pos; i < len; ++i){
			if(numbers[i] == target){
				return i;
			}
		}
		return -1;
	}
public:
	std::vector<int> twoSum(std::vector<int>& numbers, int target){
		std::vector<int> result;
		std::map<int, int> temp;
		int len = numbers.size();
		for(int i = 0; i < len; ++i){
			if(temp.find(target - numbers[i]) != temp.end()){//Find a solution
				result.push_back(temp[target - numbers[i]]);
				result.push_back(i + 1);
				break;
			}
			if(temp.find(numbers[i]) == temp.end()){//Create hash table
				temp[numbers[i]] = i + 1;
			}
		}
		return result;
	}
	/*
	 //O(n2) too slow
	std::vector<int> twoSum(std::vector<int>& numbers, int target){
		std::vector<int> result;
		if(numbers.size() != 0){
			int len = numbers.size();
			for(int i = 0; i < len; ++i){
				int ret = findNum(numbers, target - numbers[i], i + 1);
				if(ret != -1){
					result.push_back(i + 1);
					result.push_back(ret + 1);
					break;
				}
			}
		}
		return result;
    }
	*/
};

int main(){
	std::vector<int> numbers;
	int val;
	while(std::cin >> val){
		numbers.push_back(val);
	}
	std::cout << numbers.size() << std::endl;
	Solution s;
	std::vector<int> result = s.twoSum(numbers, 16021);
	if(result.size() == 2){
		std::cout << result[0] << " " << result[1] << std::endl;
	}
	return 0;
}

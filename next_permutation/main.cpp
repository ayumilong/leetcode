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
public:
	void reverse(std::vector<int>& num, int start){
		int len = num.size();
		for(int i = start, j = 1; i < (len - start)/2 + start; ++i, ++j){
			int tmp = num[i];
			num[i] = num[len - j];
			num[len - j] = tmp;
		}
	}

	void findAndSwap(std::vector<int>& num, int start){
		int len = num.size();
		int minPos = start + 1; 
		for(int i = start + 2; i < len; ++i){
			if(num[i] > num[start]){
				minPos = i;
			}else{
				break;
			}
		}
		int tmp = num[start];
		num[start] = num[minPos];
		num[minPos] = tmp;
	}

    void nextPermutation(std::vector<int>& num) {
		int len = num.size();
		for(int i = len - 2; i >= 0; --i){
			if(num[i] < num[i + 1]){//Find a good position
				findAndSwap(num, i);
				reverse(num, i + 1);
				return;
			}
		}
		reverse(num, 0);
    }
};

void printVector(std::vector<int>& num){
	int len = num.size();
	for(int i = 0; i < len; ++i){
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}


int main(){
	int value;
	std::vector<int> num;
	while(std::cin >> value){
		num.push_back(value);
	}
	Solution s;
	s.nextPermutation(num);
	printVector(num);
	std::cout << std::endl;
	return 0;
}

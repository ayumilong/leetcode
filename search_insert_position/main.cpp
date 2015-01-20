/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

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
    int searchInsert(int A[], int n, int target){
		int l = 0;
		int h = n - 1;
		while(l < h){
			int middle = (l + h) / 2;
			if(A[middle] < target){
				l = middle + 1;
			}else{
				h = middle;
			}
		}
		if(A[l] >= target){
			return l;
		}else{
			return l + 1;
		}
    }
};

int main(){
	int A[] = {1};
	Solution s;
	std::cout << s.searchInsert(A, 1, 2) << std::endl;
	return 0;
}

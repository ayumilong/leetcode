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
	std::vector<int> searchRange(int A[], int n, int target) {
		std::vector<int> result(2, -1);
		int l = 0;
		int h = n - 1;
		while(l < h){
			int middle = (l + h) / 2; //Move middle to lower part
			if(A[middle] < target){
				l = middle + 1;
			}else{
				h = middle;
			}
		}
		if(A[l] != target){
			return result;
		}
		result[0] = l;
		h = n - 1;
		while(l < h){
			int middle = (l + h + 1) / 2; //Move middle to higher part
			if(A[middle] > target){
				h = middle - 1;
			}else{
				l = middle;
			}
		}
		result[1] = l;
		return result;
    }
	/*
	//Recursion solution
	std::vector<int> findRange(int A[], int n, int start, int target){
		std::vector<int> result(2, -1);
		if(n == 0){
			return result;
		}
		if(n == 1){
			if(A[start] == target){
				result[0] = result[1] = start;
			}
			return result;
		}
		int l = start;
		int h = n - 1 + l;
		int middle = (h - l) / 2 + l;
		if(A[middle] == target){
			std::vector<int> leftResult = findRange(A, middle - l, l, target);
			std::vector<int> rightResult = findRange(A, h - middle, middle + 1, target);
			if(leftResult[0] == -1){
				result[0] = middle;
			}else{
				result[0] = leftResult[0];
			}
			if(rightResult[1] == -1){
				result[1] = middle;
			}else{
				result[1] = rightResult[1];
			}
		}else if(A[middle] < target){
			return findRange(A, h - middle, middle + 1, target);
		}else{
			return findRange(A, middle - l, l, target);
		}
		return result;
	}	
		
	std::vector<int> searchRange(int A[], int n, int target) {
		return findRange(A, n, 0, target);
    }
	*/
};

int main(){
	int A[] = {0, 0};
	Solution s;
	std::vector<int> result = s.searchRange(A, 2, 0);
	std::cout << result[0] << " " << result[1] << std::endl;
	return 0;
}

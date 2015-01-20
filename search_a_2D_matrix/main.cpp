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
    bool searchMatrix(std::vector<std::vector<int> > &matrix, int target) {
		int row = matrix.size();
		int l = 0;
		int h = row - 1;
		while(l <= h){//Do binary search in the last element of each row
			int mid = l + (h - l) / 2;
			int len = matrix[mid].size();
			if(matrix[mid][len - 1] == target){//Find target, return true
				return true;
			}else if(matrix[mid][len - 1] < target){
				l = mid + 1;
			}else{
				h = mid - 1;
			}
		}
		if(l == row){//l == row means target is larger than the largest number in matrix
			return false;
		}
		row = l; //Which row should we search
		
		int len = matrix[row].size();
		l = 0;
		h = len - 1;
		while(l <= h){//Do binary search in this certain row
			int mid = l + (h - l) / 2;
			if(matrix[row][mid] == target){//Find target, return true
				return true;
			}else if(matrix[row][mid] > target){
				h = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		return false;
    }
};

int main(){
	int value;
	while(std::cin >> value){
		std::cout << value << " ";
	}
	std::cout << std::endl;
	return 0;
}

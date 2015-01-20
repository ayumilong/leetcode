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
	int getMinimum(std::vector<std::vector<int> > &triangle, int len, int row, int col, std::vector<std::vector<int> > &minimumPath){
		if(row == len - 1){
			return triangle[row][col];
		}
		int sum = triangle[row][col];
		int leftSum;
		int rightSum;
		if(minimumPath[row + 1][col]  == 0){
			leftSum = getMinimum(triangle, len, row + 1, col, minimumPath);
			minimumPath[row + 1][col] = leftSum;
		}else{
			leftSum = minimumPath[row + 1][col];
		}
		if(minimumPath[row + 1][col + 1]  == 0){
			rightSum = getMinimum(triangle, len, row + 1, col + 1, minimumPath);
			minimumPath[row + 1][col + 1] = rightSum;
		}else{
			rightSum = minimumPath[row + 1][col + 1];
		}
		sum += (leftSum < rightSum ? leftSum : rightSum);
		minimumPath[row][col] = sum;
		return sum;
	}
    int minimumTotal(std::vector<std::vector<int> > &triangle) {
		int len = triangle.size();
		std::vector<std::vector<int> > minimumPath(len);//To store every sub-triangle result
		for(int i = 0; i < len; ++i){
			minimumPath[i] = std::vector<int>(i + 1, 0);
		}
		return getMinimum(triangle, len, 0, 0, minimumPath);
    }
};

int main(){
	return 0;
}

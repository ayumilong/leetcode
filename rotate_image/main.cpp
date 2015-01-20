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
    void rotate(std::vector<std::vector<int> > &matrix) {
		int len = matrix.size();
		//O(n) space inplace
		std::vector<std::vector<bool> > isVisited(len, std::vector<bool>(len, false));
		for(int i = 0; i < len; ++i){
			for(int j = 0; j < len; ++j){
				if(not isVisited[i][j]){
					isVisited[i][j] = true;
					isVisited[j][len - i - 1] = true;
					isVisited[len - i - 1][len - j - 1] = true;
					isVisited[len - j - 1][i] = true;
					int tmp = matrix[i][j];
					matrix[i][j] = matrix[len - j - 1][i];
					matrix[len - j - 1][i] = matrix[len - i - 1][len - j - 1];
					matrix[len - i - 1][len - j  - 1] = matrix[j][len - i - 1];
					matrix[j][len - i - 1] = tmp;
				}
			}
		}
    }
};

int main(){
	std::vector<std::vector<int> > matrix(2, std::vector<int>(2, 1));
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][2] = 4;
	Solution s;
	s.rotate(matrix);
	return 0;
}

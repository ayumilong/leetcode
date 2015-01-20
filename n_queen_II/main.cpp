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
	bool isValid(const std::vector<std::string> &solution, int row, int col, int n){
		int curRow = row - 1;
		while(curRow >= 0){//Validate the same column
			if(solution[curRow][col] == 'Q'){
				return false;
			}
			--curRow;
		}

		int curCol = col - 1;
		curRow = row - 1;
		while(curCol >= 0 && curRow >= 0){//Validate the same left diagnoal
			if(solution[curRow][curCol] == 'Q'){
				return false;
			}
			--curRow;
			--curCol;
		}

		curCol = col + 1;
		curRow = row - 1;
		while(curCol < n && curRow >= 0){//Validate the same right diagnoal
			if(solution[curRow][curCol] == 'Q'){
				return false;
			}
			++curCol;
			--curRow;
		}

		return true;
	}
	int solveNQueens(std::vector<std::string> &solution, int start, int n){
		int result = 0;
		if(start == n){
			return 1;
		}
		for(int i = 0; i < n; ++i){
			if(isValid(solution, start, i, n)){//We can put a queen on [start, i]
				solution[start][i] = 'Q';
				int midResult = solveNQueens(solution, start + 1, n);
				result += midResult;
				solution[start][i] = '.'; //back trace
			}
		}
		return result;
	}
	int totalNQueens(int n) {
		std::vector<std::string> solution(n, std::string(n, '.'));
		return solveNQueens(solution, 0, n);
    }
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::cout << s.totalNQueens(value) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

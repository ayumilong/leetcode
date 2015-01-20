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
#include <unordered_map>

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
    bool isValidSudoku(std::vector<std::vector<char> > &board){
		int rows = 9;
		std::unordered_map<char, int> numbersInARow;
		std::unordered_map<char, int> numbersInAColumn;
		for(int i = 0; i < rows; ++i){//Validate each row
			for(int j = 0; j < rows; ++j){
				if(board[i][j] != '.'){//Row
					if(numbersInARow.count(board[i][j]) > 0){//Duplicate number in the same row
						return false;
					}
					numbersInARow[board[i][j]] = 1;
				}
				if(board[j][i] != '.'){//Column
					if(numbersInAColumn.count(board[j][i]) > 0){
						return false;
					}
					numbersInAColumn[board[j][i]] = 1;
				}
			}
			numbersInARow.clear();
			numbersInAColumn.clear();
		}	
		std::unordered_map<char, int> numbersInASubbox;
		for(int i = 0; i < 3; ++i){//Totally 9 sub boxes
			for(int j = 0; j < 3; ++j){
				for(int m = 0; m < 3; ++m){
					for(int n = 0; n < 3; ++n){
						if(board[m + i * 3][n + j * 3] != '.'){
							if(numbersInASubbox.count(board[m + i * 3][n + j * 3]) > 0){
								return false;
							}
							numbersInASubbox[board[m + i * 3][n + j * 3]] = 1;
						}
					}
				}
				numbersInASubbox.clear();
			}
		}
		return true;
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

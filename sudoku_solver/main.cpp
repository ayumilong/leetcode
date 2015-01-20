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
#include <array>

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

void printBoard(std::vector<std::vector<char> > &board){
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

class Solution{
public:
	bool realSolve(std::vector<std::vector<char> > &board, int left, std::vector<std::unordered_map<char, bool> >& rows, std::vector<std::unordered_map<char, bool> >& cols, std::vector<std::unordered_map<char, bool> >& boxes){
		if(left == 0){
			return true;
		}
		std::vector<std::vector<char> > result = board;
		
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				if(result[i][j] == '.'){
					for(int k = 1; k <= 9; ++k){
						if(rows[i].count(k + '0') == 0 && cols[j].count(k + '0') == 0 && boxes[(i / 3) * 3 + j / 3].count(k + '0') == 0){
							result[i][j] = k + '0';
							rows[i][k + '0'] = true;
							cols[j][k + '0'] = true;
							boxes[(i / 3) * 3 + j / 3][k + '0'] = true;
							if(realSolve(result, left - 1, rows, cols, boxes)){//Get a solution
								board = result;
								return true;
							}
							result[i][j] = '.';//Back tracking
							rows[i].erase(k + '0');
							cols[j].erase(k + '0');
							boxes[(i / 3) * 3 + j / 3].erase(k + '0');
						}
					}
					return false; //Can not find a unique digit for this position
				}
			}
		}

		return false;
	}

    void solveSudoku(std::vector<std::vector<char> > &board){
		std::vector<std::unordered_map<char, bool> > rows(9);
		std::vector<std::unordered_map<char, bool> > cols(9);
		std::vector<std::unordered_map<char, bool> > boxes(9);
		int left = 0;
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				if(board[i][j] != '.'){//Row
					rows[i][board[i][j]] = true; //Row i
				}else{
					++left;
				}
				if(board[j][i] != '.'){//Column
					cols[i][board[j][i]] = true; //Column i
				}
			}
		}


		for(int i = 0; i < 3; ++i){//Totally 9 sub boxes
			for(int j = 0; j < 3; ++j){
				for(int m = 0; m < 3; ++m){
					for(int n = 0; n < 3; ++n){
						if(board[m + i * 3][n + j * 3] != '.'){
							boxes[i * 3 + j][board[m + i * 3][n + j * 3]] = true;
						}
					}
				}
			}
		}

		realSolve(board, left, rows, cols, boxes);
    }
};

int main(){
	std::vector<std::vector<char> > board;
	char sudoku[9][9] = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	std::array<std::array<char, 9>, 9> tmp;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			tmp[i][j] = sudoku[i][j];
		}
	}
	for(int i = 0; i < 9; ++i){
		board.push_back(std::vector<char>(tmp[i].begin(), tmp[i].end()));
	}
	printBoard(board);
	Solution s;
	s.solveSudoku(board);
	printBoard(board);
	return 0;
}

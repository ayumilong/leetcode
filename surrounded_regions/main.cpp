/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 04 Mar 2014 09:46:54 AM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
	struct Position{
		int x;
		int y;
		Position(int x, int y): x(x), y(y) {}
	};

public:
    void solve(std::vector<std::vector<char> > &board) {
		int row = board.size();
		if(row == 0){
			return;
		}
		int col = board[0].size();
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				//Only deal with the edge of the board
				if(i != 0 && j != 0 && i != row - 1 && j != col - 1){
					continue;
				}
				if(board[i][j] == 'O'){
					std::queue<Position> poses;
					board[i][j] = 'Y';
					poses.push(Position(i, j));
					while(not poses.empty()){
						int x = poses.front().x;
						int y = poses.front().y;
						poses.pop();
						//Go up
						if(x - 1 >= 0 && board[x - 1][y] == 'O'){
							board[x - 1][y] = 'Y';
							poses.push(Position(x - 1, y));
						}
						//Go down
						if(x + 1 < row && board[x + 1][y] == 'O'){
							board[x + 1][y] = 'Y';
							poses.push(Position(x + 1, y));
						}
						//Go left
						if(y - 1 >= 0 && board[x][y - 1] == 'O'){
							board[x][y - 1] = 'Y';
							poses.push(Position(x, y - 1));
						}
						//Go right
						if(y + 1 < col && board[x][y + 1] == 'O'){
							board[x][y + 1] = 'Y';
							poses.push(Position(x, y + 1));
						}
					}
				}
			}
		}
		for(int i = 0; i < row; ++i){
			for(int j = 0; j < col; ++j){
				if(board[i][j] == 'O'){
					board[i][j] = 'X';
				}else if(board[i][j] == 'Y'){
					board[i][j] = 'O';
				}
			}
		}
    }
};

int main(){
	std::vector<std::vector<char> > board;
	std::vector<char> row1(2, 'O');
	std::vector<char> row2(2, 'O');
	board.push_back(row1);
	board.push_back(row2);
	Solution s;
	s.solve(board);
	return 0;
}

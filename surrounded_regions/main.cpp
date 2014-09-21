/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 04 Mar 2014 09:46:54 AM EST
 ************************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char> > &board) {
		int rows = board.size();
		if(rows < 3){//For 0, 1 and 2 rows, nothing should be done
			int columns = board[0].size();
			std::vector<std::vector<bool> > isVisited(rows, std::vector<bool>(columns, false));
			for(int i = 1; i < rows - 1; ++i){
				for(int j = 1; j < columns - 1; ++j){
					if(board[i][j] == 'o' && not isVisited[i][j]){
						isVisited[i][j] = true;
						if(board[i][j - 1] == 'o' || board[i - 1][j] == 'o'){
							for(int k = j + 1; k < columns - 1; ++k){//Process this row
								if(board[i][k] == 'x'){
									j = k + 1; //Skip the consecutive 'o's
									break;
								}
								for(int l = i + 1; l < rows - 1; ++l){//Process this column
									if(board[l][k] == 'x'){
										break;
									}
									isVisited[l][k] = true;
								}
								isVisited[i][k] = true;
							}
						}
					}else{ //board[i][j - 1] = 'x' && board[i - 1][j - 1] = 'x'
						bool isSurrounded = true;
						int m = j + 1;
						for(m = j + 1; m < columns; ++m){
							if(board[i][m] == 'x'){
								break;
							}else if(board[i - 1][m] == 'o'){
								isSurrounded = false;
								break;
							}
							isVisited[i][m] = true;
						}
						int n = i;
					}
				}
			}
		}
    }
};

int main(){
	return 0;
}

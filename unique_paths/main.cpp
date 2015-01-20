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
	/*
	//Backtracing solution, too slow
	int getUniquePaths(std::vector<std::string> &board, int m, int n, int row, int col){
		if(row == m - 1 && col == n - 1){
			return 1;
		}
		int result = 0;
		board[row][col] = 'f';
		if(row + 1 < m && board[row + 1][col] != 'f'){//down
			result += getUniquePaths(board, m, n, row + 1, col);
		}
		if(col + 1 < n && board[row][col + 1] != 'f'){//right
			result += getUniquePaths(board, m, n, row, col + 1);
		}
		board[row][col] = '.'; //back trace
		return result;
	}	

    int uniquePaths(int m, int n){
		if(m * n < 4 || m == 1 || n == 1){
			return 1;
		}
		std::vector<std::string> board(m, std::string(n, '.'));
		return getUniquePaths(board, m, n, 0, 0);
    }
	*/

	/*
	//Recursive solution, too slow
	int uniquePaths(int m, int n){
		if(m * n < 4 || m == 1 || n == 1){
			return 1;
		}
		return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
	}
	*/

	/*
	//Math solution, the result is the combination of n - 1 from m + n - 2
	int uniquePaths(int m, int n){
		return getCombination(m + n - 2, n - 1);
	}

	int getCombination(int m, int n){
		if(n > m / 2){
			n = m - n;
		}
		long long result = 1;
		for(int i = 1; i <= n; ++i){
			result *= (m - i + 1);
			result /= i;
		}
		return (int)result;
	}
	*/

	//DP solution
	int uniquePaths(int m, int n){
		if(m * n < 4 || m == 1 || n == 1){
			return 1;
		}
		std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1, 0));
		for(int i = 0; i <= n; ++i){
			dp[0][i] = 1;
			dp[1][i] = 1;
		}
		for(int i = 0; i <= m; ++i){
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		for(int i = 2; i <= m; ++i){
			for(int j = 2; j <= n; ++j){
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
};

int main(){
	int m, n;
	Solution s;
	while(std::cin >> m >> n){
		std::cout << s.uniquePaths(m, n) << std::endl;
	}
	return 0;
}

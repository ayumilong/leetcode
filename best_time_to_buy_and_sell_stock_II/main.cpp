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

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
		int len = prices.size();
		if(len < 2){
			return 0;
		}
		int profit = 0;
		int i = 0;
		while(i < len){
			while(i < len - 1 && prices[i] >= prices[i + 1]){
				++i;
			}
			if(i == len - 1){
				return profit; //No profit, the prices are like 4 3 2 1
			}
			int buy = prices[i];//Find the start of a increase sequence
			while(i < len - 1 && prices[i] < prices[i + 1]){
				++i;
			}
			profit += prices[i] - buy;//Find the end of a increase sequence
			++i;
		}
		return profit;
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

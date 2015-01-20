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
		int profit = 0;
		int i = 0;
		while(i < len){
			while(i < len - 1 && prices[i] >= prices[i + 1]){
				++i;
			}
			int buy = prices[i++];
			int curMax = buy;//Find the max in the current range
			while(i < len && prices[i] >= buy){
				curMax = curMax > prices[i] ? curMax : prices[i];
				++i;
			}
			profit = profit > curMax - buy ? profit : curMax - buy;//Find the end of a increase sequence
		}
		return profit;
    }
};

int main(){
	int value;
	Solution s;
	std::vector<int> prices;
	while(std::cin >> value){
		prices.push_back(value);
	}
	std::cout << s.maxProfit(prices) << std::endl;
	return 0;
}

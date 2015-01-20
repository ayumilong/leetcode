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

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
		int len = prices.size();
		if(len == 0){
			return 0;
		}
		std::vector<int> left(len);//Store the max profit for range 0 to i
		int lowest = prices[0];
		left[0] = 0;
		for(int i = 1; i < len; ++i){
			if(prices[i] < lowest){//Find a new lowest price
				left[i] = left[i - 1];
				lowest = prices[i];
			}else{
				left[i] = prices[i] - lowest;
				left[i] = left[i] > left[i - 1] ? left[i] : left[i - 1];
			}
		}
		int max = left[len - 1];
		int highest = prices[len - 1];
		for(int i = len - 2; i > 0; --i){
			if(prices[i] > highest){//Find a new highest price
				highest = prices[i];
			}else{
				int profit = highest - prices[i] + left[i - 1];
				max = max > profit ? max : profit;
			}
		}
		return max; 
	}
};

int main(){
	int value;
	std::vector<int> prices;
	while(std::cin >> value){
		prices.push_back(value);
	}
	Solution s;
	std::cout << s.maxProfit(prices) << std::endl;
	return 0;
}

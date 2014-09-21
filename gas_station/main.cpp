/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Mon 24 Feb 2014 12:28:02 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
		int len = gas.size();
		int flag = -1;
		for(int i = 0; i < len; ++i){
			if(gas[i] >= cost[i]){//Can go from station i to station i + 1
				int start = (i + 1)%len;
				int curGas = gas[i] - cost[i];
				while(start != i){
					if(curGas + gas[start] < cost[start]){
						break;
					}
					curGas = curGas + gas[start] - cost[start];
					start = (++start)%len;
				}
				if(start == i){//Has complete the circuit
					flag = i;
					break;
				}
				if(start < i){//Now start < i, then we can get that we cann't complete the circuit
					return -1;
				}
				i = start;//The gas stations in the range of [i, start] are all cannot be the start station 
			}
		}	
		return flag;
    }
};

int main(){
	int num;
	std::cin >> num;
	std::vector<int> gas;
	std::vector<int> cost;
	int val;
	int i = 0;
	while((i++) < num){
		std::cin >> val;
		gas.push_back(val);
	}
	i = 0;
	while((i++) < num){
		std::cin >> val;
		cost.push_back(val);
	}
	Solution s;
	std::cout << s.canCompleteCircuit(gas, cost) << std::endl;
	return 0;
}

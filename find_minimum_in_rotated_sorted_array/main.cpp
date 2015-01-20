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
    int findMin(std::vector<int> &num) {
		int len = num.size();
		int low = 0;
		int high = len - 1;
		while(low < high){
			int mid = low + (high - low) / 2;
			if(num[mid] >= num[low] && num[mid] >= num[high]){
				low = mid + 1;
			}else{
				high = mid;
			}
		}
		return num[low];
    }
};
int main(){
	int value;
	std::vector<int> num;
	Solution s;
	while(std::cin >> value){
		num.push_back(value);
	}
	std::cout << s.findMin(num) << std::endl;
	return 0;
}

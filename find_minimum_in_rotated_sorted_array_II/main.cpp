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
			if(num[mid] == num[low]){
				if(num[mid] == num[high]){//3 3 3 1 3, 3 1 3 3 3
					for(int i = low + 1; i < mid; ++i){
						if(num[i] < num[mid]){
							return num[i];
						}
					}
					low = mid + 1;
				}else if(num[mid] < num[high]){//1 1 1 1 2
					return num[low];
				}else if(num[mid] > num[high]){//3 3 3 1 2
					low = mid + 1;
				}
			}else if(num[mid] > num[low]){
				if(num[mid] <= num[high]){//1 2 3 3 3, 1 2 3 3 4
					return num[low];
				}else if(num[mid] > num[high]){//3 4 4 1 2
					low = mid + 1;
				}
			}else if(num[mid] < num[low]){
				if(num[mid] <= num[high]){//4 1 2 2 2, 4 1 2 2 3
					high = mid;
				}
			}
		}
		return num[low];
    }
};

int main(){
	int value;
	std::vector<int> num;
	while(std::cin >> value){
		num.push_back(value);
	}
	Solution s;
	std::cout << s.findMin(num) << std::endl;
	return 0;
}

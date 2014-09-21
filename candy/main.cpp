/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sun 23 Feb 2014 01:33:19 AM EST
 ************************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    int candy(std::vector<int> &ratings) {
		int sum = 0;
		int len = ratings.size();
		int i = 0;
		int curMin = 1;
		while(i < len){
			int curLen = 1; //Find a decreasing sequence
			if(i > 0 && ratings[i] == ratings[i - 1]){
				curMin = 1;
			}
			while(i < len - 1 && ratings[i + 1] < ratings[i]){
				++i;
				++curLen;
			}
			++i;
			if(curLen == 1){//Current decreasing sequence just has one element
				if(i >= 2 && i < len && ratings[i - 1] == ratings[i - 2]){
					sum += 1;
					curMin = 2;
				}else{
					sum += curMin; //Give him curMin candy 
					++curMin;
				}
				continue;
			}
			if(curMin == 1){//The first time
				sum += curLen * (curLen + 1) / 2;
			}else{
				if(curLen <= curMin){
					sum += curLen * (curLen - 1) / 2;
					sum += curMin;
				}else{
					sum += curLen * (curLen + 1) / 2;
				}
			}
			curMin = 2;
		}
		return sum;
    }
};

int main(){
	std::vector<int> ratings;
	int val;
	while(std::cin >> val){
		ratings.push_back(val);
	}
	Solution s;
	std::cout << s.candy(ratings) << std::endl;
	return 0;
}

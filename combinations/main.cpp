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
	std::vector<std::vector<int> > getCombine(int n, int k, std::vector<std::vector<std::vector<std::vector<int> > > > &midResult){
		std::vector<std::vector<int> > result;
		if(k <= 0 || n < k){
			return result;
		}
		if(1 == k){
			for(int i = 1; i <= n; ++i){
				result.push_back(std::vector<int>(1, i));
			}
			return result;
		}
		if(n == k){
			std::vector<int> tmp(n);
			for(int i = 1; i <= n; ++i){
				tmp[i - 1] = i;
			}
			result.push_back(tmp);
			return result;
		}
		std::vector<std::vector<int> > tmpResult;
		if(midResult[n - 1][k - 1].size() == 0){
			tmpResult = getCombine( n- 1, k - 1, midResult);
			midResult[n - 1][k - 1] = tmpResult;
		}else{
			tmpResult = midResult[n - 1][k - 1];
		}
		int len = tmpResult.size();
		for(int i = 0; i < len; ++i){
			tmpResult[i].push_back(n);
			result.push_back(tmpResult[i]);
		}
		if(midResult[n - 1][k].size() == 0){
			tmpResult = getCombine(n - 1, k, midResult);
			midResult[n - 1][k] = tmpResult;
		}else{
			tmpResult = midResult[n - 1][k];
		}
		len = tmpResult.size();
		for(int i = 0; i < len; ++i){
			result.push_back(tmpResult[i]);
		}
		return result;
	}	
	std::vector<std::vector<int> > combine(int n, int k){
		std::vector<std::vector<std::vector<std::vector<int> > > > midResult(n, std::vector<std::vector<std::vector<int> > >(k + 1));
		return getCombine(n, k, midResult);
    }
};

int main(){
	int n, k;
	Solution s;
	while(std::cin >> n >> k){
		std::vector<std::vector<int> > result = s.combine(n, k);
		int len = result.size();
		for(int i = 0; i < len; ++i){
			int curLen = result[i].size();
			for(int j = 0; j < curLen; ++j){
				std::cout << result[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "len = " << len << std::endl;
	}
	return 0;
}

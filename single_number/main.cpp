/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Fri 21 Feb 2014 02:54:18 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
	int anotherSolu(int A[], int n){
		int ones = 0, twos = 0, threes = 0;
		for(int i = 0; i < n; ++i){
			twos |= ones & A[i];
			ones ^= A[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
    int singleNumber(int A[], int n){
		std::vector<int> bitNumber(32, 0);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 32; ++j){
				if(A[i] & 1 << j){
					++bitNumber[j];
				}
			}
		}
		int result = 0;
		for(int j = 0; j < 32; ++j){
			result += ((bitNumber[j] % 3) << j);
		}
		return result;
    }
};

int main(){
	Solution s;
	int A[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
	std::cout << s.anotherSolu(A, 10) << std::endl;
	int x = ~0;
	std::cout << x << std::endl;
	return 0;
}

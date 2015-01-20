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
	//DP solution
	int maxSubArray(int A[], int n){
		std::vector<int> dp(A, A + n);
		int max = dp[0];
		for(int i = 1; i < n; ++i){
			if(dp[i - 1] > 0){
				dp[i] += dp[i - 1];
			}
			max = (max > dp[i]) ? max : dp[i];
		}
		return max; 
	}
		
	/*
	//Divide and conquer
	int getMax(int A[], int low, int high, int n){
		if((high - low + 1) == 2){//We can get a result if the array just have two element
			int bigger = A[low] > A[high] ? A[low] : A[high];
			return bigger > A[low] + A[high] ? bigger : A[low] + A[high];
		}else if(low == high){//Just have one element
			return A[low];
		}
		int middleIndex = low + (high - low) / 2;
		int left = getMax(A, low, middleIndex - 1, n);
		int right = getMax(A, middleIndex + 1, high, n);
		int sum = 0;
	    for(int i = low; i < middleIndex; ++i){
			sum += A[i];
		}	
		int max = sum;
	    for(int i = low; i < middleIndex; ++i){//Find the maximum suffix subarray of left part
			sum -= A[i];
			max = max > sum ? max : sum;
		}	
		int middle = max;
		for(int i = middleIndex + 1; i <= high; ++i){
			sum += A[i];
		}
		max = sum;
		for(int i = high; i > middleIndex; --i){//Find the maximum prefix subarray of right part
			sum -= A[i];
			max = max > sum ? max : sum;
		}

		middle += (max + A[middleIndex]);
		int bigger = (left > right) ? left : right;
		return (bigger > middle) ? bigger : middle;
	}

	int maxSubArray(int A[], int n){
		return getMax(A, 0, n - 1, n);
	}
	*/

	/*
	//O(n) solution
    int maxSubArray(int A[], int n) {
		int sum = 0;
		int ans = A[0];
		for(int i = 0; i < n; ++i){
			sum += A[i];
			ans = ans > sum ? ans : sum;
			if(sum < 0){
				sum = 0;
			}
		}
		return ans;
    }
	*/
};

int main(){
	int A[] = {-2, 3, -2, 4};
	Solution s;
	std::cout << s.maxSubArray(A, 4) << std::endl;
	return 0;
}

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
#include <algorithm>

class Solution1{
public:
	int maxProduct1(int A[], int n) {
        if(n <= 0) return 0;
		if(n == 1) return A[0];
		int curMax = A[0];
		int curMin = A[0];
		int ans = A[0];

		for(int i = 1; i < n; i++)
		{
			int temp = curMin * A[i];
			curMin = std::min(A[i],std::min(temp,curMax * A[i]));
			curMax = std::max(A[i],std::max(temp,curMax * A[i]));
			ans = std::max(ans,curMax);
		}
		return ans;
    }
	int maxProduct(int A[], int n){
		if(n == 0){
			return 0;
		}
		std::vector<int> zeros;
		std::vector<std::pair<int, int> > negatives;
		for(int i = 0; i < n; ++i){
			if(A[i] == 0){
				zeros.push_back(i);
			}else if(A[i] < 0){
				negatives.push_back(std::pair<int, int>(i, A[i]));
			}
		}
		int zeroNum = zeros.size();
		int negativeNum = negatives.size();
		if(zeroNum == 0){
			if(negativeNum % 2 == 0){//Has even number of negative number and no zero
				int max = 1;
				for(int i = 0; i < n; ++i){
					max *= A[i];
				}
				return max;
			}else{//Has odd number of negative number and no zero
				int left = A[0];
				int right = A[n - 1];
				for(int i = 1; i < negatives[negativeNum - 1].first; ++i){
					left *= A[i];
				}
				for(int i = negatives[0].first + 1; i < n - 1; ++i){
					right *= A[i];
				}
				return left > right ? left : right;
			}
		}else{
			zeros.push_back(n);
			int max = maxProduct(A, zeros[0]);//Recursively compute each subarraies which do not contain any zero
			for(int i = 0; i < zeroNum; ++i){
				int cur = maxProduct(A + zeros[i] + 1, zeros[i + 1] - zeros[i] - 1);
				max = max > cur ? max : cur;
			}
			return max > 0 ? max : 0;
		}
	}
};

class Solution {
public:
	int getMaxProduct(int A[], int n){
		if(n == 0){
			return 0;
		}
		std::vector<std::pair<int, int> > negatives;
		for(int i = 0; i < n; ++i){
			if(A[i] < 0){
				negatives.push_back(std::pair<int, int>(i, A[i]));
			}
		}
		int negativeNum = negatives.size();
		if(negativeNum % 2 == 0){//Has even number of negative number and no zero
			int max = A[0];
			for(int i = 1; i < n; ++i){
				max *= A[i];
			}
			return max;
		}else{//Has odd number of negative number and no zero
			int left = A[0];
			int right = A[n - 1];
			for(int i = 1; i < negatives[negativeNum - 1].first; ++i){
				left *= A[i];
			}
			for(int i = negatives[0].first + 1; i < n - 1; ++i){
				right *= A[i];
			}
			return left > right ? left : right;
		}
	}

	int maxProduct(int A[], int n){
		if(n == 0){
			return 0;
		}
		std::vector<int> zeros;
		std::vector<std::pair<int, int> > negatives;
		for(int i = 0; i < n; ++i){
			if(A[i] == 0){
				zeros.push_back(i);
			}else if(A[i] < 0){
				negatives.push_back(std::pair<int, int>(i, A[i]));
			}
		}
		int zeroNum = zeros.size();
		if(zeroNum == 0){
			return getMaxProduct(A, n);	
		}else{//Has zeros, the product is at least 0
			int max = getMaxProduct(A, zeros[0]); 
			int cur;
			for(int i = 0; i < zeroNum - 1; ++i){
				cur = getMaxProduct(A + zeros[i] + 1, zeros[i + 1] - zeros[i] - 1);
				max = max > cur ? max : cur;
			}
			cur = getMaxProduct(A + zeros[zeroNum - 1] + 1, n - zeros[zeroNum - 1] - 1);
			max = max > cur ? max : cur;
			return max > 0 ? max : 0;
		}
	}
};

int main(){
	int A[] = {2, -2, 0, -2, -2, 0, 3};
	Solution1 s;
	std::cout << s.maxProduct1(A, 7) << std::endl;
	return 0;
}

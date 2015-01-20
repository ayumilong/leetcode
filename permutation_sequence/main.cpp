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

using namespace std;

class Solution{
public:
	int getFactorial(int n){
		if(n < 2){
			return 1;
		}
		return n * getFactorial(n - 1);
	}

	vector<int> getKthLehmerCode(int n, int k){
		vector<int> result(n);
		for(int i = 1; i <= n; ++i){
			result[n - i] = k % i;
			k = k / i;
		}
		return result;
	}

	string getPermutation(int n, int k){
		int fac = getFactorial(n);
		if(k < 1 || k > fac){
			return "";
		}
		vector<int> original(n);
		for(int i = 0; i < n; ++i){
			original[i] = i + 1;
		}
		vector<int> lehmerCode = getKthLehmerCode(n, k - 1);
		string result(n, '0');
		for(int i = 0; i < n; ++i){
			result[i] = original[lehmerCode[i]] + '0';
			original.erase(original.begin() + lehmerCode[i]);
		}
		return result;
	}
};

int main(){
	int n, k;
	Solution s;
	while(std::cin >> n >> k){
		std::cout << s.getPermutation(n, k) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

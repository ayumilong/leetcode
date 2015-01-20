/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

class Solution{
public:
	double pow(double x, int n){
		if(n == 0){
			return 1;
		}
		if(n < 0){
			n = -n;
			x = 1 / x;
		}
		return n % 2 == 0 ? pow(x * x, n / 2) : x * pow(x * x, (n - 1) / 2);
	}

	double pow1(double x, int n){
		if(n == 0){
			return 1;
		}
		if(n < 0){
			return pow1(1 / x, -n);
		}
		double result = 1;
		for(int i = 0; i < n; ++i){
			result *= x;
		}
		return result;
	}
};

int main(){
	double value;
	int n;
	Solution s;
	while(std::cin >> value >> n){
		std::cout << s.pow(value, n) << std::endl;
		std::cout << s.pow1(value, n) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

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
	int sqrt1(int x) {
    	unsigned int res = 0;
    	for (int i = 15; i >= 0; i--){
        	if ((res + (1 << i)) * (res + (1 << i)) <= x){
            	res += (1 << i);
			}
    	}
    return res;
	}	

	int sqrt(int x){
		int pre = 46340;
		int cur = pre / 2;
		while(cur * cur > x){
			pre = cur;
			cur /= 2;
		}
		if(cur * cur == x){
			return cur;
		}else{
			for(int i = cur + 1; i <= pre; ++i){
				if(i * i == x){
					cur = i;
					break;
				}
				if(i * i < x && ((i + 1) * (i + 1) > x || (i + 1) * (i + 1) < 0)){
					cur = i;
					break;
				}
			}
		}
		return cur;
	}
};

int main(){
	int value;
	Solution s;
	while(std::cin >> value){
		std::cout << s.sqrt(value) << std::endl;
		std::cout << s.sqrt1(value) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

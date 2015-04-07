/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: Yaolin Zhang
    > Mail: yaolinz@clemson.edu 
    > Created Time: Thu 22 Jan 2015 02:27:33 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
	int majorityElement(std::vector<int> &num){
		std::unordered_map<int, int> elements;
		int len = num.size();
		for(int i = 0; i < len; ++i){
			++elements[num[i]];
			if(elements[num[i]] > len / 2){
				return num[i];
			}
		}
	}
};

int main(){
	return 0;
}

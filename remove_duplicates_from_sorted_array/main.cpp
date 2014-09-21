/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

void print(const std::string &s){
	std::cout << s << std::endl;
}

void trim(std::string &s){ //Delete leading and trailing spaces of a string
	std::size_t len = s.size();
	if(len == 0){
		return;
	}
	std::size_t i = 0;
	while(i < len){
		if(s[i] != ' '){
			break;
		}
	}
	if(i == len){
		s = "";
		return;
	}
	s.erase(0, i); //Delete leading spaces
	len = s.size();

	std::size_t j = len - 1;
	while(j > i){
		if(s[j] != ' '){
			break;
		}
	}
	if(j != len - 1){
		s.erase(j + 1, len - j - 1); //Delete trailing spaces
	}
}

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n < 2){
			return n;
		}
		int cur = A[0];
		int i = 1;
		int count = 1;
		while(i < n){
			int j = i;
			while(j < n && A[j] == cur){
				++j;
			}	
			if(j < n){
				A[count++] = A[j];
				cur = A[j];
			}
			i = j;
		}
		return count;
    }
};

int main(){
	int A[] = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5};
	Solution s;
	std::cout << s.removeDuplicates(A, 15) << std::endl;
	for(int i = 0; i < 15; ++i){
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}

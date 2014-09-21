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
    int removeElement(int A[], int n, int elem) {
		int i = 0;
		int j = n - 1;
		while(i <= j){
			while(i < n && A[i] != elem){//Find a element equals to elem
				++i;
			}
			while(j >= 0 && A[j] == elem){//Find a element not equals to elem
				--j;
			}
			if(i < j){
				int tmp = A[i];
				A[i++] = A[j];
				A[j--] = tmp;
			}
		}
		return i;
    }
};

int main(){
	int A[] = {2, 3, 3};
	Solution s;
	std::cout << s.removeElement(A, 3, 2) << std::endl;
	return 0;
}

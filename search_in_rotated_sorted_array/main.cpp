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
	int findMin(int A[], int n){
		int l = 0;
		int h = n - 1;
		while(l < h){
			int middle = (h - l) / 2 + l;
			if(A[middle] >= A[l]){
				if(A[middle] <= A[h]){
					if(A[middle] == A[h]){
						h = middle - 1;
					}else{
						h = middle;
					}
				}else{
					if(A[middle] == A[l]){
						l = middle + 1;
					}else{
						l = middle;
					}
				}
			}else{
				if(A[middle] == A[h]){
					h = middle - 1;
				}else{
					h = middle;
				}
			}
		}
		return l;
	}
	int binarySearch(int A[], int n, int start, int target){
		int l = start;
		int h = n - 1 + start;
		while(l < h){
			int middle = (h - l + 1) / 2 + l;
			if(A[middle] == target){
				return middle;
			}
			if(A[middle] > target){
				h = middle - 1;
			}else{
				l = middle + 1;
			}
		}
		return (target == A[l]) ? l : -1;
	}
    int search(int A[], int n, int target) {
		int minPos = findMin(A, n);
		if(target == A[minPos]){
			return minPos;
		}else if (target < A[minPos] || target > A[(minPos == 0) ? n - 1 : minPos - 1]){
			return -1;
		}else{
			if(target > A[n - 1]){
				return binarySearch(A, minPos, 0, target);
			}else{
				return binarySearch(A, n - minPos, minPos, target);
			}
		}
    }
};

int main(){
	int A[] = {1, 3};
	Solution s;
	std::cout << s.search(A, 2, 3) << std::endl; 
	return 0;
}

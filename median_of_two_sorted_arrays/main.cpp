/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 04 Mar 2014 09:55:46 PM EST
 ************************************************************************/

#include <iostream>

class Solution {
public:
	double findKthElement(int A[], int m, int B[], int n, int k){//Find the kth element in two sorted array
		//std::cout << "m = " << m << " n = " << n << std::endl;
		if(m <= 0){
			//std::cout << "Line 15" << std::endl;
			return B[k - 1];
		}else if(n <= 0){
			//std::cout << "Line 18" << std::endl;
			return A[k - 1];
		}else if(k <= 0){
			//std::cout << "Line 21" << std::endl;
			return A[0] < B[0] ? A[0] : B[0];
		}
		if(A[m/2] <= B[n/2]){
			if(m/2 + n/2 + 1 >= k){
				//std::cout << "Line 22" << std::endl;
				return findKthElement(A, m, B, n/2, k);
			}else{
				//std::cout << "Line 26" << std::endl;
				return findKthElement(A + m/2 + 1, m - (m/2 + 1), B, n, k - (m/2 + 1));
			}
		}else{
			if(m/2 + n/2 + 1 >= k){
				//std::cout << "Line 29" << std::endl;
				return findKthElement(A, m/2, B, n, k);
			}else{
				//std::cout << "Line 32" << std::endl;
				return findKthElement(A, m, B + n/2 + 1, n - (n/2 + 1), k - (n/2 + 1));
			}
		}
	}
	/*
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if((m + n)%2 == 0){
			return (findKthElement(A, m, B, n, (m + n)/2) + findKthElement(A, m, B, n, (m + n)/2 + 1))/2.0;
		}else{
			return findKthElement(A, m, B, n, (m + n)/2 + 1);
		}	
    }*/
	double findMedianSortedArrays(int A[], int m, int B[], int n){
		if(m <= 0){
			if(n > 0){
				return (n%2 == 0) ? (B[n/2 - 1] + B[n/2])/2 : B[n/2];
			}else{
				return A[0] < B[0] ? A[0] : B[0];
			}
		}else if(n <= 0){
			return (m%2 == 0) ? (A[m/2 - 1] + B[m/2])/2 : B[m/2]；
		}
		if((m + n) % 2 == 0){//The median is the average of the middle two numbers
			int lowA = 0;
			int highA = m - 1;
			int lowB = 0;
			int highB = n - 1;
			while(lowA < highA && lowB < highB){
				int halfA = (lowA + highA)/2;
				int halfB = (lowB + highB)/2;
				if(A[halfA] == B[halfB]){
					return (A[halfA] + B[halfB])/2;
				}else{
				}
			}
		}else{
		}
	}
};

int main(){
	int A[] = {4};
	int B[] = {1, 2, 3};
	Solution s;
	double median = s.findMedianSortedArrays(A, 1, B, 3);
	std::cout << median << std::endl;
	std::cout << s.findKthElement(A, 1, B, 3, 3) << std::endl;
	return 0;
}

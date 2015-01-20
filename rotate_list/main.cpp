/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <mutex>
#include <vector>
#include <cstdlib>
#include <ctime>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *rotateRight1(ListNode *head, int k){
		if(NULL == head){
			return head;
		}
		ListNode *first = head;
		while(k > 0){
			first = first -> next;
			if(first == NULL){
				first = head;
			}
			--k;
		}
		ListNode *second = head;
		while(first -> next){
			second = second -> next;
			first = first -> next;
		}	
		first -> next = head;
		head = second -> next;
		second -> next = NULL;
		return head;
	}

    ListNode *rotateRight(ListNode *head, int k) {
		if(NULL == head){
			return head;
		}
		ListNode *end = head;
		int len = 1;
		while(end -> next){
			++len;
			end = end -> next;
		}
		k = k % len;
		k = len - k;
		ListNode *start = head;
		while(k > 1){
		    start = start -> next;	
			--k;
		}
		if(k == 1){
			end -> next = head;
			head = start -> next;
			start -> next = NULL;
		}
		return head;
    }
};

void printMultiplication(){
	for(int i = 1; i <= 12; ++i){
		for(int j = 1; j <= i; ++j){
			std::cout << j << " * " << i << " = " << i * j << " ";
		}
		std::cout << std::endl;
	}
}

int sumNumInFile(std::string file){
	try{
	std::ifstream ifs(file.c_str());
	std::string num;
	int sum = 0;
	while(getline(ifs, num)){
		sum += std::stoi(num);
	}
	ifs.close();
	int y = 0;
	if(y == 0){
		throw &y;
	}
	return sum;
	}catch(int *n){
		std::cout << *n << std::endl;
		throw;
	}
}

std::string toHex(int r){
	std::string table[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
	std::string result = "";
	while(r >= 0){
		int cur = r % 16;
		result = table[cur] + result;
		r = r / 16;
		if(r == 0){
			break;
		}
	}
	return result;
}

std::string formatRGB(int r, int g, int b){
	int n;
	printf("%X%X%X%n\n", r, g, b, &n);
	std::cout << n << std::endl;
	std::cout << std::hex << r << g << b << std::endl;
	std::string result = "";
	result += toHex(r);
	result += toHex(g);
	result += toHex(b);
	std::ofstream ofs("nums", std::ios::app);
	ofs.write(result.c_str(), result.size());
	ofs.close();
	return result;
}

class CallHandler{
	public:
		static CallHandler* getInstance(){
			if(NULL == instance){
				m.lock();
				if(NULL == instance){
					instance = new CallHandler();
				}
				m.unlock();	
			}
			return instance;
		}

		~CallHandler(){
			if(instance != NULL){
				delete instance;
			}
		}

	private:
		static CallHandler* instance;
		static std::mutex m;
};

void visite(std::vector<std::vector<int> >& matrix, std::vector<std::vector<bool> >& isVisited, int startRow, int startCol, int row, int col){
	int i = 0;
	int j = 0;
	for(i = startCol; i < col; ++i){//Go right
		if(not isVisited[startRow][i]){
			isVisited[startRow][i] = true;
			std::cout << matrix[startRow][i] << " ";	
		}
	}
	for(i = startRow + 1, j = col - 2; i < row && j >= 0; ++i, --j){//Go left-down
		if(not isVisited[i][j]){
			isVisited[i][j] = true;
			std::cout << matrix[i][j] << " ";
		}
	}
	for(; j >= 0; --j){//Go left
		if(not isVisited[row - 1][j]){
			isVisited[row - 1][j] = true;
			std::cout << matrix[row - 1][j] << " ";
		}
	}
	for(i -= 2; i >= 0; --i){//Go up
		if(not isVisited[i][0]){
			isVisited[i][0] = true;
			std::cout << matrix[i][0] << " ";	
		}
	}

}

void printMatrix(std::vector<std::vector<int> >& matrix){
	int m = matrix.size(); //m rows
	if(m <= 0){
		return;
	}
	int n = matrix[0].size(); //n coloms
	std::vector<std::vector<bool> > isVisited(m, std::vector<bool>(n, false));
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(not isVisited[i][j]){
				visite(matrix, isVisited, i, j, m, n);
			}
		}
	}
}

int main(){
	srand(time(NULL));
	int m = rand() % 10 + 1;
	int n = rand() % 10 + 1;
	std::vector<std::vector<int> > matrix(m, std::vector<int>(n));
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			//matrix[i][j] = rand() % 10000 + 1;
			matrix[i][j] = i * n + j + 1;
		}
	}
	printMatrix(matrix);
	std::cout << std::endl;

	ListNode *head = new ListNode(1);
	head -> next = new ListNode(2);
	Solution s;
	ListNode *result = s.rotateRight(head, 10);
	std::cout << result -> val << std::endl;
	return 0;
}

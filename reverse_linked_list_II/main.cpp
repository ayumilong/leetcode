/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(NULL == head){
			return NULL;
		}
		ListNode *first = head;
		ListNode *firstPre = NULL;
		int firstPos = m;
		while(m > 1 && NULL != first){
			firstPre = first;
			first = first -> next;
			--m;
		}
		if(NULL == first){
			return head;
		}
		ListNode *second = first;
		ListNode *secondPre = NULL;
		n -= firstPos;
		while(n > 0 && NULL != second){
			secondPre = second;
			second = second -> next;
			--n;
		}
		if(NULL == second){
			second = secondPre;
		}
		while(first != second){
			ListNode *tmp = first -> next;
			first -> next = second -> next;
			second -> next = first;
			first = tmp;
		}
		if(firstPre != NULL){
			firstPre -> next = second;
			return head;
		}else{
			return second;
		}
    }
};

ListNode* reverseList(ListNode *header1){
    if(NULL == header1){
        return NULL;
    }
    ListNode* header2 = new ListNode(header1 -> val); 
    ListNode* temp = header1 -> next;
    while(NULL != temp){
        ListNode *cur = new ListNode(temp -> val);
        cur -> next = header2 -> next;
        header2 -> next = cur;
        temp = temp -> next;
    }
    return header2;
}

struct Point{
	int x;
	int y;
	Point(int x, int y): x(x), y(y) {}
};

//BFS
int findWhiteArea(std::vector<std::vector<int> > bitMap, int m, int n){
	int result = 0;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(bitMap[i][j] == 0){//Find a new area, do BFS search
				++result;
				std::queue<Point> poses;
				bitMap[i][j] = 2;
				poses.push(Point(i, j));
				while(not poses.empty()){
					int x = poses.front().x;
					int y = poses.front().y;
					poses.pop();
					//Go down
					if(x + 1 < m && bitMap[x + 1][y] == 0){
						bitMap[x + 1][y] = 2;
						poses.push(Point(x + 1, y));
					}
					//Go up
					if(x - 1 >= 0 && bitMap[x - 1][y] == 0){
						bitMap[x - 1][y] = 2;
						poses.push(Point(x - 1, y));
					}
					//Go right 
					if(y + 1 < n && bitMap[x][y + 1] == 0){
						bitMap[x][y + 1] = 2;
						poses.push(Point(x, y + 1));
					}
					//Go left
					if(y - 1 >= 0 && bitMap[x][y - 1] == 0){
						bitMap[x][y - 1] = 2;
						poses.push(Point(x, y - 1));
					}
				}
			}
		}
	}
	for(int i = 0; i < m; ++i){//Restore all the zeros
		for(int j = 0; j < n; ++j){
			if(bitMap[i][j] == 2){
				bitMap[i][j] = 0; 
			}
		}
	}
	return result;
}

int main(){
	std::vector<std::vector<int> > bitMap;
	srand(time(NULL));
	int row = 10;
	int col = 10;
	for(int i = 0; i < row; ++i){
		std::vector<int> curRow;
		for(int j = 0; j < col; ++j){
			int n =rand() % 2;
			std::cout << n << " ";
			curRow.push_back(n);
		}
		std::cout << std::endl;
		bitMap.push_back(curRow);
	}
	std::cout << findWhiteArea(bitMap, row, col) << std::endl;

	int value;
	ListNode *head = new ListNode(-1);
	ListNode *pre = head;
	while(std::cin >> value){
		ListNode *cur = new ListNode(value);
		pre -> next = cur;
		pre = cur;
	}
	ListNode *newHead = reverseList(head);
	while(newHead -> next){
		std::cout << newHead -> next -> val << " ";
		newHead = newHead -> next;
	}
	std::cout << std::endl;
	return 0;
}

/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: Yaolin Zhang
    > Mail: yaolinz@clemson.edu 
    > Created Time: Wed 10 Dec 2014 04:38:23 PM EST
 ************************************************************************/

#include <iostream>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution{
public:
	ListNode *partition(ListNode *head, int x){
		if(NULL == head){
			return NULL;
		}
		ListNode *pre = NULL;
		ListNode *first = head;
		while(first && first -> val < x){
			pre = first;
			first = first -> next;
		}
		if(NULL == first){
			return head;
		}
		ListNode *second = first -> next;
		ListNode *secondPre = first;
		while(second){
			while(second && second -> val >= x){
				secondPre = second;
				second = second -> next;
			}
			if(NULL == second){
				return head;
			}
			if(NULL == pre){
				head = second;
				pre = second;
				secondPre -> next = second -> next;
				second -> next = first;
			}else{
				pre -> next = second;
				pre = second;
				secondPre -> next = second -> next;
				second -> next = first;
			}
			second = secondPre -> next;
		}
		return head;
	}
};

void printList(ListNode* head){
	while(head){
		std::cout << head -> val << " ";
		head = head -> next;
	}
	std::cout << std::endl;
}

int main(){
	ListNode *head = new ListNode(1);
	ListNode *pre = head;
	int value;
	while(std::cin >> value){
		pre -> next = new ListNode(value);
		pre = pre -> next;
	}
	printList(head);
	Solution s;
	printList(s.partition(head, 3));
	return 0;
}

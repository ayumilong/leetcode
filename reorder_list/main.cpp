/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sun 09 Feb 2014 11:39:27 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head){// 1 2 3 4 5 6 to 1 6 2 5 3 4
		if(head != NULL){
		//	std::vector<ListNode*> listVec;
			int len = 1;
			ListNode *tail = head;
	//		listVec.push_back(tail);
			while(tail -> next != NULL){
				++len;
				tail = tail -> next;
	//			listVec.push_back(tail);
			}
	//		int i = 0;
	//		while(i < len/2){
	//			listVec[i] -> next = listVec[len - i - 1];
	//			listVec[len - i - 1] -> next = listVec[i + 1];
	//			++i;
	//		}
	//		listVec[len/2] -> next = NULL;
			int count = len;
			count = (count%2 == 0) ? count/2 -1 : count/2;
			int i = 1;
			ListNode *cur = head;
			while(i <= count){
				ListNode *temp = cur;
				ListNode *pre = NULL;
				while(temp -> next != NULL){
					pre = temp;
					temp = temp -> next;
				}
				if(pre != NULL){
					pre -> next = NULL;
					temp -> next = cur -> next;
					cur -> next = temp;
					cur = cur -> next -> next;
				}
				++i;
			}
		}
    }
/*
    void reorderList(ListNode *head){// 1 2 3 4 to 1 4 3 2
		if(head != NULL){
			ListNode *tail = head;
			while(tail -> next != NULL){
				tail = tail -> next;
			}
			ListNode *cur = head -> next;
			while(cur != NULL && cur != tail){
				head -> next = cur -> next;
				cur -> next = tail -> next;
				tail -> next = cur;
				cur = head -> next;
			}
		}
    }
*/
/*
    void reorderList(ListNode*& head){// 1 2 3 4 to 4 3 2 1
		if(head != NULL){
			ListNode *tail = head;
			while(tail -> next != NULL){
				tail = tail -> next;
			}
			ListNode *cur = head;
			while(cur != NULL && cur != tail){
				ListNode *temp = cur -> next;
				cur -> next = tail -> next;
				tail -> next = cur;
				cur = temp;
			}
			head = tail;
		}
    }
*/
};

void printList(const ListNode* head){
	while(head){
		std::cout << head -> val << " ";
		head = head -> next;
	}
	std::cout << std::endl;
}

int main(){
	int val;
	ListNode *head = NULL;
	ListNode *pre = NULL;
	while(std::cin >> val){
		if(head == NULL){
			head = new ListNode(val);
			pre = head;
		}else{
			pre -> next = new ListNode(val);
			pre = pre -> next;
		}
	}
	Solution s;
	s.reorderList(head);
	printList(head);
	return 0;
}

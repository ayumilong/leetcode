/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Fri 07 Feb 2014 11:43:19 PM EST
 ************************************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
		ListNode *beforeHead = new ListNode(-1); //Guard nod, so we can treat head as normal node
		beforeHead -> next = head;
		if(head != NULL){
			ListNode *cur = head -> next;
			ListNode *preCur = head;
			while(cur != NULL){
				ListNode *temp = beforeHead -> next;
				ListNode *pre = beforeHead;
				while(temp != cur){
					if(temp -> val >= cur -> val){
						pre -> next = cur;
						preCur -> next = cur -> next;
						cur -> next = temp;
						cur = preCur -> next;
						break;
						/* //When no guard node, we should apply different process to head or other
						if(temp == head){ //The current node is the smallest node, so insert to head
							ListNode *t = head;
							head = cur;
							preCur -> next = cur -> next;
							cur -> next = t;
							cur = preCur -> next;
							temp = head;
							break;
						}else{
							pre -> next = cur;
							preCur -> next = cur -> next; //preCur maintain its value
							cur -> next = temp;
							cur = preCur -> next;  //The next node
							break;
						}
						*/
					}else{
						pre = temp; //Just move to the next node
						temp = temp -> next;
					}
				}
				if(temp == cur){//The current node is the biggest node, so move to the next node
					preCur = cur;
					cur = cur -> next;
				}
			}
		}
		return beforeHead -> next;
    }
};

void printList(ListNode *head){
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
			head -> next = NULL;
			pre = head;
		}else{
			pre -> next = new ListNode(val);
			pre = pre -> next;
		}
	}
	Solution s;
	head = s.insertionSortList(head);
	printList(head);
	return 0;
}

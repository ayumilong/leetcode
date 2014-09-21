/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Fri 31 Jan 2014 11:59:14 AM EST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){
	while(head != NULL){
		std::cout << head -> val << " ";
		head = head -> next;
	}
	std::cout << std::endl;
}
 
class Solution {
public:
	ListNode* hasCycle(ListNode *head) {
		ListNode *fastNode = head;
		ListNode *slowNode = head;
		while(fastNode && slowNode){
			fastNode = fastNode -> next;
			if(fastNode){
				fastNode = fastNode -> next;
			}else{
				return NULL; //fastNode is NULL, no cycle
			}
			slowNode = slowNode -> next;
			if(fastNode == slowNode){
				return fastNode;
			}
		}
		return NULL;
    }

	ListNode* detectCycle(ListNode *head) {
		ListNode *inCycle = hasCycle(head);
		if(inCycle != NULL){ //Has a cycle
			ListNode *temp = inCycle -> next;
			int cycleLen = 1;
			while(temp != inCycle){//Get the length of the cycle
				++cycleLen;
				temp = temp -> next;
			}
			ListNode *first = head;
			ListNode *second = head;
			while((cycleLen--) > 0){ //First walks cycleLen steps
				first = first -> next;
			}
			while(second != first){
				second = second -> next;
				first = first -> next;
			}
			return first;
		}
		return NULL;
		/* //This method is too slow
		ListNode *inCycle = hasCycle(head);
		if(inCycle != NULL)){//If has a cycle
			ListNode *first = head;
			while(first){
				ListNode *second = first;
				ListNode *third	= first;
				ListNode *pre = NULL;
				while(true){
					second = second -> next -> next;
					pre = third;
					third = third -> next;
					if(third == first){ //Find the head of the cycle
						return pre;
					}else if(third == second){ //Ensure that this while loop can break
						break;
					}
				}
				first = first -> next;
			}
		}
		return NULL;
		*/
    }
};

int main(){
	Solution s;
	ListNode *start = new ListNode(1);
	ListNode *end = new ListNode(2);
	start -> next = end;
	end -> next = start;
	s.detectCycle(start);
	printList(start);
	return 0;
}

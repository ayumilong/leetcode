/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: Yaolin Zhang
    > Mail: yaolinz@clemson.edu 
    > Created Time: Wed 10 Dec 2014 04:38:23 PM EST
 ************************************************************************/

#include <iostream>
#include <unordered_map>

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		if(NULL == head){
			return NULL;
		}
		std::unordered_map<int, int> nodeMap;
		ListNode *p = head;
		while(p){
			++nodeMap[p -> val];
			p = p -> next;
		}
		ListNode *pre = NULL;
		ListNode *cur = head;
		while(cur){
			if(nodeMap[cur -> val] > 1){
				if(NULL == pre){
					head = cur -> next;
					cur -> next = NULL;
					cur = head;
				}else{
					pre -> next = cur -> next;
					cur = pre -> next;
				}
			}else{
				pre = cur;
				cur = cur -> next;
			}
		}
		return head;
	}
};
int main(){
	return 0;
}

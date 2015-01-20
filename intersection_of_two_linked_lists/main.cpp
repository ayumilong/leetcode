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
	ListNode(int v): val(v), next(NULL) {}
};

class Solution{
public:
	ListNode* getIntersectionNode1(ListNode* headA, ListNode* headB){
		if(NULL == headA || NULL == headB){
			return NULL;
		}
		ListNode *pA = headA;
		ListNode *pB = headB;
		ListNode *endA = NULL;
		ListNode *endB = NULL;
		while(true){
			if(NULL == pA){//Has got to the end of headA
				pA = headB;
			}
			if(NULL == pB){//Has got to the end of headB
				pB = headA;
			}
			if(pA == pB){
				return pA;
			}
			if(NULL == pA -> next){
				endA = pA;
			}
			if(NULL == pB -> next){
				endB = pB;
			}
			if(endA != NULL && endB != NULL){
				if(endA != endB){
					return NULL;
				}
			}
			pA = pA -> next;
			pB = pB -> next;
		}
	}

	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
		int lenA = 0;
		int lenB = 0;
		ListNode *tmp = headA;
		while(tmp){//O(m)
			++lenA;
			tmp = tmp -> next;
		}
		tmp = headB;
		while(tmp){//O(n)
			++lenB;
			tmp = tmp -> next;
		}
		if(lenA == 0 || lenB == 0){
			return NULL;
		}
		while(lenA > lenB){//O(m)
			headA = headA -> next;
			--lenA;
		}
		while(lenB > lenA){//O(n)
			headB = headB -> next;
			--lenB;
		}
		while(lenA > 0){//O(min(m, n))
			if(headA == headB){
				return headA;
			}
			headA = headA -> next;
			headB = headB -> next;
			--lenA;
		}
		return NULL;
	}
};

int main(){
	ListNode *headA = new ListNode(3);
	ListNode *headB = new ListNode(2);
	headB -> next = headA;
	Solution s;
	ListNode *result = s.getIntersectionNode1(headA, headB);
	if(result){
		std::cout << result -> val << std::endl;
	}else{
		std::cout << "NULL" << std::endl;
	}
	return 0;
}

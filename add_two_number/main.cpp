/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 18 Mar 2014 02:42:29 PM EDT
 ************************************************************************/

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
class Solution {  
public:  
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {  
        if(l2==NULL) return l1;  
        if(l1==NULL) return l2;  
        ListNode *l3=NULL;  
        ListNode *p = l3;  
        int flag=0;  
        while( l1!=NULL || l2!=NULL ){  
            int sum =  flag;  
            if(l1!=NULL){  
                sum += l1->val;  
                l1 = l1->next;  
            }  
            if(l2!=NULL){  
                sum += l2->val;  
                l2 = l2->next;  
            }  
            int current ;  
            flag   = sum /10;  
            current= sum%10;  
            ListNode *tmp = new ListNode(current);  
              
            if(l3==NULL){  
                l3 = tmp;  
                p  = l3;  
            }else{  
                p->next = tmp;  
                p = p->next;  
            }  
        }  
        if ( flag != 0){  
            ListNode *tmp = new ListNode(flag);  
            p->next   = tmp;  
        }  
        return l3;  
    }  
};  
* /

void getCarry(int& cur, int& carry){
	carry = cur / 10;
	cur = cur % 10;
}

void copyWithCarry(ListNode*& pre, ListNode* l, int& carry){
	ListNode *sum = NULL;
	while(l != NULL){
		int cur = l -> val + carry;
		getCarry(cur, carry);
		if(pre == NULL){
			pre = new ListNode(cur);
			sum = pre;
		}else{
			pre -> next = new ListNode(cur);
			pre = pre -> next;
		}
		l = l -> next;
	}
	if(sum != NULL){
		pre = sum;
	}
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode *sum = NULL;
		if(l1 != NULL || l2 != NULL){
			int carry = 0; 
			if(l1 == NULL){
				copyWithCarry(sum, l2, carry);
			}else if(l2 == NULL){
				copyWithCarry(sum, l1, carry);
			}else{
				ListNode *pre;
				while(l1 != NULL && l2 != NULL){
					int cur = l1 -> val + l2 -> val + carry;
					getCarry(cur, carry);
					if(sum == NULL){//The first node
						sum = new ListNode(cur);
						pre = sum;
					}else{
						pre -> next = new ListNode(cur);
						pre = pre -> next;
					}
					l1 = l1 -> next;
					l2 = l2 -> next;
				}
				if(l1 != NULL){
					copyWithCarry(pre, l1, carry);
				}else if(l2 != NULL){
					copyWithCarry(pre, l2, carry);
				}
				if(carry == 1){
					pre -> next = new ListNode(carry);
				}
			}
		}
		return sum;
    }
};

void printList(ListNode *l){
	while(l != NULL){
		std::cout << l -> val << " ";
		l = l -> next;	
	}
	std::cout << std::endl;
}

int main(){
	ListNode *l1 = NULL, *l2 = NULL;
	int val;
	int n1, n2;
	std::cout << "Please input n1 and n2: " << std::endl;
	std::cin >> n1 >> n2;
	std::cout << "Please input l1: " << std::endl;
	ListNode *pre = l1;
	while(n1-- > 0){
		std::cin >> val;
		if(l1 == NULL){
			l1 = new ListNode(val);
			pre = l1;
		}else{
			pre -> next = new ListNode(val);
			pre = pre -> next;
		}
	}
	std::cout << "Please input l2: " << std::endl;
	while(n2-- > 0){
		std::cin >> val;
		if(l2 == NULL){
			l2 = new ListNode(val);
			pre = l2;
		}else{
			pre -> next = new ListNode(val);
			pre = pre -> next;
		}
	}
	Solution s;
	ListNode *sum = s.addTwoNumbers(l1, l2);
	printList(l1);
	printList(l2);
	printList(sum);
	return 0;
}

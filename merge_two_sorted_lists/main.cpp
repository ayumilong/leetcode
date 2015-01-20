/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

void print(const std::string &s){
	std::cout << s << std::endl;
}

void trim(std::string &s){ //Delete leading and trailing spaces of a string
	std::size_t len = s.size();
	if(len == 0){
		return;
	}
	std::size_t i = 0;
	while(i < len){
		if(s[i] != ' '){
			break;
		}
	}
	if(i == len){
		s = "";
		return;
	}
	s.erase(0, i); //Delete leading spaces
	len = s.size();

	std::size_t j = len - 1;
	while(j > i){
		if(s[j] != ' '){
			break;
		}
	}
	if(j != len - 1){
		s.erase(j + 1, len - j - 1); //Delete trailing spaces
	}
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1 == NULL){
			return l2;
		}
		if(l2 == NULL){
			return l1;
		}
		ListNode *result = NULL;
		ListNode *cur = NULL;
		if(l1 -> val <= l2 -> val){
			result = l1;
			cur = l1;
			l1 = l1 -> next;
		}else{
			result = l2;
			cur = l2;
			l2 = l2 -> next;
		}
		while(l1 != NULL && l2 != NULL){
			if(l1 -> val <= l2 -> val){
				cur -> next = l1;
				cur = l1;
				l1 = l1 -> next;
			}else{
				cur -> next = l2;
				cur = l2;
				l2 = l2 -> next;
			}
		}
		while(l1 != NULL){
			cur -> next = l1;
			cur = l1;
			l1 = l1 -> next;
		}
		while(l2 != NULL){
			cur -> next = l2;
			cur = l2;
			l2 = l2 -> next;
		}
		return result;
    }
};

int main(){
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(1);
	Solution s;
	ListNode *l3 = s.mergeTwoLists(l1, l2);
	while(l3 != NULL){
		std::cout << l3 -> val << " ";
		l3 = l3 -> next;
	}
	std::cout << std::endl;
	return 0;
}

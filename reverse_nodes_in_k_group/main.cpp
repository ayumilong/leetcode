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
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(k < 2){
			return head;
		}
		ListNode *top = new ListNode(0);
		top -> next = head;

		ListNode *first = top;
		while(head != NULL){
			int group = k;
			ListNode *pre = head;
			while(group > 0 && pre != NULL){//Try to find a whole group
				pre = pre -> next;
				--group;
			}
			if(group == 0){//Find a group, then reverse it
				group = k;
				while(group > 1){
					ListNode *cur = head -> next;
					head -> next = cur -> next;
					cur -> next = first -> next;
					first -> next = cur;
					--group;
				}
			}else{//Just a part of a group, return
				return top -> next;
			}
			first = head;
			head = head -> next; //Try to find the next group
		}
		return top -> next;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *second = new ListNode(2);
	ListNode *third = new ListNode(3);
	ListNode *fourth = new ListNode(4);
	ListNode *fifth = new ListNode(5);
	head -> next = second;
	second -> next = third;
	third -> next = fourth;
	fourth -> next = fifth;

	ListNode *p = head;
	while(p){
		std::cout << p -> val << " ";
		p = p -> next;
	}
	std::cout << std::endl;

	Solution s;
	
	ListNode *result = s.reverseKGroup(head, 2);
	while(result){
		std::cout << result -> val << " ";
		result = result -> next;
	}
	std::cout << std::endl;
	
	return 0;
}

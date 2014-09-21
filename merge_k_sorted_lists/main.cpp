/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

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
	ListNode *mergeTwoLists(ListNode *list1, ListNode* list2){
		ListNode *head = NULL;
		ListNode *pre = NULL;
		while(list1 != NULL && list2 != NULL){
			ListNode *tmp;
			if(list1 -> val < list2 -> val){
				tmp = list1;
				list1 = list1 -> next;
			}else{
				tmp = list2;
				list2 = list2 -> next;
			}
			if(head == NULL){
				head = tmp;
				pre = head;
			}else{
				pre -> next = tmp;
				pre = tmp;
			}
		}
		if(list1 != NULL){
			if(head == NULL){
				return list1;
			}
			pre -> next = list1;
		}
		if(list2 != NULL){
			if(head == NULL){
				return list2;
			}
			pre -> next = list2;
		}
		return head;
	}

    ListNode *mergeKLists(std::vector<ListNode *> &lists) {
		int len = lists.size();
		if(len == 0){
			return NULL;
		}else if(len == 1){
			return lists[0];
		}
		ListNode *head = mergeTwoLists(lists[0], lists[1]);
		for(int i = 2; i < len; ++i){
			head = mergeTwoLists(head, lists[i]);
		}
		return head;
    }
};

int main(){
	ListNode *list1 = new ListNode(1);
	ListNode *list2 = new ListNode(0);
	std::vector<ListNode *> lists;
	lists.push_back(list1);
	lists.push_back(list2);
	Solution s;
	ListNode *head = s.mergeKLists(lists);
	return 0;
}
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
private:
	void sort(ListNode*& head, ListNode*& tail, int len){
		if(len <= 1){
			return;
		}
		int m = random()%len; //A random value for partation
		int i = 0;
		ListNode *middle = head;
		while((i++) < m){
			middle = middle -> next;
		}
		i = middle -> val;
		middle -> val = tail -> val;
		tail -> val = i;
		middle = tail;
		int selVal = tail -> val;
		ListNode *left = head;
		ListNode *pre = head;
		int n = 0;
		int num = len;
		while((num--) > 1){ //Process the left side of the list
			if(left -> val > selVal){ //Get a bigger node and insert it to the tail
				++n;
				if(left == head){
					head = left -> next; //The next node becomes the head node
					pre = head;
				}else{
					pre -> next = left -> next; //Take out of current node
				}
				ListNode *temp = tail -> next; //Move current node to the tail
				tail -> next = left;
				left -> next = temp;
				tail = left; //New tail
				if(pre != head){
					left = pre -> next; //The next node
				}else{
					left = head; //The next node is still the head node
				}
				continue;
			}
			pre = left;
			left = left -> next;
		}
		pre = head;
		if(pre != middle){ //Get the pre node of the middle node
			while(pre -> next != middle){
				pre = pre -> next;
			}
		}
		sort(head, pre, len - n - 1);
		sort(middle -> next, tail, n);
	}

public:
	/*
 //This is a very tricky method
	ListNode *sortList(ListNode *head){
		if(head == NULL || head -> next == NULL){
			return head;
		}
		std::map<int, std::vector<ListNode*> > listMap;
		while(head){
			listMap[head -> val].push_back(head);
			head = head -> next;
		}
		std::map<int, std::vector<ListNode*> >::iterator iter = listMap.begin();
		ListNode *pre = NULL; 
		head = (*iter).second[0];
		while(iter != listMap.end()){
			size_t i = 0;
			while(i < (*iter).second.size()){
				if(pre == NULL){
					pre = head;
					++i;
					continue;
				}
				pre -> next = (*iter).second[i];
				pre = pre -> next;
				++i;
			}
			++iter;
		}
		pre -> next = NULL;
		return head;
	}
	*/
    ListNode *sortList(ListNode *head) {
		if(head == NULL || head -> next == NULL){ //No element or only 1 element
			return head;
		}
		ListNode *tail = head;
		int len = 1;
		while(tail -> next != NULL){ //O(N)
			tail = tail -> next;
			++len;
		}
		sort(head, tail, len); //O(NlogN)
		return head;
    }
};

int main(){
	int val;
	ListNode *head = NULL;
	ListNode *pre = NULL;
	while(std::cin >> val){
		if(head == NULL){
			head = new ListNode(val);
			pre = head;
			continue;
		}
		ListNode *temp = new ListNode(val);
		pre -> next = temp;
		pre = temp;
	}
	Solution s;
	head = s.sortList(head);
	printList(head);
	return 0;
}

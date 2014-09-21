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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(n <= 0){
			return head;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *pre = head;
		int steps = n;
		while(fast != NULL && steps > 0){
			--steps;
			fast = fast -> next;
		}
		if(fast == NULL){//Do not have Nth node from end of list
			if(steps == 0){//Delete head
				return head -> next;
			}else{
				return head;
			}
		}
		while(fast != NULL){//Find Nth node
			pre = slow;
			slow = slow -> next;
			fast = fast -> next;
		}
		pre -> next = slow -> next;//Delete it
		return head;
    }
};

int main(){
	int value;
	while(std::cin >> value){
		std::cout << value << " ";
	}
	std::cout << std::endl;
	return 0;
}

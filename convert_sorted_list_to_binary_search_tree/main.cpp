/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode *toBST(ListNode *head, int len){
		if(len == 1){
			return new TreeNode(head -> val);
		}
		int mid = len / 2;
		ListNode *midNode = head;
		while(mid > 0){
			--mid;
			midNode = midNode-> next;
		}
		TreeNode *root = new TreeNode(midNode -> val);
		root -> left = toBST(head, len / 2);
		if(len / 2 != len - 1){//If mid is not the root 
			root -> right = toBST(midNode -> next, len - len / 2 - 1);
		}
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
		if(not head){
			return NULL;
		}
		int len = 0;
		ListNode *tail = head;
		while(tail){
			++len;
			tail = tail -> next;
		}
		if(len == 1){
			return new TreeNode(head -> val);
		}
		return toBST(head, len);
	}
};

int main(){
	ListNode *root = new ListNode(1);
	root -> next = new ListNode(2);
	Solution s;
	s.sortedListToBST(root);
	return 0;
}

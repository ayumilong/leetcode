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
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	 //Recursive version
	TreeNode* toBST(const std::vector<int>& num, int start, int end){
		if(end - start == 0){
			return NULL;
		}
		if(end - start == 1){
			return new TreeNode(num[start]);
		}
		int middle = start + (end - start) / 2;
		TreeNode *root = new TreeNode(num[middle]);
		root -> left = toBST(num, start, middle);
		root -> right = toBST(num, middle + 1, end);
		return root;
	}

    TreeNode *sortedArrayToBST(std::vector<int> &num){
		int len = num.size();
		if(len == 0){
			return NULL;
		}
		int start = 0;
		int end = len;
		return toBST(num, start, end);
    }
	*/

	TreeNode *sortedArrayToBST(std::vector<int> &num){
		int len = num.size();
		if(len == 0){
			return NULL;
		}
		TreeNode *root = new TreeNode(num[len / 2]);
		std::stack<TreeNode*> nodes;//Store the nodes that have not been processed
		std::stack<std::pair<int, int> > positions;//Store the tree range of the according root
		nodes.push(root);
		positions.push(std::pair<int, int>(0, len));
		while(not nodes.empty()){
			TreeNode *cur = nodes.top();
			nodes.pop();
			std::pair<int, int> curPos = positions.top();
			positions.pop();
			int middle = curPos.first + (curPos.second - curPos.first) / 2;
			int left = curPos.first + (middle - curPos.first) / 2; //Left child
			int right = middle + 1 + (curPos.second - (middle + 1)) / 2; //right child
			if(left >= curPos.first && left != middle){//If has left child
				cur -> left = new TreeNode(num[left]);
				nodes.push(cur -> left);
				positions.push(std::pair<int, int>(curPos.first, middle));
			}
			if(right < curPos.second && right != middle){//If has right child
				cur -> right = new TreeNode(num[right]);
				nodes.push(cur -> right);
				positions.push(std::pair<int, int>(middle + 1, curPos.second));
			}
		}
		return root;
	}

	std::vector<int> inorderTraversal(TreeNode *root) {
		std::vector<int> result;
		if(root == NULL){
			return result;
		}
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		TreeNode *leftMost = root -> left;
		while(leftMost != NULL){//Push all the nodes in the left path to stack
			nodes.push(leftMost);
			leftMost = leftMost -> left;
		}
		while(not nodes.empty()){
			TreeNode *left = nodes.top(); //The current node in inorder sequence
			nodes.pop();
			result.push_back(left -> val);
			TreeNode *tmp = left -> right;
			while(tmp != NULL){ //The right sub-tree
				nodes.push(tmp);
				tmp = tmp -> left;
			}
		}
		return result;
    }
};

int main(){
	int value;
	std::vector<int> num;
	while(std::cin >> value){
		num.push_back(value);
	}
	Solution s;
	TreeNode *root = s.sortedArrayToBST(num);
	num = s.inorderTraversal(root);
	int len = num.size();
	for(int i = 0; i < len; ++i){
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}

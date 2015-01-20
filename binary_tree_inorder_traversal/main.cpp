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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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

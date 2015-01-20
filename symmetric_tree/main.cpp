/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <deque>

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
	bool helper(TreeNode *left, TreeNode *right){
		if(left == NULL && right == NULL){
			return true;
		}else if(left != NULL && right != NULL && left -> val == right -> val){
			bool result = true;
			result &= helper(left -> left, right -> right);
			result &= helper(left -> right, right -> left);
			return result;
		}else{
			return false;
		}
	}

	bool isSymmetric(TreeNode *root){
		if(root == NULL){
			return true;
		}
		return helper(root -> left, root -> right);
	}

	/*
	//Iteratively solution
    bool isSymmetric(TreeNode *root) {
		if(root == NULL){
			return true;
		}
		std::deque<TreeNode*> nodes;
		nodes.push_front(root -> left);
		nodes.push_back(root -> right);
		while(not nodes.empty()){
			while(not nodes.empty()){
				TreeNode *n1 = nodes.front();
				nodes.pop_front();
				TreeNode *n2 = nodes.back();
				nodes.pop_back();
				if(n1 == NULL && n2 == NULL){
				}else if(n1 != NULL && n2 != NULL && n1 -> val == n2 -> val){
					nodes.push_front(n1 -> right);
					nodes.push_front(n1 -> left);
					nodes.push_back(n2 -> left);
					nodes.push_back(n2 -> right);
				}else{
					return false;
				}
			}
		}
		return true;
    }
	*/
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(3);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	root -> right -> left = new TreeNode(5);
	root -> right -> right = new TreeNode(4);
	root -> left -> right -> left = new TreeNode(8);
	root -> left -> right -> right = new TreeNode(9);
	root -> right -> left -> left = new TreeNode(9);
	root -> right -> left -> right = new TreeNode(8);
	Solution s;
	if(s.isSymmetric(root)){
		std::cout << "true" << std::endl;
	}else{
		std::cout << "false" << std::endl;
	}
	return 0;
}

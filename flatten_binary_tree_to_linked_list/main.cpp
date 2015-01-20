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
	TreeNode* doFlatten(TreeNode *root){
		if(not root){
			return NULL;
		}
		TreeNode *leftList = doFlatten(root -> left);
		TreeNode *rightList = doFlatten(root -> right);
		if(leftList){
			root -> right = leftList;
			while(leftList -> right){
				leftList = leftList -> right;
			}
			if(rightList){
				leftList -> right = rightList;
			}
		}else if(rightList){
			root -> right = rightList;
		}
		return root;
	}

    void flatten(TreeNode *root) {
		if(root){
			std::stack<TreeNode*> nodes;
			nodes.push(root);
			while(not nodes.empty()){
				TreeNode *curNode = nodes.top();
				nodes.pop();
				if(curNode -> right){
					nodes.push(curNode -> right);
				}
				if(curNode -> left){
					nodes.push(curNode -> left);
				}
				if(not nodes.empty()){//The next nodes in the flatten list is at the top of the stack
					curNode -> right = nodes.top(); 
				}
				curNode -> left = NULL;
			}
		}
    }
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(5);
	root -> left -> left = new TreeNode(3);
	root -> left -> right = new TreeNode(4);
	root -> right -> right = new TreeNode(6);
	Solution s;
	s.flatten(root);
	while(root){
		std::cout << root -> val << " ";
		root = root -> right;
	}
	std::cout << std::endl;
	return 0;
}

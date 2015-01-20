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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int abs(int n){
		return (n > 0) ? n : -n;
	}

	int getHeight(TreeNode *root){
		if(root == NULL){
			return 0;
		}
		int leftHeight = getHeight(root -> left);
		int rightHeight = getHeight(root -> right);
		if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1){
			return -1;
		}
		return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
	}

    bool isBalanced(TreeNode *root){
		if(root == NULL){
			return true;
		}
		int leftHeight = getHeight(root -> left);
		int rightHeight = getHeight(root -> right);
		if(leftHeight == -1 || rightHeight == -1){
			return false;
		}
		return (leftHeight > rightHeight) ? (leftHeight - rightHeight) < 2 : (rightHeight - leftHeight) < 2;
    }
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> left -> left = new TreeNode(2);
	root -> left -> right = new TreeNode(2);
	Solution s;
	std::cout << s.getHeight(root) << std::endl;
	return 0;
}

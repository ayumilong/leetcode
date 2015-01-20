/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <queue>

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
    int maxDepth(TreeNode *root) {
		if(root == NULL){
			return 0;
		}
		std::queue<TreeNode*> curLevel;
		curLevel.push(root);
		TreeNode* curLast = root;
		TreeNode* preNode = NULL;
		int depth = 0;
		while(not curLevel.empty()){
			TreeNode *tmp = curLevel.front();
			curLevel.pop();
			if(tmp -> left != NULL){
				curLevel.push(tmp -> left);
				preNode = tmp -> left;
			}
			if(tmp -> right != NULL){
				curLevel.push(tmp -> right);
				preNode = tmp -> right;
			}
			if(tmp == curLast){
				++depth;
				curLast = preNode; 
			}
		}
		return depth;
    }
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	Solution s;
	std::cout << s.maxDepth(root) << std::endl;
	return 0;
}

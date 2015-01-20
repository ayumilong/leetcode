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
#include <queue>
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
	std::vector<std::vector<int> > levelOrderBottom(TreeNode *root){
		std::vector<std::vector<int> > result;
		if(root == NULL){
			return result;
		}
		std::vector<std::vector<int> > leftResult = levelOrderBottom(root -> left);
		std::vector<std::vector<int> > rightResult = levelOrderBottom((root -> right));
		int leftLen = leftResult.size();
		int rightLen = rightResult.size();
		std::stack<std::vector<int> > midResult;
		int i = leftLen - 1;
		int j = rightLen - 1;
		for(; i >= 0 && j >= 0; --i, --j){
			int len = rightResult[j].size();
			for(int k = 0; k < len; ++k){
				leftResult[i].push_back(rightResult[j][k]);
			}
			midResult.push(leftResult[i]);
		}
		if(i == -1){
			for(int k = j; k >= 0; --k){
				midResult.push(rightResult[k]);
			}
		}
		if(j == -1){
			for(int k = i; k >= 0; --k){
				midResult.push(leftResult[k]);
			}
		}
		while(not midResult.empty()){
			result.push_back(midResult.top());
			midResult.pop();
		}
		result.push_back(std::vector<int>(1, root -> val));
		return result;
	}
	/*
	std::vector<std::vector<int> > levelOrderBottom(TreeNode *root) {
		std::vector<std::vector<int> > result;
		if(root == NULL){
			return result;
		}
		std::queue<TreeNode*> nodes;
		nodes.push(root);
		TreeNode *levelLastNode = root;//The last node of the current level
		TreeNode *preNode = NULL; //Keep track of the possible last node of a level
		std::vector<int> levelResult; //To store all the nodes of a level
		std::stack<std::vector<int> > midResult;//To store all level to a stack then back store them to result
		while(not nodes.empty()){
			TreeNode *cur = nodes.front();
			nodes.pop();
			levelResult.push_back(cur -> val);
			if(cur -> left != NULL){
				nodes.push(cur -> left);
				preNode = cur -> left;
			}
			if(cur -> right != NULL){
				nodes.push(cur -> right);
				preNode = cur -> right;
			}
			if(cur == levelLastNode){
				levelLastNode = preNode;
				midResult.push(levelResult);
				levelResult.clear();
			}
		}
		while(not midResult.empty()){
			result.push_back(midResult.top());
			midResult.pop();
		}
		return result;
    }
	*/
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(2);
	Solution s;
	std::vector<std::vector<int> > result = s.levelOrderBottom(root);
	std::cout << result.size() << std::endl;
	return 0;
}

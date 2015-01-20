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
    int minDepth(TreeNode *root) {
		if(root == NULL){
			return 0;
		}
		std::queue<TreeNode*> nodes;
		nodes.push(root);
		TreeNode* curLast = root;
		TreeNode* preNode = NULL;
		int level = 0;
		while(not nodes.empty()){
			TreeNode *tmp = nodes.front();
			nodes.pop();
			if(tmp -> left == NULL && tmp -> right == NULL){//The hightest leaf node
				return level + 1;
			}
			if(tmp -> left != NULL){
				nodes.push(tmp -> left);
				preNode = tmp -> left;
			}
			if(tmp -> right != NULL){
				nodes.push(tmp -> right);
				preNode = tmp -> right;
			}
			if(tmp == curLast){
				++level;
				curLast = preNode;
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

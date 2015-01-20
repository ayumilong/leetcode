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
	std::vector<std::vector<int> > levelOrder(TreeNode *root) {
		std::vector<std::vector<int> > result;
		if(not root){
			return result;
		}
		std::queue<TreeNode*> nodes;
		nodes.push(root);
		TreeNode *curLast = root;
		TreeNode *preNode = NULL;
		std::vector<int> level;
		while(not nodes.empty()){
			TreeNode *curNode = nodes.front();
			nodes.pop();
			level.push_back(curNode -> val);
			if(curNode -> left != NULL){
				nodes.push(curNode -> left);
				preNode = curNode -> left;
			}
			if(curNode -> right != NULL){
				nodes.push(curNode -> right);
				preNode = curNode -> right;
			}
			if(curNode == curLast){
				result.push_back(level);
				level.clear();
				curLast = preNode;
			}
		}
		return result;
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

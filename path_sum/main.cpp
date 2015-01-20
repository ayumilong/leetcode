/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
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
	//DFS
	bool hasPathSum(TreeNode *root, int sum){
		if(root == NULL){
			return false;
		}
		int curSum = 0;
		std::deque<TreeNode*> nodes;
		nodes.push_back(root);
		curSum += root -> val;
		TreeNode *preNode = NULL;
		while(not nodes.empty()){
			if(preNode == NULL || (preNode != nodes.back() -> left && preNode != nodes.back() -> right)){
				while(nodes.back() -> left){//The most left node of this sub-tree
					nodes.push_back(nodes.back() -> left);
					curSum += nodes.back() -> val;
				}	
			}
			if(curSum == sum && nodes.back() -> left == NULL && nodes.back() -> right == NULL){//This is a leaf node and the sum is equal
				return true;
			}
			//If have not process the right node then push it into queue if it is exist
			if(nodes.back() -> right && preNode != nodes.back() -> right){
				nodes.push_back(nodes.back() -> right);
				curSum += nodes.back() -> val;
			}else{//No right node then pop the current node
				preNode = nodes.back();
				nodes.pop_back();
				curSum -= preNode -> val;
				if(not nodes.empty() && nodes.back() -> right && preNode != nodes.back() -> right){//Push the right node to queue if it is exist and has not been processed
					nodes.push_back(nodes.back() -> right);
					curSum += nodes.back() -> val;
				}
			}
		}
		return false;
	}
	/*
	//Recursion
    bool hasPathSum(TreeNode *root, int sum) {
		if(root == NULL){
			return false;
		}
		if(root -> val == sum && root -> left == NULL && root -> right == NULL){
			return true;
		}
		sum -= root -> val;
		if(hasPathSum(root -> left, sum) || hasPathSum(root -> right, sum)){
			return true;
		}
		return false;
    }
	*/
};

int main(){
	int value;
	while(std::cin >> value){
		std::cout << value << " ";
	}
	std::cout << std::endl;
	return 0;
}

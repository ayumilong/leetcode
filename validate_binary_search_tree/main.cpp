/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <climits>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	std::vector<int> inOrderTravers(TreeNode *root){
		std::vector<int> result;
		if(NULL == root){
			return result;
		}
		std::stack<TreeNode*> nodes;
		while(root){
			nodes.push(root);
			root = root -> left;
		}
		while(not nodes.empty()){
			TreeNode *cur = nodes.top();
			nodes.pop();
			result.push_back(cur -> val);
			TreeNode *right = cur -> right;
			while(right){
				nodes.push(right);
				right = right -> left;
			}
		}
		return result;
	}

	//In-order traversal
    bool isValidBST(TreeNode *root) {
		std::vector<int> seq = inOrderTravers(root);
		int len = seq.size();
		for(int i = 0; i < len - 1; ++i){
			if(seq[i] >= seq[i + 1]){
				return false;
			}
		}
		return true;
    }
};

class Solution {
public:
	bool validateBST(TreeNode *root, long long lowerLimit, long long upperLimit){
		if(NULL == root){
			return true;
		}
		if(root -> val > lowerLimit && root -> val < upperLimit){
			return validateBST(root -> left, lowerLimit, root -> val) && validateBST(root -> right, root -> val, upperLimit);
		}
		return false;
	}
	
    bool isValidBST(TreeNode *root) {
		return validateBST(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(){
	TreeNode *root = new TreeNode(1);
	root -> left = new TreeNode(1);
	Solution s;
	if(s.isValidBST(root)){
		std::cout << "First" << std::endl;
	}
	Solution1 s1;
	if(s1.isValidBST(root)){
		std::cout << "second" << std::endl;
	}
	return 0;
}

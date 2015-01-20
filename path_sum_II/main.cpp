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
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//DFS
	std::vector<std::vector<int> > pathSum(TreeNode *root, int sum){
		std::vector<std::vector<int> > result;
		if(not root){
			return result;
		}
		std::deque<TreeNode*> path(1, root);
		TreeNode *preNode = NULL;
		int curSum = root -> val;
		while(not path.empty()){
			if(NULL == preNode || (preNode != path.back() -> left && preNode != path.back() -> right)){//This is a new node, we need firstly to process its left sub-tree
				while(path.back() -> left){
					path.push_back(path.back() -> left);
					curSum += path.back() -> val;
				}
			}
			if(curSum == sum && not path.back() -> left && not path.back() -> right){//This is a leaf node and the sum of this path is the same with "sum"
				std::vector<int> onePath;
				std::deque<TreeNode*>::iterator iter = path.begin();
				while(iter != path.end()){//Store the path to result
					onePath.push_back((*iter) -> val);
					++iter;
				}
				result.push_back(onePath);
			}
			if(path.back() -> right && preNode != path.back() -> right){//No left sub-tree then to process right sub-tree directly
				path.push_back(path.back() -> right);
				curSum += path.back() -> val;
			}else{
				preNode = path.back();
				path.pop_back();
				curSum -= preNode -> val;
				if(not path.empty() && path.back() -> right && preNode != path.back() -> right){//Process the right sub-tree of current node
					path.push_back(path.back() -> right);
					curSum += path.back() -> val;
				}
			}
		}
		return result;
	}
	/*
	//Recursion
	std::vector<std::vector<int> > pathSum(TreeNode *root, int sum){
		std::vector<std::vector<int> > result;
		if(not root){
			return result;
		}
		if(root -> val == sum && not root -> left && not root -> right){//This is a leaf, then find a path
			result.push_back(std::vector<int>(1, sum));
			return result;
		}
		sum -= root -> val;
		std::vector<std::vector<int> > leftPath = pathSum(root -> left, sum);
		std::vector<std::vector<int> > rightPath = pathSum(root -> right, sum);
		int leftLen = leftPath.size();
		for(int i = 0; i < leftLen; ++i){
			leftPath[i].insert(leftPath[i].begin(), 1, root -> val);
			result.push_back(leftPath[i]);
		}
		int rightLen = rightPath.size();
		for(int i = 0; i < rightLen; ++i){
			rightPath[i].insert(rightPath[i].begin(), 1, root -> val);
			result.push_back(rightPath[i]);
		}
		return result;
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

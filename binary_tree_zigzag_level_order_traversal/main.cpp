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
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
		if(NULL == root){
			return result;
		}
		TreeNode *preNode = NULL;
		TreeNode *curLastNode = root;
		queue<TreeNode*> nodes;
		nodes.push(root);
		int level = 1;
		stack<int> levelStack;
		vector<int> levelVec;
		while(not nodes.empty()){
			TreeNode *cur = nodes.front();
			nodes.pop();
			if(level % 2 != 0){
				levelVec.push_back(cur -> val);	
			}else{
				levelStack.push(cur -> val);
			}
			if(cur -> left){
				nodes.push(cur -> left);
				preNode = cur -> left;
			}
			if(cur -> right){
				nodes.push(cur -> right);
				preNode = cur -> right;
			}
			if(cur == curLastNode){
				curLastNode = preNode;
				if(level % 2 == 0){
					while(not levelStack.empty()){
						levelVec.push_back(levelStack.top());
						levelStack.pop();
					}
				}
				result.push_back(levelVec);
				levelVec.clear();
				++level;
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

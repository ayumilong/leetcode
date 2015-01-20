/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 08 Feb 2014 11:45:42 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> postorderTraversal(TreeNode *root){ 
		std::vector<int> result;
		if(root == NULL){
			return result;
		}
		std::stack<TreeNode*> nodes;
		nodes.push(root);
		TreeNode *cur = nodes.top();
		while(cur -> left != NULL){//Get to the leftmost node
			nodes.push(cur -> left);
			cur = cur -> left;
		}
		TreeNode *preNode = NULL;
		while(not nodes.empty()){
			TreeNode *cur = nodes.top();
			if(cur -> right == preNode){//Has processed both left and right child then process the current node
				result.push_back(cur -> val);
				preNode = nodes.top();
				nodes.pop();
			}else{//Process the right sub-tree
				if(cur -> right != NULL){
					nodes.push(cur -> right);
					cur = nodes.top();
					while(cur -> left != NULL){//Process the left sub-tree
						nodes.push(cur -> left);
						cur = cur -> left;
					}
				}
				preNode = NULL;
			}
		}
		return result;
    }
};

void printTree(const std::vector<int> tree){
	std::vector<int>::const_iterator iter = tree.begin();
	while(iter != tree.end()){
		std::cout << *iter << " ";
		++iter;
	}
	std::cout << std::endl;
}
class Other{  
public:  
    std::vector<int> postorderTraversal(TreeNode *root) {  
        std::vector<int> result;  
        TreeNode* curNode = root;  
        std::stack<TreeNode*> nodeStack;  
          
        while(curNode || not nodeStack.empty()){ 
            //...delay the visit to the returned function  
            if(not curNode){ 
                while(not nodeStack.empty() && nodeStack.top()->right == curNode){ 
                    curNode = nodeStack.top();  
                    nodeStack.pop();  
                    result.push_back(curNode->val);  
                }  
                if(not nodeStack.empty()){
					curNode = nodeStack.top()->right;
				}else{
				   	curNode = NULL;
				}	
            }  
            //...process the left subtree call  
            while(curNode){ 
                nodeStack.push(curNode);  
                curNode = curNode->left;  
            }  
            //...process the right subtree call  
            if(not nodeStack.empty()){ 
                curNode = nodeStack.top();  
                curNode = curNode->right;  
            }  
        }  
        return result;  
    }  
};  

int main(){
	TreeNode *root = new TreeNode(3);
	root -> left = new TreeNode(1);
	root -> left -> right = new TreeNode(4);
	root -> left -> right -> left = new TreeNode(5);
	root -> right = new TreeNode(2);
	Solution s;
	std::vector<int> tree = s.postorderTraversal(root);
	printTree(tree);
	Other o;
	tree = o.postorderTraversal(root);
	printTree(tree);
	return 0;
}

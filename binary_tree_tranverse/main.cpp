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
	std::vector<int> postorderTraversal(TreeNode *root){ //Recursive version 
		std::vector<int> tree;
		if(root != NULL){
			std::vector<int> temp = postorderTraversal(root -> left);
			int len = temp.size();
			tree.resize(len);
			copy(temp.begin(), temp.end(), tree.begin());
			temp = postorderTraversal(root -> right);
			tree.resize(tree.size() + temp.size());
			copy(temp.begin(), temp.end(), tree.begin() + len);
			tree.push_back(root -> val);
		}
		return tree;
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
	root -> right = new TreeNode(2);
	Solution s;
	std::vector<int> tree = s.postorderTraversal(root);
	printTree(tree);
	Other o;
	tree = o.postorderTraversal(root);
	printTree(tree);
	return 0;
}

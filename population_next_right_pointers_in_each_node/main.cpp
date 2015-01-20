/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>

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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root){//Process level by level
		if(root == NULL){
			return;
		}
		TreeLinkNode *highLevelNode = root;
		TreeLinkNode *curNode = root -> left;
		TreeLinkNode *curLevelNode = curNode;
		while(curNode != NULL){
			curNode -> next = highLevelNode -> right;//Process the left child
			curNode = curNode -> next;
			highLevelNode = highLevelNode -> next;
			if(highLevelNode == NULL){//Has processed the current level
				highLevelNode = curLevelNode;
				curLevelNode = curLevelNode -> left;
				curNode = curLevelNode;
				continue;
			}
			curNode -> next = highLevelNode -> left;//Process the right child
			curNode = curNode -> next;
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

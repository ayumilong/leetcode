/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 25 Feb 2014 10:14:07 AM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

struct UndirectedGraphNode {
    int label;
	std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void printGraph(UndirectedGraphNode *node){
	if(node != NULL){
		std::vector<UndirectedGraphNode*> nodesQueue;
		nodesQueue.push_back(node);
		size_t curPos = 0;
		while(curPos < nodesQueue.size()){
			UndirectedGraphNode *curNode = nodesQueue[curPos];
			std::cout << curNode -> label << "(" << curNode << "): ";
			int len = curNode -> neighbors.size();
			for(int i = 0; i < len; ++i){
				if(curNode -> neighbors[i] != curNode && find(nodesQueue.begin(), nodesQueue.end(), curNode -> neighbors[i]) == nodesQueue.end()){
					nodesQueue.push_back(curNode -> neighbors[i]);
				}
				std::cout << curNode -> neighbors[i] -> label << "(" << curNode -> neighbors[i] << ")";
			}
			++curPos;
			std::cout << std::endl;
		}
	}
}

class Solution {
private:
	static bool cmpGraphNode(const UndirectedGraphNode *node1, const UndirectedGraphNode *node2){
		return node1 -> label < node2 -> label;
	}
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node != NULL){
			std::vector<UndirectedGraphNode*> nodesQueue;
			nodesQueue.push_back(node);
			size_t curPos = 0;
			while(curPos < nodesQueue.size()){
				UndirectedGraphNode *curNode = nodesQueue[curPos];
				++curPos;
				UndirectedGraphNode *newNode = new UndirectedGraphNode(curNode -> label);
				curNode -> neighbors.push_back(newNode); //At the first time, insert the new node to the end of the old node and just left the neighbors empty 
				int len = curNode -> neighbors.size() - 1;
				for(int i = 0; i < len; ++i){ //Push all the neighbors of current node to the queue
					if(curNode -> neighbors[i] != curNode && find(nodesQueue.begin(), nodesQueue.end(), curNode -> neighbors[i]) == nodesQueue.end()){//Not a node that point to itself and is a new node
						nodesQueue.push_back(curNode -> neighbors[i]);
					}
				}
			}
			UndirectedGraphNode *result = node -> neighbors[node -> neighbors.size() - 1]; 
			sort(nodesQueue.begin(), nodesQueue.end(), Solution::cmpGraphNode);
			curPos = 0;
			while(curPos < nodesQueue.size()){
				UndirectedGraphNode *curNode = nodesQueue[curPos];
				++curPos;
				int len = curNode -> neighbors.size() - 1;
				UndirectedGraphNode *newNode = curNode -> neighbors[len];
				curNode -> neighbors.erase(curNode -> neighbors.end() - 1);
				for(int i = 0; i < len; ++i){
					if(curNode -> neighbors[i] == curNode){
						newNode -> neighbors.push_back(newNode);
					}else{
						newNode -> neighbors.push_back(curNode -> neighbors[i] -> neighbors[curNode -> neighbors[i] -> neighbors.size() - 1]);
					}
				}
			}
			return result;
		}
		return NULL;
    }
};

int main(){
	UndirectedGraphNode *node0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *node1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *node2 = new UndirectedGraphNode(2);
	UndirectedGraphNode *node3 = new UndirectedGraphNode(3);
	UndirectedGraphNode *node4 = new UndirectedGraphNode(4);
	UndirectedGraphNode *node5 = new UndirectedGraphNode(5);
	node0 -> neighbors.push_back(node1);
	node0 -> neighbors.push_back(node5);
	node1 -> neighbors.push_back(node2);
	node1 -> neighbors.push_back(node5);
	node2 -> neighbors.push_back(node3);
	node3 -> neighbors.push_back(node4);
	node3 -> neighbors.push_back(node4);
	node4 -> neighbors.push_back(node5);
	node4 -> neighbors.push_back(node5);
	Solution s;
	std::cout << "Clone Graph" << std::endl;
	printGraph(s.cloneGraph(node0));
	std::cout << "Original Graph" << std::endl;
	printGraph(node0);
	return 0;
}

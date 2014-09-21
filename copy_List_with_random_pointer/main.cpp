/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Thu 20 Feb 2014 10:30:48 PM EST
 ************************************************************************/

#include <iostream>
#include <map>

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *anotherCopy(RandomListNode *head){
		RandomListNode *newHead = NULL;
		if(head){
			newHead = new RandomListNode(head -> label);
			head -> label = 0;
			int len = 1;
			RandomListNode *cur = head -> next;
			RandomListNode *newPre = newHead;
			while(cur){//Create deep copy list with the random pointer as NULL
				newPre -> next = new RandomListNode(cur -> label);
				cur -> label = len++; //Change nodes label in original list to their index
				newPre = newPre -> next;
				cur = cur -> next;
			}
			RandomListNode **nodeArray = new RandomListNode*[len];
			newPre = newHead;
			for(int i = 0; i < len && newPre; ++i){//Map deep copy list to a array use their index
				nodeArray[i] = newPre;
				newPre = newPre -> next;
			}
			newPre = newHead;
			cur = head;
			while(newPre){//Store the random pointer of the new deep copy list
				if(cur -> random != NULL){
					newPre -> random = nodeArray[cur -> random -> label];
				}
				newPre = newPre -> next;
				cur = cur -> next;
			}
			newPre = newHead;
			cur = head;
			while(cur){//Restore the labels of the original list
				cur -> label = newPre -> label;
				cur = cur -> next;
				newPre = newPre -> next;
			}
		}
		return newHead;
	}
	RandomListNode *fastCopy(RandomListNode *head){
		if(head == NULL){
			return NULL;
		}
		RandomListNode *pre = head;
		while(pre){//Create new nodes in the original List
			RandomListNode *temp = pre -> next;
			pre -> next = new RandomListNode(pre -> label);
			pre -> next -> next = temp;
			pre = temp; 
		}
		pre = head;
		while(pre){//Find the random node that the new nodes should point to
			pre -> next -> random = (pre -> random == NULL) ? NULL : (pre -> random -> next);
			pre = pre -> next -> next;
		}
		RandomListNode *newHead = head -> next; //The head of the new deep copy list
		head -> next = head -> next -> next;
		pre = head -> next;
		RandomListNode *newPre = newHead;
		while(pre){//Get the new list
			newPre -> next = pre -> next;
			pre -> next = pre -> next -> next;
			pre = pre -> next;
			newPre = newPre -> next;
		}
		return newHead;
	}
    RandomListNode *copyRandomList(RandomListNode *head) {
		RandomListNode *newHead = NULL;
		RandomListNode *pre = NULL;
		std::map<RandomListNode*, RandomListNode*> randomNodes;
		if(head != NULL){
			newHead = new RandomListNode(head -> label);
			randomNodes[head] = newHead;
			if(head -> random != NULL){ //Find random node that head points to
				newHead -> random = new RandomListNode(head -> random -> label);
				randomNodes[head -> random] = newHead -> random;
			}
			pre = newHead;
			RandomListNode *temp = head -> next;
			while(temp){
				if(randomNodes.find(temp) == randomNodes.end()){//The node has not been established
					pre -> next = new RandomListNode(temp -> label);
					randomNodes[temp] = pre -> next;
				}else{//The node has been established
					pre -> next = randomNodes[temp];
				}
				pre = pre -> next;
				if(temp -> random != NULL){
					if(randomNodes.find(temp -> random) == randomNodes.end()){
						pre -> random = new RandomListNode(temp -> random -> label);
						randomNodes[temp -> random] = pre -> random;
					}else{
						pre -> random = randomNodes[temp -> random];
					}
				}
				temp = temp -> next;
			}
		}
		return newHead;
		/* //O(n2), too slow
		RandomListNode *newHead = NULL;
		RandomListNode *pre = NULL;
		if(head != NULL){
			newHead = new RandomListNode(head -> label);
			pre = newHead;
			RandomListNode *temp = head -> next;
			while(temp){
				pre -> next = new RandomListNode(temp -> label);
				pre = pre -> next;
				temp = temp -> next;
			}		
			temp = head;	
			RandomListNode *newTemp = newHead;
			while(temp){
				RandomListNode *random = temp -> random;
				if(random != NULL){
					RandomListNode *randomTemp = head;
					RandomListNode *newRandomTemp = newHead;
					while(randomTemp != random){
						randomTemp = randomTemp -> next;
						newRandomTemp = newRandomTemp -> next;
					}
					newTemp -> random = newRandomTemp;
				}
				temp = temp -> next;
				newTemp = newTemp -> next;
			}
		}
		return newHead;
		*/
    }
};

int main(){
	RandomListNode *head = new RandomListNode(-1);
	head -> next = new RandomListNode(1);
	Solution s;
	RandomListNode *newHead = s.fastCopy(head);
	return 0;
}

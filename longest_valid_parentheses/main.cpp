/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Sat 22 Feb 2014 04:40:48 PM EST
 ************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

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

class Solution {
public:
	bool isParentheses(std::string s){
		std::stack<char> ps;
		int len = s.size();
		for(int i = 0; i < len; ++i){
			if(s[i] == '('){
				ps.push('(');
			}else{
				if(ps.empty()){
					return false;
				}else{
					ps.pop();
				}
			}
		}
		if(ps.empty()){
			return true;
		}else{
			return false;
		}
	}

	//DP solution
	int longestValidParentheses(std::string s){
		int len = s.size();
		std::vector<int> subLongest(len); //subLongest[i] means the longest valid parentheses in the substring which ends in ith char
		int maxLen = 0;
		for(int i = 1; i < len; ++i){
			if(s[i] != ')'){
				continue;
			}else{
				int startPos = i - subLongest[i - 1] - 1;
				if(startPos >= 0 && s[startPos] == '('){
					subLongest[i] = subLongest[i - 1] + 2;
					if(--startPos >= 0){ //Join adjacent valid parentheses
						subLongest[i] += subLongest[startPos];
					}
					//Update maxLen
					maxLen = maxLen > subLongest[i] ? maxLen : subLongest[i];
				}
			}
		}
		return maxLen;
	}

	/*
	//Solution using a stack
	int longestValidParentheses(std::string s){
		std::stack<int> ps;
		int maxLen = 0;
		int len = s.size();
		for(int i = 0; i < len; ++i){
			if(s[i] == '('){
				ps.push(i);
			}else{
				if(not ps.empty() && s[ps.top()] == '('){
					ps.pop();
					int startPos = -1;
					if(not ps.empty()){
						startPos = ps.top();
					}
					int curLen = i - startPos;
					maxLen = (maxLen > curLen) ? maxLen : curLen;
				}else{
					ps.push(i);
				}
			}
		}
		return maxLen;
	}
	*/

	/*
	//Too slow
    int longestValidParentheses(std::string s) {
		int len = s.size();
		int max = 0;
		for(int i = 0; i < len - 1; ++i){
			if(isParentheses(s.substr(i, len - i))){
				max = len - i;
				break;
			}
			int r1 = longestValidParentheses(s.substr(i + 1, len - i - 1));
			int r2 = longestValidParentheses(s.substr(i, len - i - 1));
			max = r1 > r2 ? r1 : r2;
			if(max != 0){
				return max;
			}
		}
		return max;
    }
	*/
};

int main(){
	std::string str;
	Solution s;
	while(std::cin >> str){
		std::cout << s.longestValidParentheses(str) << std::endl;
	}
	std::cout << std::endl;
	return 0;
}

/*
struct Vertex{
	int num; //The value of the vertex
	int brotherNum; //The number of edges related to this vertex
	int unlabledBrother; //The number of unlabled vertexes that related to this vertex
	struct Node* head; //The list of vertexes that related to this vertex
};

struct Node{
	int num; //Which vertex this node refers to
	struct Node* next; //Next node that refer another vertex
};

1 int findCenter(struct Vertex myTree[], int len){
2	int i = 0;
3	int labledVertex = 0; //Number of vertexes that have been labled
4	while(true){
5		if(myTree[i].unlabledBrother == 1){ //This is one of the vertexes that should be labled now
6			++labledVertex;
7			if(labledVertex == len){ //All the vertex has been labled
8				return i; //Vertex i is the last vertex that be labled, so it is the center
9			}
10			--myTree[i].unlabledBrother;
11			struct Node* head = myTree[i].head;
12			while(head != NULL){//Decrease all the number of unlabled vertexes that related to this vertex
13				--myTree[head -> num].unlabledBrother; 
14				head = head -> next;
15			}
16		}	
17		++i;
18		if(i == len){
19			i = 0;
20		}
21	}
22}
*/

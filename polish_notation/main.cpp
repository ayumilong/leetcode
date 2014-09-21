/*************************************************************************
    > File Name: main.cpp
    > Subject: 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Tue 28 Jan 2014 12:01:04 PM EST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
private:
	stack<int> expr;
	int pop(){
		int n = expr.top();
		expr.pop();
		return n;
	}

public:
    int evalRPN(vector<string> &tokens) {
		int len = tokens.size();
		int i = 0;
		while(i < len){
			switch(tokens[i][0]){
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8':
				case '9': 
					{
						expr.push(atoi(tokens[i].c_str()));
						break;
					}
				case '+':
					{
						expr.push(pop() + pop());
						break;
					}
				case '-':
					{
						if(tokens[i].size() != 1){ //This is a signed integer
							expr.push(atoi(tokens[i].c_str()));
							break;
						}
						int n = pop();
						expr.push(pop() - n);
						break;
					}
				case '*':
					{
						expr.push(pop() * pop());
						break;
					}
				case '/':
					{
						int n = pop();
						if(n == 0){
							std::cout << "Cannot divide by zero" << std::endl;
							pop();
							return pop();
						}
						int n1 = pop();
						expr.push(n1/n);
						break;
					}
				default:
					{
						std::cout << "Line 66: Invalid expression  " << i << std::endl;
						return pop();
					}
			}
			++i;
		}
		if(expr.size() != 1){
			std::cout << "Line 72: Invalid expression" << std::endl;
		}
		return pop();
    }
};


int main(){
	vector<string> tokens;
	string temp;
	while(std::cin >> temp){
		tokens.push_back(temp);
	}
	Solution sol;
	cout << sol.evalRPN(tokens) << endl;
}

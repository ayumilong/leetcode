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

//Store the gap between min and actual value
class MinStack {
private:
	std::stack<long long> stack;
	int min;
public:
	MinStack(): stack(), min(0){
	}
    void push(int x) {
		if(stack.empty()){
			stack.push(0);
			min = x;
		}else{
			stack.push((long long)x - min);
			if(x < min){
				min = x;
			}
		}
    }

    void pop() {
		if(not stack.empty()){
			if(stack.top() < 0){
				min -= stack.top();
			}
			stack.pop();
		}
    }

    int top() {
		long long t = stack.top();
		if(t < 0){
			return min;
		}else{
			return t + min;
		}
    }

    int getMin() {
		return min; 
    }
};

int main(){
	MinStack stack;
	stack.push(2147483646);	
	stack.push(2147483646);	
	stack.push(2147483647);	
	std::cout << stack.top() << std::endl;
	stack.pop();
	std::cout << stack.getMin() << std::endl;
	stack.pop();
	std::cout << stack.getMin() << std::endl;
	stack.pop();
	stack.push(2147483647);	
	std::cout << stack.top() << std::endl;
	std::cout << stack.getMin() << std::endl;
	stack.push(-2147483648);	
	std::cout << stack.top() << std::endl;
	std::cout << stack.getMin() << std::endl;
	stack.pop();
	std::cout << stack.getMin() << std::endl;
	return 0;
}

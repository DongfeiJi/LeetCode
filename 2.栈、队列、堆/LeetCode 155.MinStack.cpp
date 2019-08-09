/*
准备两个栈，一个data，一个min，push时候，data直接push，min先判断push的数是否大于min的top
*/
#include <stdio.h>
#include <stack>

class MinStack {
public:
    MinStack() {/** initialize your data structure here. */
    }//构造函数
    void push(int x) {
    	_data.push(x);
    	if (_min.empty()){//这里注意编程思路，按照实际走，先考虑第一次push情况
	    	_min.push(x);
	    }
	    else{//下面统一处理更为方便，将小的数传给x，就是为了保证push的x是与min中较小的那个数
	    	if (x > _min.top()){
	    		x = _min.top();
	    	}
    		_min.push(x);
    	}
    }
    void pop() {
    	_data.pop();
    	_min.pop();
    }
    int top() {
        return _data.top();
    }
    int getMin() {
        return _min.top();
    }
private:
	std::stack<int> _data;
	std::stack<int> _min;
};

int main(){
	MinStack minStack;
	minStack.push(-2);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	minStack.push(0);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.push(-5);
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());
	minStack.pop();
	printf("top = [%d]\n", minStack.top());
	printf("min = [%d]\n\n", minStack.getMin());	
	return 0;
}

   /** 
    1.push改进，使队列从左到右54321，设栈中已经是从上到下1234满足题意，如何push5？就是用临时栈
    设原始栈里面有从上到下1234，来个5，则将1234先pop，再push到临时栈，临时栈为从上到下4321
    再将5push进入临时栈，临时栈从上到下就变为54321
    再将临时栈导到原始栈，原始栈从上到下为12345满足要求
    2.pop 弹出队列头，就是栈pop
    3.peek返回队列头部即front，就是栈top
    4，empty等价的不变
    */
#include <stdio.h>

#include <stack>	
class MyQueue {
public:
    MyQueue() {
    }
    void push(int x) {
        std::stack<int> temp_stack;
        while(!_data.empty()){//第一步将data导入到temp
        	temp_stack.push(_data.top());
        	_data.pop();
        }
        temp_stack.push(x);//第二步将输入加入到temp
        while(!temp_stack.empty()){//第三步将temp导入到data
        	_data.push(temp_stack.top());
        	temp_stack.pop();
        }
    }
    int pop() {
    	int x = _data.top();
    	_data.pop();
        return x;
    }
    int peek() {
        return _data.top();
    }
    bool empty() {
        return _data.empty();
    }
private:
	std::stack<int> _data;
};

int main(){
	MyQueue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	printf("%d\n", Q.peek());
	Q.pop();
	printf("%d\n", Q.peek());	
	return 0;
}

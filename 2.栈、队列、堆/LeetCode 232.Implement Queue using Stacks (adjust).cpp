   /**
     * 特点: 队列:先进先出 栈:先进后出
     * 思路: 使用两个栈输入栈A、输出栈B.
     * 1.入队列时,将数据进入A栈
     * 2.出队列时,若B不为空，那么从B栈弹出，若B为空，那么将A全部弹出到B，再弹出B。
     *因此需要一个调整函数，当输出栈不为空，无需调整。当输出栈为空，那么将输入栈中全部弹出到输出栈。
     *
     */
#include <stdio.h>

#include <stack>	
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    std::stack<int> _input;
    std::stack<int> _output;
    /** Push element x to the back of queue. */
    void push(int x) {
       _input.push(x); 
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        adjust();
        int x = _output.top();
        _output.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        adjust();
        return _output.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _input.empty()&&_output.empty();
    }
private:
    void adjust(){
        if(!_output.empty()) return;
        while(!_input.empty()){
        _output.push(_input.top());
         _input.pop();
        }
    }
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

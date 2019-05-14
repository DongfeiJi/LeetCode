 /** Initialize your data structure here.
    用队列实现栈，就是用两个队列实现，左手倒右手思想，画图，栈由上至下54321，
    那么一个队列假设从左到右已经是1234，如何push5?
    即再用一个临时队列push5，将1234加入到5，即12345，这样拿出头就是，54321
  */
#include <stdio.h>

#include <queue>
class MyStack {
public:
    MyStack() {        
    }
    void push(int x) {
    	std::queue<int> temp_queue;//临时队列
    	temp_queue.push(x);//push的内容先存入临时队列
    	while(!_data.empty()){
	    	temp_queue.push(_data.front());//data里的东西倒入临时队列变为12345
	    	_data.pop();//别忘了对data pop操作
	    }
	    while(!temp_queue.empty()){//再存回data
   			_data.push(temp_queue.front());
   			temp_queue.pop();
    	}
    }
    int pop() {
        int x = _data.front();
    	_data.pop();
    	return x;
    }
    int top() {
        return _data.front();
    }
    bool empty() {
        return _data.empty();
    }
private:
	std::queue<int> _data;
};

int main(){
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	printf("%d\n", S.top());
	S.pop();
	printf("%d\n", S.top());
	S.push(5);
	printf("%d\n", S.top());	
	return 0;
}

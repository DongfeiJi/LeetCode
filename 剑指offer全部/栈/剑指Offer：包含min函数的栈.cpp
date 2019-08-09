//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
class Solution {
public:
    void push(int value) {//原理就是始终保持最小栈栈顶为最小值
        Data.push(value);
        if(Min.empty()){//第一次往最小栈push的时候特殊处理下
            Min.push(value);
        }
        if(value < Min.top()){//如果push的值小与最小栈栈顶，就push当前值
            Min.push(value);
        }
        else{
            Min.push(Min.top());//否则，重复的push，最小栈栈顶
        }
    }
    void pop() {
        Data.pop();
        Min.pop();
    }
    int top() {
        return Data.top();
    }
    int min() {
        return Min.top();
    }
private:
    stack<int> Data;
    stack<int> Min;
};
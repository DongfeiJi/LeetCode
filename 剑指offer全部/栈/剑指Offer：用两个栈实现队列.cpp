/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

栈实现队列就是两个栈实现队列的功能，对于实现push功能，pop功能，只需要固定一个即可，一般固定push
push的时候直接push到stack1即可
pop的时候，先判断stack2不为空，然后一次性将stack1中元素全部push到stack2
特点：
1，stack2中不为空，不倒换
2，一旦倒换，stack1要全部倒换到stack2
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);//push固定push到stack1
    }

    int pop() {
        if(stack2.empty()){//只有stack2中为空，才可以倒换
            while(stack1.size() > 0){//只要倒换，一次性把stack1中倒换过去
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        int data = stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
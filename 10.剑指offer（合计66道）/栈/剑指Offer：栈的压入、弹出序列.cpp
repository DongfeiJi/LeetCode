/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是1，
然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，
所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，直到不相等，这样循环等压栈顺序遍历完成，
如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。
核心：利用一个辅助栈，将pushV中元素不断push到栈，实时查看popV，一旦发现是pop的元素，就pop然后把popV下标++
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() == 0){//若输入pushV数组为空，返回false
            return false;
        }
        int j = 0;//定有popV下标
        for(int i = 0; i < pushV.size(); i++){
            mystack.push(pushV[i]);//若栈顶和popV不等，那么一直将pushV中元素push到栈
            while(j < popV.size() && mystack.top() == popV[j]){//这里不要忘记j不要越界
                mystack.pop();//栈顶和popV的最前面元素相等，栈pop，j下标后移
                j++;
            }
        }
        return mystack.empty();//栈最后为空，代表符合题意
    }
private:
    stack<int> mystack;
};
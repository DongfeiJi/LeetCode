/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

1，此题目要考虑算法的稳定性，即前后顺序保持不变
2，STL中不同容器之间是不能直接赋值的，assign（）可以实现不同容器但相容的类型赋值
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        deque<int> result;
        int size = array.size();
        for(int i = 0; i < size; i++){
            if(array[size - 1 - i] % 2 == 1){//注意deque是双向队列，从前push，顺序就反了，所以倒着遍历
                result.push_front(array[size - 1 - i]);
            }
            if(array[i] % 2 == 0){
                result.push_back(array[i]);
            }
        }
        array.assign(result.begin(), result.end());
    }
};
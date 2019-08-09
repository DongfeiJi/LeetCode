/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P%1000000007

这是一个归并排序的合并过程，主要是考虑合并两个有序序列时，计算逆序对数。
对于两个升序序列，设置两个下标：两个有序序列的末尾。每次比较两个末尾值，如果前末尾大于后末尾值，则有”后序列当前长度“个逆序对；
否则不构成逆序对。然后把较大值拷贝到辅助数组的末尾，即最终要将两个有序序列合并到辅助数组并有序。
这样，每次在合并前，先递归地处理左半段、右半段，则左、右半段有序，且左右半段的逆序对数可得到，再计算左右半段合并时逆序对的个数。
个人理解：这就是mergesort过程，创建一个辅助vector，比较大小，这只不过是从后面向前面比较的。
需要辅助数组是因为在递归时候，需要排序好的数组这个信息，才可以计算count。
 
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0){//特殊情况处理，data没有，一定没有逆序对
            return 0;
        }
        vector<int> copy;
        for(int i = 0; i < data.size(); i++){
            copy.push_back(data[i]);//设置好拷贝数组
        }
        return partition(data, copy, 0, data.size() - 1) % 1000000007;//返回的结果不要忘记取余数，一定要看题目返回
    }
    //注意：InversePairsCore形参的顺序是(data,copy)，而递归调用时实参是(copy,data)。
    //要明白递归函数InversePairsCore的作用就行了，它是对data的左右半段进行合并，复制到辅助数组copy中有序。
    //之所以交换copy和data的顺序是因为：
    //经过排序后data左半部分仍旧乱序，但copy左半部分已经存储了排好序的data左半部分，
    //即已经保存了data左半部分的信息，这样在向上层递归时，data左半部分本身可以作为容器，copy左半部分作为已经排好序的一个单元，即待排序列的一个元素。
    long partition(vector<int> &data, vector<int> &copy, int begin, int end){
        if(begin == end){
            copy[begin] = data[end];//data此时其实就是不动，就是排序好，再拷贝到copy
            return 0;//这是递归最小子问题，也是递归跳出条件
        }
        int mid = (end + begin) >> 1;;
        long leftcount = partition(copy, data, begin, mid);// 使data左半段有序，并返回左半段逆序对的数目
        long rightcount = partition(copy, data, mid + 1, end);/// 使data右半段有序，并返回右半段逆序对的数目
        int i = mid;
        int j = end;//定义下标，二分法返回时候处理求count，都指向左右两部分的最后一个位置
        int copyindex = end;//拷贝数组，就是从最后一个开始存储
        long count = 0;//注意这里是long
        while(i >= begin && j >= mid + 1){//在各自满足条件时候，其实是从最后一个下标一直--到最前面
            if(data[i] > data[j]){
                copy[copyindex--] = data[i--];//如果前面的大，拷贝到copy，然后计算count
                count += j - mid;//由于两边已经有顺序，此时逆序对共有，右侧前面的全部数字，都是逆序对
            }
            else{
                copy[copyindex--] = data[j--];//不大，就不是逆序对，直接拷贝大的到copy
            }
        }
        for(; i >= begin; i--){
            copy[copyindex--] = data[i];//这就是mergesort，有剩余直接拷贝
        }
        for(; j >= mid + 1; j--){
            copy[copyindex--] = data[j];//这就是mergesort，有剩余直接拷贝
        }
        return leftcount + rightcount + count;
        //逆序对的总数 = 左边数组中的逆序对的数量 + 右边数组中逆序对的数量 + 左右结合成新的顺序数组时中出现的逆序对的数量
    }
};
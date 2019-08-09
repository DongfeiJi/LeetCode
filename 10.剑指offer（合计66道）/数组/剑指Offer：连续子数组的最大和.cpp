/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,
他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,
问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

数组分析：下图是我们计算数组（1，-2，3，10，-4，7，2，-5）中子数组的最大和的过程。
通过分析我们发现，累加的子数组和，如果大于零，那么我们继续累加就行；
否则，则需要剔除原来的累加和重新开始。
*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()){
            return 0;
        }
        int MaxSum = array[0];
        int CurSum = array[0];//定义初始第一个为下标为0的值
        for(int i = 1; i < array.size(); i++){
            if(CurSum < 0){//说明到这个节点，前面的和小于0，那一定要舍弃，并且将当前节点值赋值给CurSum
                CurSum = array[i];
            }
            else{
                CurSum += array[i];//如果前面和大于0，就累加
            }
            if(CurSum > MaxSum){
                MaxSum = CurSum;//始终将最大值，赋值给MaxSum
            }
        }
        return MaxSum;
    }
};
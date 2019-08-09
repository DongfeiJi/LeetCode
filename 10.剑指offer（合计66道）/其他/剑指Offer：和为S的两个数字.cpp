/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。对应每个测试案例，输出两个数，小的先输出。

对于一个数组，我们可以定义两个指针，一个从左往右遍历（pleft），另一个从右往左遍历（pright）。
首先，我们比较第一个数字和最后一个数字的和curSum与给定数字sum，
如果curSum < sum，那么我们就要加大输入值，所以，pleft向右移动一位，重复之前的计算；
如果curSum > sum，那么我们就要减小输入值，所以，pright向左移动一位，重复之前的计算；
如果相等，那么这两个数字就是我们要找的数字，直接输出即可。
这么做的好处是，也保证了乘积最小。
算法核心：保证乘积最小，就用排序数组的两端开始判断即可。
1，定义结果数组
2，求输入数组长度，并且判断非法输入
3，定义左右指针
4，while循环合理性，左小于右
求和
if判断如果相等，先push左，再push右，最后break
如果小于，加大输入，就是left++
如果大于，减小输入，就是right--
5，return result
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int length = array.size();
        if(length < 1){
            return result;//非法输入判断
        }
        int pLeft = 0, pRight = length - 1;//左右指针
        while(pLeft < pRight){//判断合理性，跳出条件
            int twoSum = array[pLeft] + array[pRight];//求和
            if(twoSum == sum){//满足条件返回结果
                result.push_back(array[pLeft]);
                result.push_back(array[pRight]);
                break;
            }
            else if(twoSum > sum){
                pRight--;//当前和较大，减小输入
            }
            else{
                pLeft++;//当前和较小，加大输入
            }
        }
        return result;
    }
};
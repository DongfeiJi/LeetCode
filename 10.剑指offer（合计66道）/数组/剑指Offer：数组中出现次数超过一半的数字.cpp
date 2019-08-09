/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，
因此输出2。如果不存在则输出0。

数组中有一个数字出现的次数超过数组长度的一半，也就是说它出现的次数比其他所有数字出现次数的和还要多。
因此我们可以考虑在遍历数组的时候保存两个值：一个是数组的一个数字，一个是次数。当我们遍历到下一个数字的时候，
如果下一个数字和我们之前保存的数字相同，则次数加1；如果下一个数字和我们之前保存的数字不同，则次数减1。
如果次数为零，我们需要保存下一个数字，并把次数设为1。由于我们要找的数字出现的次数比其他所有数字出现的次数之和还要多，
那么要找的数字肯定是最后一次把次数设为1时对应的数字。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()){
            return 0;//特殊情况判断，输入为空直接返回0
        }
        int result = numbers[0];
        int times = 1;//下标为0的先设定为result，并且times初始化为1
        for(int i = 1; i < numbers.size(); i++){//从下标为1的开始判断
            if(times == 0){//这里注意times是判断条件，一般放在循环最前面
                result = numbers[i];//times为0，说明这个结果出现次数一定不大于二分之一
                times = 1;//初始化，从下一个节点继续判断
            }
            else if(numbers[i] == result){//1，如果等于，times++
                times++;
            }
            else{
                times--;//不等就--
            }
        }//这段代码就是最后可以找出可能是出现次数最大的那个点，但是不确定是否出现的次数大于了size的一半
        times = 0;//重新初始化，后面计算result出现的次数到底大于size的一半不
        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == result){
                times++;
            }
        }
        return (times > (numbers.size() >> 1)) ? result : 0;
    }
};

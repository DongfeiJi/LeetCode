/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的
所有字符串abc,acb,bac,bca,cab和cba

我们求整个字符串的排列，可以看成两步：首先求所有可能出现在第一个位置的字符，即把第一个字符和后面所有的字符交换。
首先固定第一个字符，求后面所有字符的排列。
这个时候我们仍把后面的所有字符分为两部分：后面的字符的第一个字符，以及这个字符之后的所有字符。
然后把第一个字符逐一和它后面的字符交换。
这个思路，是典型的递归思路。
总结：
结果result声明在类全局
1，声明结果vector，判断非法输入
2，调用子函数，进行递归排列组合
3，排序后返回
子函数：从第一个位置开始，和之后所有不重复的地方的值进行交换，递归的进行下去，因此形参一个是输入str，一个是begin=0
1，如果begin等于长度，递归跳出，str存入result
2，for循环，判断i不等于begin并且当前位置与for循环位置值相等，不交换continue，否则，交换，最后递归进行
ps：递归在for循环里面，因为要对后面的也递归（即把后面的所有字符分为两部分：后面的字符的第一个字符以及之后的所有字符）
*/
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.length() <= 0){
            return result;//输入非法以及输入为空情况
        }
        PermutationCore(str, 0);//调用子函数返回所有result
        sort(result.begin(), result.end());//排序是根据题目要求
        return result;
    }
private:
    void PermutationCore(string str, int begin){//子函数是根据输入字符串返回全部可能排列组合，begin用于递归+1，必须要有
        if(begin == str.length()){
            result.push_back(str);//一次递归跳出，push到result，并且返回
            return;
        }
        for(int i = begin; i < str.length(); i++){//从头开始遍历
            if((i != begin) && str[i] == str[begin]){//如果值相等，不交换（注意i开始是自己，也没必要交换，这是为了提高效率）
                continue;
            }
            swap(str[begin], str[i]);
            PermutationCore(str, begin + 1);//递归在for循环内部，因为后面的也需要递归交换
        }
    }
    vector<string> result;//result只可以被类内使用
};

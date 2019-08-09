/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

遇到这个题，全排列当然可以做，但是时间复杂度为O(n!)。在这里我们自己定义一个规则，对拼接后的字符串进行比较。
排序规则如下：
若ab > ba 则 a 大于 b，
若ab < ba 则 a 小于 b，
若ab = ba 则 a 等于 b；
根据上述规则，我们需要先将数字转换成字符串再进行比较，因为需要串起来进行比较。比较完之后，按顺序输出即可。
！！！！注意在C++中，cmp函数要是使用static进行声明，声明是静态成员函数，这样才能正确调用。
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int length = numbers.size();
        if(length == 0){//特殊情况，对于string类型返回的是“”，char是‘’
            return "";
        }
        sort(numbers.begin(), numbers.end(), cmp);//基于排序规则对numbers排序，此时还是int类型
        string result;
        for(int i = 0; i < length; i++){
            result += to_string(numbers[i]);//int类型转换为string
        }
        return result;
    }
private:
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;//这里这样排序，是自己设计的规则，而且string类型比较大小，是基于ASCII码，幸好数值大小与ASCII大小成正比
    }
};
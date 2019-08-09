/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，
这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。

观察字符串变化规律，你会发现这道题很简单。只需要对每个单词做翻转，然后再整体做翻转就得到了正确的结果。
总结：
1，定义length、定义result并将result赋值为str
2，输入特殊情况长度为0
3，给result追加一个空格‘ ’，为了区别最后一个单词统一处理，定义一个mark相当于开始翻转的begin、
4，for循环，这里注意，result长度由于补全了一个空格要+1，判断，遇到了空格，说明当前遇到了单词结束，此时调用子函数反转该单词，
最后下一个单词由于隔了一个空格，因此mark+1
5，利用substr，去掉最后一个空格
6，调用子函数，整体再反转一下
7，返回结果
子函数：反转字符串，因此形参就是，str，begin，end，返回void，
1，利用while判断，然后swap前后下标begin++，end-- 

*/
class Solution {
public:
    string ReverseSentence(string str) {
        int length = str.size();
        string result = str;//定义length、定义result并将result赋值为str
        if(length == 0){
            return "";//输入特殊情况长度为0,注意这里返回的是string类型，双引号
        }
        result += ' ';//给result追加一个空格‘ ’，为了区别最后一个单词统一处理
        int mark = 0;//定义一个mark相当于开始翻转的begin
        for(int i = 0; i < length + 1; i++){//for循环，这里注意，result长度由于补全了一个空格要+1，
            if(result[i] == ' '){
                ReverseWord(result, mark, i - 1);//判断，遇到了空格，说明当前遇到了单词结束，此时调用子函数反转该单词，
                mark = i + 1;//最后下一个单词由于隔了一个空格，因此mark+1
            }
        }
        //利用substr，去掉最后一个空
        result = result.substr(0, length);//substr用法是从下标0开始，返回length个字符
        ReverseWord(result, 0, length - 1);//调用子函数，整体再反转一下
        return result;
    }
private:
    void ReverseWord(string &str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);//利用while判断，然后swap前后下标begin++，end-- 
        }
    }
};
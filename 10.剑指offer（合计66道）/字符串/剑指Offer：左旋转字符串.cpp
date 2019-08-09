/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！

例如：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到的结果"cdefgab";
第一步：翻转字符串“ab”，得到"ba"；
第二步：翻转字符串"cdefg"，得到"gfedc"；
第三步：翻转字符串"bagfedc"，得到"cdefgab"；
或者：
第一步：翻转整个字符串"abcdefg",得到"gfedcba"
第二步：翻转字符串“gfedc”，得到"cdefg"
第三步：翻转字符串"ba",得到"ab"
本人方法总结：
1，定义result就是str，定义长度简化代码量
2，非法输入，长度小于0
3，对于输入n，也要判断是否非法，即if的n在0到length之间
3.1，定义两段指针，分别指向两部分头尾，一共四个下标，调用子函数翻转
4，返回
子函数:功能就是实现字符串翻转，输入一个字符串，begin还有end进行转换
即：while循环begin小于end，swap（里面下标要++），void类型
//方法1：
 class Solution {
public:
    string LeftRotateString(string str, int n) {
  if(str.empty()||n<=0||n>=str.size())
   return str;
  string substr1=str.substr(0,n),substr2=str.substr(n);
  return substr2+substr1;
    }
};
//方法2：
class Solution {
public:
     string LeftRotateString(string str, int n) {
  if(str.empty()||n<=0||n>=str.size())
   return str;
  reverse(str,0,n-1);
  reverse(str,n,str.size()-1);
  reverse(str,0,str.size()-1);
  return str;
  }
  void reverse(string &str,int beg,int end)
  {
   while(beg<end)
   {
    char tmp=str[beg];
    str[beg]=str[end];
    str[end]=tmp;
    beg++;
    end--;
   }
  }
};
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        string result = str;
        int length = str.size();
        if(length < 0){//非法输入，长度小于0
            return NULL;
        }
        if(0 <= n <= (length-1)){//对于输入n，也要判断是否非法，即if的n在0到length之间
            int leftBegin = 0, leftEnd = n - 1;//左侧，头尾下标
            int rightBegin = n, rightEnd = length - 1;//右侧，头尾下标
            ReverseString(result, leftBegin, leftEnd);//反转左侧
            ReverseString(result, rightBegin, rightEnd);//反转右侧
            ReverseString(result, leftBegin, rightEnd);//全部反转
        }
        return result;
    }
private:
    void ReverseString(string &str, int begin, int end){
        while(begin < end){
            swap(str[begin++], str[end--]);
        }
    }
};
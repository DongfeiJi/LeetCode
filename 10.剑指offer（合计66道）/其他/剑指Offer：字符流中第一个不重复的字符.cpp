/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，
第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
如果当前字符流没有存在出现一次的字符，返回#字符。

将字节流保存起来，通过哈希表统计字符流中每个字符出现的次数，顺便将字符流保存在string中，
然后再遍历string，从哈希表中找到第一个出现一次的字符。
*/
class Solution{
public:
  //Insert one char from stringstream
    void Insert(char ch){//将字符保存在字符串，并且利用字符哈希记录出现次数
         s += ch;
        count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce(){
        int length = s.size();
        for(int i = 0; i < length; i++){//循环遍历字符串
            if(count[s[i]] == 1){//如果第一个出现次数为1，返回
                return s[i];
            }
        }
        return '#';//否则都没出现一次，返回#
    }
private:
    string s;//字符流
    int count[256] = {0};//这里是c语言中的数组，int类型，开辟256个int类型空间，初始化为0，下标0~255
};
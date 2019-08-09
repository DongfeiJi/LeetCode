/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.

建立一个哈希表，第一次扫描的时候，统计每个字符的出现次数。
第二次扫描的时候，如果该字符出现的次数为1，则返回这个字符的位置。
总结：
1，定义length，判断非法输入
2，创建字符哈希
3，for遍历str，字符哈希++
4，for再遍历，如果字符哈希值为1，那么返回i
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int length = str.size();
        if(length == 0){
            return -1;
        }
        map<char, int> count;
        for(int i = 0; i < length; i++){
            count[str[i]]++;//for遍历str，字符哈希++
        }
        for(int i = 0; i < length; i++){//for再遍历，如果字符哈希值为1，那么返回i
            if(count[str[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
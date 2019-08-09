/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

分析下如何匹配一个字符，现在只考虑字符'.'，不考虑'*'看一下：
如果字符串和模式串的当前字符相等，那么我们继续匹配它们的下一个字符；
如果模式串中的字符是'.'，注意字符串此时不能为终止符，那么它可以匹配字符串中的任意字符，我们也可以继续匹配它们的下一个字符。

接下来，把字符'*'考虑进去，它可以匹配任意次的字符，当然出现0次也可以。
我们分两种情况来看：
模式串的下一个字符不是'*'，也就是上面说的只有字符'.'的情况。
如果字符串中的第一个字符和模式串中的第一个字符相匹配，那么字符串的模式串都向后移动一个字符，
然后匹配剩余的字符串和模式串。如果字符串中的第一个字符和模式中的第一个字符不相匹配，则直接返回false。

模式串的下一个字符是'*'，此时就要复杂一些。
因为可能有多种不同的匹配方式。
选择一：无论字符串和模式串当前字符相不相等，我们都将模式串后移两个字符，相当于把模式串中的当前字符和'*'忽略掉，
因为'*'可以匹配任意次的字符，所以出现0次也可以。
选择二：如果字符串和模式串当前字符相等，则字符串向后移动一个字符。而模式串此时有两个选择：
1、我们可以在模式串向后移动两个字符，继续匹配；
2、也可以保持模式串不变，这样相当于用字符'*'继续匹配字符串，也就是模式串中的字符'*'匹配字符串中的字符多个的情况。
总结：
1，if判断指针为空，返回false
2，返回 调用子函数的返回值
子函数：实现字符串与模式串是否匹配，返回bool型，输入就是str和pattern
1，如果str和pattern都遇到结束符\0，返回true
（对于.比较好判断，对于*不好判断，可能性较多）
2，if*（pattern+1）字符为*
2.1，如果str和pattern相等或者pattern为‘.’且str不是\0，此时由于pattern的下一个就是*，*可以代表重复前一个0-n次
所以此时返回情况有多种，比如;
str不抵消不变，pattern不抵消走两个，再判断
str抵消走一个，pattern抵消不走
str抵消走一个，pattern抵消走两个
2.2，否则就是str和pattern不相等，此时str不抵消不变，pattern不抵消走两个，再判断
3，因此，首先if判断当前str与pattern相等的情况或者pattern是‘.’（此时，str不是\0）
递归进行str+1，pattern+1
（上面是没有遇到*的情况，比较正常，一旦pattern下一个为*，情况有多种）
4，上面没返回true，返回false
*/
class Solution {
public:
    bool match(char* str, char* pattern){
        if(str == NULL || pattern == NULL){
            return false;//指针为空，返回false
        }
        return matchCore(str, pattern);
    }
private:
    bool matchCore(char* str, char* pattern){
        if(*str == '\0' && *pattern == '\0'){
            return true;//如果str和pattern都遇到结束符\0，返回true
        }
        if(*(pattern + 1) == '*'){//如果pattern下一个就是*
            if(*str == *pattern || (*pattern == '.' && *str != '\0')){//当前值相等
                return matchCore(str, pattern + 2) ||//不抵消，*当作0次
                    matchCore(str + 1, pattern) || //抵消，*当作重复很多次
                    matchCore(str + 1, pattern + 2);;//抵消，*当作1次
            }
            else{//当前值不等
                return matchCore(str, pattern + 2);//不抵消，*当作0次
            }
        }
        if(*str == *pattern || (*pattern == '.' && *str != '\0')){//当前值相等，不考虑*
            return matchCore(str + 1, pattern + 1);
        }
        return false;//这就是当前值不等，且pattern下一个不是*，返回false即可
    }
};
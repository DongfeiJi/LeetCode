/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

最简单的方法就是从头到尾遍历，但是时间复杂度为O(n^2)。
这里采用一种时间复杂度为O(n)的方法。
先遍历一次字符串，这样就可以统计出字符串空格的总数，并可以由此计算出替换之后的字符串的总长度。
每替换一个空格，长度增加2，因此替换以后字符串的长度等于原来的长度加上2乘以空格数目。
以"We are happy"为例，"We are happy"这个字符串的长度为13（包括结尾符号"\0"），
里面有两个空格，因此替换之后字符串的长度是17。
从字符串的尾部开始复制和替换。
首先准备两个指针，P1和P2，P1指向原始字符串的末尾，而P2指向替换之后的字符串的末尾。
接下来我们向前移动指针P1，逐个把它指向的字符复制到P2指向的位置，直到碰到第一个空格为止。
碰到第一个空格之后，把P1向前移动1格，在P2之前插入字符串"%20"。由于"%20"的长度为3，同时也要把P2向前移动3格
总结：
1，定义下标变量i与空格数量numsapce
2，利用while不为"\0"进行遍历，求去numspace
3，重新计算长度，并且作为最后一个指针，注意此时，i和newLen都不包含"\0"
4，从字符串最后面开始遍历重新赋值，j指向原字符串，newLen指向的是扩充替换后的字符串
*/
class Solution {
public:
    //这里这个length是字符串的输入数组长度，大于实际输入的str，但是扩充后不能大于这个length
    void replaceSpace(char *str,int length) {
        int i = 0;
        int numspace = 0;//定义下标变量i与空格数量numsapce
        while(str[i] != '\0'){
            if(str[i] == ' '){
                numspace++;//利用while不为"\0"进行遍历，求空格数量numspace
            }
            i++;
        }
        int newLen = i + numspace * 2;//计算出来的新长度
        if(newLen > length){//这里判断下，扩充如果大于给定的length，就return
            return;
        }
        //从字符串最后面开始遍历重新赋值，j指向原字符串，newLen指向的是扩充替换后的字符串
        for(int j = i; j >= 0, newLen >= 0; j--){
            if(str[j] == ' '){
                str[newLen--] = '0';
                str[newLen--] = '2';
                str[newLen--] = '%';
            }
            else{
                str[newLen--] = str[j];
            }
            //这里注意最开始j=i，他们指向的是\0前面的最后一个下标内容，所以从这里开始赋值
        }
    }
};
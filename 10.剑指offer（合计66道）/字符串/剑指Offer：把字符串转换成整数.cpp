/*
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。

思路：
注意题意，代码合理性应该判断各种非法情况来增加鲁棒性，要判断非法输入以及输入为0都是返回0.
这道题要考虑全面，对异常值要做出处理。对于这个题目，需要注意的要点有：
指针是否为空指针以及字符串是否为空字符串；
字符串对于正负号的处理；
输入值是否为合法值，即小于等于'9'，大于等于'0'；
int为32位，需要判断是否溢出；
使用错误标志，区分合法值0和非法值0。
//代码中用两个函数来实现该功能，其中标志位g_nStatus用来表示是否为异常输出，minus标志位用来表示是否为负数。

补充尝试内容：
1，C++ 允许程序员创建自己的数据类型，比如本节要将的枚举类型。枚举数据类型是一种由程序员定义的数据类型，其合法值是与它们关联的一组命名整数常量。
2，c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同.
这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式。
注意：一定要使用strcpy()函数 等来操作方法c_str()返回的指针
3，int(4个字节，32位)            long(4个字节，32位)           long long(8个字节，64位)
4，0x80000000是32位有符号整型的最小值，32位有符号整型的范围是 -2147483648到2147483647，并且一定是signed int类型
0x7fffffff是32位有符号整型的最大值

总结：
1，由于可能存在int溢出，因此定义num类型为long long
2，c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同
定义一个输入str的 常量 字符 指针cstr，其中*cstr表示指向内容，cstr++表示常量指针后移
3，if判断是否为常量指针以及是否为空字符串，如果是，表示合理，可以进行处理
3.1，定义一个符号标志位，minus=false，默认是正
3.2，直接对第一个*cstr判断正负，若为正，指针后移，若为负，符号标志位置负，指针后移，因调用子函数转换是不带正负号的
3.3，如果后面不是\0结束符号，调用子函数进行字符串转换整数
4，上面均不符合，直接返回0，即：由于子函数返回的是longlong类型，最后return要强制转换为int
子函数：实现将字符串转换为整数，为了防止溢出，返回longlong，输入是常量字符指针，以及符号标志位
1，定义longlong类型的num
2，while判断没有遇到结束标识符\0
2.1，判断是不是非法值，即大于0，小于9，这里用的是ASCII码，
如果是，那么定义flag就是int的正负号，用三目运算发计算
num的计算是累计，10乘以num+flag乘以与0的ASCII之差，判断最后的num是否溢出上下限（各自带符号判断），溢出num清0后break，最最后指针后移
否则就是不是数字的非法，num清0后break
3，返回num
*/
class Solution {
public:
    int StrToInt(string str) {
        long long num = 0;//防止int溢出，定义num类型为long long
        const char* cstr = str.c_str();//定义一个输入str的 常量 字符 指针cstr，其中*cstr表示指向内容，cstr++表示常量指针后移
        if(cstr != NULL && *cstr != '\0'){//if判断是否为常量指针以及是否为空字符串，如果是，表示合理，可以进行处理
            bool minus = false;//定义一个符号标志位，minus=false，默认是正
            if(*cstr == '+'){
                cstr++;//默认为正，只需后移指针
            }
            else if(*cstr == '-'){
                minus = true;
                cstr++;//遇到-，符号标志位置负，指针再后移，因为子函数调用，不能带+-，所以先后移一下
            }
            if(*cstr != '\0'){//如果符号后面有数字
                num = StrToIntCore(cstr, minus);
            }
        }
        return (int)num;//看题目要求返回int，强制转换一下
    }
private:
    long long StrToIntCore(const char* cstr, bool minus){
        long long num = 0;
        while(*cstr != '\0'){//由于cstr一直在++，所以这是用while循环遍历
            if(*cstr >= '0' && *cstr <= '9'){//字符串内容在0-9之间，合法，可以进入转换
                int flag = minus ? -1 : 1;//符号标志位换算为int，用于计算num
                num = num * 10 + flag * (*cstr - '0');
                if((flag == 1 && num > 0x7fffffff) || (flag == -1 && num < (signed int)0x80000000)){//如果溢出
                //if((!minus && num > 0x7fffffff) || (minus && num < (signed int)0x80000000)){
                    num = 0;
                    break;//num清0，break
                }
                cstr++;
            }
            else{//字符串内容不在0-9之间，不合法
                num = 0;
                break;//num清0，break
            }
        }
        return num;
    }
};
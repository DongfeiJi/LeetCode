/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

const char*和char const *是等价的，可以修改指针的值（整体修改），但不可以修改指针指向的内容
char * const不可以修改指针的值，但是可以修改指针指向的内容
const谁就是可以修改谁

补充学习指针:
int *p ;//*p指针，指向int类型

C语言中没有真正的字符串类型，可以通过字符数组表示字符串，因为它的元素地址是连续的。
c++包含string，因此存在 const char* cstr=str.to_str();使c和c++兼容

对于str[10]="China"，C语言中规定数组代表数组所在内存位置的首地址，也是 str[0]的地址，即str = &str[0];
先看 char *a[];
由于[ ]的优先级高于* 所以a先和 [ ]结合，他还是一个数组，数组中的元素才是char * 

前面讲到char* 是一个变量，保存的地址。。
所以 char *a[ ] = {"China","French","America","German"}；
理解为c语言没有string，char*代表，字符串的字符串首地址

char **为二级指针，s保存一级指针char*的地址
举例：
char* a[ ] ={"China","French","America","German"};
char **s =a;
为什么能把 a赋给s,因为数组名a代表数组元素内存单元的首地址，即 a = &a[0] = 0012FF38;


本题思路：
char c：c为一个字符
char *p：p指向一个char类型的指针，可以类似看作是一个字符数组
char **p：p指向一个指针，该指针是指向一个char类型的指针，可以类似看作是个指向字符串数组的指针。
在数值之前可能有一个表示正负的'+'或者'-'。
接下来是若干个0到9的数位表示数值的整数部分（在某些小数里可能没有数值的整数部分）。
如果数值是一个小数，那么在小数后面可能会有若干个0到9的数位表示数值的小数部分。
如果数值用科学记数法表示，接下来是一个'e'或者'E'，以及紧跟着的一个整数（可以有正负号）表示指数。

判断一个字符串是否符合上述模式时，
首先看第一个字符是不是正负号。
如果是，在字符串上移动一个字符，继续扫描剩余的字符串中0到9的数位。
如果是一个小数，则将遇到小数点。
另外，如果是用科学记数法表示的数值，在整数或者小数的后面还有可能遇到'e'或者'E'。

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
// 其中A和C都是整数（可以有正负号，也可以没有）
// 而B是一个无符号整数，一定为正，比如1.401298E-45

总结：
1，判断非法输入，空指针或者\0，都返回false
2，首先对正负号判断，用if，string++
3，定义结果bool值，numeric = true;
4，为了简单，调用子函数过滤掉正常数字，这里要传引用
5，如果没有到结束符号\0
5.1，if遇到了小数点（小数情况），string++，继续调用子函数过滤掉正常数字，
如果遇到eE，调用科学记数法的判断子函数赋值给numeric
5.2，if直接遇到eE(其实是整数情况)，调用科学记数法的判断子函数赋值给numeric
5.3，什么都没遇到就是遇到了非法字符，返回false
6，返回numeric以及结尾是不是\0，与逻辑

过滤正常数字子函数：实现扫描数字，合法的直接跳过，返回void，传入char** string，** string表示内容，* string表示下表
1，当不是结束符号\0，并且大于等于0，小于等于9，（*string）++

判断科学记数法子函数：判断科学计数法表示的是否合法，返回布尔，输入同上
1，现在是到达了eE，先string++
2，对于下一个下标内容，遇到+ -，再跳过++
3，如果直接遇到结束符号，就是12e\0，返回false
4，都不是，调用过滤正常数字子函数，
5，返回是不是到达结尾的三目运算符
*/
class Solution {
public:
    bool isNumeric(char* string){//string代表该指针指向字符串的第一个地址
        if(string == NULL || *string == '\0'){
            return false;//判断非法输入，空指针或者\0，都返回false
        }
        if(*string == '+' || *string == '-'){
            string++;//先遇到+-，指针后移
        }
        bool numeric = true;//初始化为真，因为有扫描数值函数，扫描到结尾就是真
        scanDigits(&string);//扫描数值子函数，一直扫描到非数值，传引用是子函数是char**，&string才是char**类型
        if(*string != '\0'){//没扫描到结束符号，这就是不是普通正常整数如100
            if(*string == '.'){//小数
                ++string;//指针后移
                scanDigits(&string);//扫描数值
                if(*string == 'e' || *string == 'E'){//科学计数法
                    numeric = isExponential(&string);
                }
            }
            else if(*string == 'e' || *string == 'E'){//整数
                numeric = isExponential(&string);//科学计数法
            }
            else{
                numeric = false;//什么都不是就是非法字符
            }
        }
        return numeric && (*string == '\0');//这里注意一定带上(*string == '\0')，因为只能有一个.以及eE
    }
private:
    void scanDigits(char** string){//char **p：p指向一个指针，该指针是指向一个char类型的指针，可以类似看作是个指向字符串数组的指针。
        while(**string != '\0' && **string >= '0' && **string <= '9'){//数字跳过，直到非数字停止
            (*string)++;//必须加括号
        }
    }
    bool isExponential(char** string){//判断科学计数法是否合理，后面判断都在此，因此返回bool赋值给numeric
        (*string)++;//已经是eE，先指针后移
        if(**string == '+' || **string == '-'){//遇到+ - 再后移
            (*string)++;
        }
        if(**string == '\0'){//直接遇到结束符号，比如100e，返回假
            return false;
        }
        scanDigits(string);//这里的string就是**
        return (**string == '\0') ? true : false;//能到达结尾就返回真
    }
};
//这个是否合理12e2.4254e-34,是利用之判断一次实现的，即代码循环编译执行，所以允许里面仅仅包含一个.和eE
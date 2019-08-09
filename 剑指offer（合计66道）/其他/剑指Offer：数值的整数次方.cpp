/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

原码就是符号位加上真值的绝对值, 即用第一位表示符号, 其余位表示值.
反码的表示方法是:
正数的反码是其本身
负数的反码是在其原码的基础上, 符号位不变，其余各个位取反.
补码的表示方法是:
正数的补码就是其本身
负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)

思路：
当指数为负数的时候，可以先对指数求绝对值，然后算出次方的结果之后再取倒数。
如果底数为0，则直接返回0。此时的次方在数学上是没有意义的。
在计算次方的时候，除了简单的遍历，
对于偶数我们可以先将n/2，分别求n/2次方再相乘，
对于奇数我们可以先将n-1/2，分别求n-1/2次方再相乘，最后乘底
除此之外，我们要注意：由于计算机表示小数（包括float和double型小数）都有误差，
不能直接用等号（==）判断相等，如果两个小数的差的绝对值很小，比如小于0.0000001，就可以认为它们相等。

算法：
1，先调用子函数判断base是否为0.0，return 的是0.0
2,定义无符号整数absExponent为0，然后对exponent求绝对值，并且复制给absExponent
3，定义result等于调用子函数求得次方
4，判断指数exponent小于0，result取倒数
5，返回result
子函数：判断两个double类型是否相等，传入两个double，返回布尔
如果两个数相减，或者调过来，都小于-0.000001或者大于0.0000001，就是相等，否则不等
子函数：求base的n次方，返回的是double，输入是double的base，以及无符号整形指数exponent
1，指数为0，返回1
2，指数为1，返回base
3，定义结果，递归调用，exponent不断右移，即递归/2
4，函数功能result*=result；
5，最底层子问题也就是递归返回，if指数exponent变成了1，那么返回，最底层就是result*=base
6，最后返回result
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if(isEqual(base, 0.0)){//非法输入判断底为0.0
            return 0.0;
        }
        unsigned int absExponent = 0;//指数为负，先转化为正，再求
        if(exponent > 0){
            absExponent = (unsigned int)(exponent);
        }
        else{
            absExponent = (unsigned int)(-exponent);
        }
        double result = PowerCore(base, absExponent);//调用子函数求结果，注意指数为奇数的处理
        if(exponent < 0){
            result = 1.0 / result;//负指数不要忘记求倒数
        }
        return result;
    }
private:
    bool isEqual(double num1, double num2){//c++==有精度丢失解决办法
        if((num1 - num2 < -0.00000001) && (num1 - num2 > 0.00000001)){
            return true;
        }
        else{
            return false;
        }
    }
    double PowerCore(double base, unsigned int exponent){
        if(exponent == 0){
            return 1.0;//指数为0特殊情况
        }
        //if(exponent == 1){//指数为1特殊情况
            //return base;//但是其实还是可以省略，因为后面递归只不过当成1乘了
        //}
        double result = PowerCore(base, exponent >> 1);//递归先求指数的一半
        result *= result;//递归处理内容
        if(exponent & 0x1 == 1){//exponent为奇数，所以这里要单独乘一个base
            result *= base;//这里不仅仅是最小子问题哦，一定要加在后面，因为奇数最后乘以base
        }
        return result;
    }
};
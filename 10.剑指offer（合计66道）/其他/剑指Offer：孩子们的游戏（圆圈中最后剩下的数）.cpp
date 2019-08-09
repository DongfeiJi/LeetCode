/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:
首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,
从他的下一个小朋友开始,继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围
。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；
依此规律重复下去，直到圆桌周围的人全部出列。
通常解决这类问题时我们把编号从0~n-1，最后 [1]  结果+1即为原问题的解。

如果只求最后一个报数胜利者的话，我们可以用数学归纳法解决该问题，为了讨论方便，先把问题稍微改变一下，并不影响原意：
问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人继续从0开始报数。求胜利者的编号。
比如n=5，5个人，m=13，
我们知道第一个人(编号一定是m%n-1) 出列之后，剩下的n-1个人组成了一个新的约瑟夫环（以编号为k=m%n的人开始）:
k k+1 k+2 ... n-2, n-1, 0, 1, 2, ... k-2并且从k开始报0。
现在我们把他们的编号做一下转换：
k --> 0
k+1 --> 1
k+2 --> 2
...
...
k-2 --> n-2
k-1 --> n-1
变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解：

例如xnew是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情况的解吗？
变回去的公式很简单，相信大家都可以推出来：xold=(xnew+k)%n。
令f[i]表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。
递推公式：
f[1]=0;
f[i]=(f[i-1]+m)%i; (i>1)

算法核心;参考https://blog.csdn.net/tingyun_say/article/details/52343897
设n=9，m=4，画两个圆，old和new，
new种去掉的是下标为m-1=3，在new种将下标为4（死了的下一个就是相当于最终活着的下标）开始赋值为0~7，
那么此时，new种第0个人就是当前问题的解（存活者），只需要将此坐标变换到old种，就是原问题的解
最后基于for循环迭代的求解
补充:坐标变换公式，被杀的人的下标其实是m%n-1，存活的人下标old是m%n，new是0，
可以将0+补全杀死前面的人m，再对n取余数就是old坐标，也可以总结规律
到现在，成功假设了，移除一个人后，new坐标和old坐标的关系，因此本题目求最后存活的，可以根据最小自问题反推回去最old的位置
1，非法输入判断，n和m都小于1，返回-1
2，定义第一个初始为0，这是最小子问题，即只有一个人，解就是0，定义res=0
for循环，从2开始，循环到n
迭代计算res
3，return
*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m < 1){
            return -1;//非法输入
        }
        int res = 0;//最小子问题，杀到只有一个人
        for(int i = 2; i <= n; i++){
            res = (res + m) % i;//从1个人2个人反推到n个人，人数+1时候坐标换算的输入是子问题的结果，如何递归实现？
        }
        return res;
    }
};
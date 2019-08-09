/*
这道题递归很好写，但是存在很严重的效率问题。我们以求解f(10)为例类分析递归的求解过程。想求f(10)，需要先求得f(9)和f(8)。
同样，想求得f(9)，需要先求的f(8)和f(7)....我们可以用树形结构来表示这种依赖关系
不难发现在这棵树中有很多结点是重复的，而且重复的结点数会随着n的增加而急剧增加，这意味计算量会随着n的增加而急剧增大。
事实上，递归方法计算的时间复杂度是以n的指数的方式递增的。
所以，使用简单的循环方法来实现。
这里涉及到一点点dp思想
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0){
            return 0;//非法输入小于0，以及输入为0边界
        }
        if(n == 1){
            return 1;//输入为1边界
        }
        int first = 0, second = 1, third = 0;//定义三个连续变量初始化
        for(int i = 2; i <= n; i++){//迭代循环
            third = first + second;
            first = second;
            second = third;
        }
        return third;//返回最终值
    }
};
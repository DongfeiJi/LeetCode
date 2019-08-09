/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），
因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

和上一道题矩阵中的路径十分相似，只不过这次的限制条件变成了坐标位数之和，且更简单
因为是从（0，0）开始移动，主函数中无需两个for循环
对于求坐标位数之和，单独用一个函数实现，然后套入上一道题的代码中即可。
 
总结：
1，定义int类型count作为返回值
2，非法输入判断，都是小于等于0，返回false
3，定义visited数组，并且menset置0
4，count=调用子函数实现计算
5，释放内存，返回count
子函数：实现返回查找机器人可以最远到达多少格子，返回的就是int count，输入是矩阵，总行，总列，当前行，当前列，visited数组
1，定义count，初始化为0
2，if判断 行列符合题意+调用子函数求数字位数之和小于等于阈值+visited数组未访问过
visited标记访问过
count= 1 + 上下左右四次递归(加和)
3，返回count
子函数；实现计算位数之和，返回的是int位数之和sum，输入就是int num
1，定义sum初始化为0
2，不断将num对于10进行运算，统计各个位，因此用while保证num不为0
sum累计num%10
num再/10
返回num
 
*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols){
        int count = 0;//初始化结果变量为0
        if(threshold <= 0 || rows <= 0 || cols <= 0){
            return count;//非法输入判断
        }
        bool* visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);//定义一个记录节点访问状态的数组，并且置0
        count = movingCountCore(threshold, rows, cols, 0, 0, visited);//调用子函数求count
        delete[] visited;
        return count;//释放内存，并且返回count
    }
private:
    int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
        int count = 0;//初始化count
        //判断 行列符合要求+行列位数之和小于阈值+节点未访问过
        if(row >= 0 && row < rows && col >= 0 && col < cols && (numCount(row) + numCount(col) <= threshold) && !visited[row * cols + col]){
            visited[row * cols + col] = true;//标记节点访问过
            count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row, col - 1, visited);//递归求总和
        }
        return count;
    }
    int numCount(int num){//求位数之和代码
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

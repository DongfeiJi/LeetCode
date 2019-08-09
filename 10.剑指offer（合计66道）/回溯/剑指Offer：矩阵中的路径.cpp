/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

补充知识：
1，memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。
一定要记住如果要把一个char a[20]清零，一定是 memset(a,0,20*sizeof(char));
2，c++传引用，如果变量名作为实参和形参，这种方式传给形参的是变量的值，传递是单向的。
如果在执行函数器件形参的值变了，不会回传给实参。也就是说如果想要实现一个这样的功能：调用函数后实参的值随之改变。
显然此方式无法实现。
因此子函数传参，如果传引用，相当于绑定，就可以联动改变主函数里面的变量值
 
 
 
思路：
这是一个可以用回溯法解决的典型问题。
首先，遍历这个矩阵，我们很容易就能找到与字符串str中第一个字符相同的矩阵元素ch。
然后遍历ch的上下左右四个字符，如果有和字符串str中下一个字符相同的，就把那个字符当作下一个字符（下一次遍历的起点）
如果没有，就需要回退到上一个字符，然后重新遍历。为了避免路径重叠，需要一个辅助矩阵来记录路径情况。
 
下面代码中，当矩阵坐标为（row，col）的格子和路径字符串中下标为pathLength的字符一样时，
从4个相邻的格子（row，col-1）、（row-1，col）、（row，col+1）以及（row+1，col）中
去定位路径字符串中下标为pathLength+1的字符。
如果4个相邻的格子都没有匹配字符串中下标为pathLength+1的字符，
表明当前路径字符串中下标为pathLength的字符在矩阵中的定位不正确，回到前一个字符串（pathLength-1），然后重新定位。
一直重复这个过程，直到路径字符串上所有字符都在矩阵中找到格式的位置（此时str[pathLength] == '\0'）。
 
总结：
1，判断非法输入，return false
2，new一个bool形的visited数组，大小为行*列，并且用指针表示
3，将其设置为0，即从未访问过
4，设置类型为int的，str的下标pathLength，初始化为0
5，循环每一行，循环每一列，如果调用子函数说明当前值包含str中下标pathLength对应的值，释放visited，返回true
6，否则释放内存，返回false
子函数：实现判断整个矩阵是否包含str路径，输入是矩阵指针，总行，总列，当前行，当前列，str指针，str下标pathLength（传引用）
1，如果str遇到结束符号\0，返回真
2，定义布尔类型haspath作为返回值，初始化为false
3，if判断如果行列满足条件，并且矩阵当前值和str值相同，这里注意计算矩阵当前值换算,并且visited没访问过
pathLength++
设定visited=true
haspath=递归调用四次位置不同的子函数
如果发现haspath不存在，证明此次递归失败，需要回溯
visited变为false，str下标pathLength--
4，返回haspath
*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str){
        if(matrix == NULL || rows <= 0 || cols <= 0 || str == NULL){
            return false;//判断非法输入
        }
        bool* visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);//定义visited数组，bool形，并且全部置false
        int pathLength = 0;//str下标初始化为0
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){//遍历matrix每一个节点
                if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited)){//存在路径中元素
                    delete[] visited;
                    return true;//释放内存，返回真
                }
            }
        }
        delete[] visited;
        return false;//否则释放内存，返回假
    }
private:
    bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str,int &pathLength, bool* visited){
        if(str[pathLength] == '\0'){
            return true;//将字符串遍历到了结束符证明存在路径
        }
        bool hasPath = false;//初始化结果标志为false
        //判断行列符合题意+矩阵当前值和str当前值相等+visited数组未访问过，只有这样下面才会递归
        if(row >= 0 && row < rows && col >=0 && col < cols && str[pathLength] == matrix[row * cols + col] && !visited[row * cols + col]){
            ++pathLength;
            visited[row * cols + col] = true;//访问该节点后，str下标后移，visited数组标记
            hasPath = hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
                hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
                hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited) ||
                hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited);//上下左右递归
            if(!hasPath){
                --pathLength;
                visited[row * cols + col] = false;//不存在，回溯，此时str下标不要忘记--，visited数组要置false
            }
        }
        return hasPath;//返回结果
    }
};

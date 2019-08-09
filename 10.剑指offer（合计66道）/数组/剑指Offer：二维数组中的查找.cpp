/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

首先选取数组中右上角的数字。如果该数字等于要查找的数字，查找过程结束；如果该数字大于要查找的数组，剔除这个数字所在的列；
如果该数字小于要查找的数字，剔除这个数字所在的行。也就是说如果要查找的数字不在数组的右上角，
则每一次都在数组的查找范围中剔除一行或者一列，这样每一步都可以缩小查找的范围，直到找到要查找的数字，或者查找范围为空。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();//二维数组的size一般都是最后一个维度，二维数组就是有多少行
        int cols = array[0].size();
        if(!array.empty() && rows > 0 && cols >0){//满足条件时才会进行while循环缩小范围
            int row = 0;
            int col = cols - 1;//这里是从第一行最后一列开始
            while(row < rows && col >= 0){//这里 raw <= raws-1也可以，就是行列满足条件
                if(array[row][col] == target){
                    return true;
                }
                else if(array[row][col] > target){
                    --col;//此时，当前值大于target，说明在当前值左侧范围
                }
                else{
                    ++row;//此时，当前值小于targht，说明在当前值下面范围
                }
            }
        }
        return false;
    }
};
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

将结果存入vector数组，从左到右，再从上到下，再从右到左，最后从下到上遍历。
算法：
1，定义行和列分别求其值，定义result
2，如果行列为0，返回result
3，定义左右上下用来遍历
4，while满足条件，即左小于等于右，上小于等于下
从左到右遍历，push结果
从上到下，push结果，注意top + 1，因此右上节点已经打印过
从右向左，if判断一下top和bottom不等，push结果，因为这代表最后一次，注意right - 1，此时右下节点已打印过
从下到上，if判断一下左不等右，push结果，因为这代表最后一次，注意bottom - 1，此时左下节点已打印过，注意 top + 1;，此时左上节点已打印过
上下左右全部++
5，返回result
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();//求行列size
        vector<int> result;
        if(rows == 0 && cols ==0){//非法输入，行列为0
            return result;
        }
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;//定义遍历的边界
        while(left <= right && top <= bottom){
            //从左到右
            for(int i = left; i <= right; ++i){
                result.push_back(matrix[top][i]);
            }
            //从上到下
            for(int i = top + 1; i <= bottom; ++i){//注意top + 1，因此右上节点已经打印过
                result.push_back(matrix[i][right]);
            }
            //从右到左
            if(top != bottom){//这是要判断停止了
                for(int i = right - 1; i >= left; --i){//注意right - 1，此时右下节点已打印过
                    result.push_back(matrix[bottom][i]);
                }
            }
            //从下到上
            if(left != right){//这是要判断停止了
                for(int i = bottom - 1; i >= top + 1; --i){//注意bottom - 1，此时左下节点已打印过
                    result.push_back(matrix[i][left]);//注意 top + 1;，此时左上节点已打印过
                }
            }
            left++, top++, right--, bottom--;//千万不要忘记
        }
        return result;
    }
};

/*
题目变种，按照这种规则，给定一个数字2，按照此规则打印2*2矩阵1234
python：
def matrix(target):
    num = target * target
    left, right, top, bottom = 0, target-1, 0, target-1
    res = [ [0 for col in range(target)] for row in range(target)]
    each = 1
    while left <= right and top <= bottom and each <= num:
        for i in range(left, right+1):
            res[top][i] = each
            each += 1
        for i in range(top+1, bottom+1):
            res[i][right] = each
            each += 1
        if top != bottom:
            for i in range(left, right)[::-1]:
                res[bottom][i] = each
                each += 1
        if left != right and each <= num:
            for i in range(top+1, bottom)[::-1]:
                res[i][left] = each
                each += 1
        top += 1
        left += 1
        bottom -= 1
        right -= 1
    for i in range(len(res)):
        print("\t".join('%s' %id for id in res[i]))
 
if __name__ == '__main__':
    matrix(4)
*/
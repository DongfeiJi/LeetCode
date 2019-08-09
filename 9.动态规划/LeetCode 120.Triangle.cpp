/*
这是二维dp问题
思考问题：从下到上，从上到下，这两种思维方式一样么？怎么选可以让递推更容易，更少的考虑边界条件？
状态：
dp[i][j]表示第i行，第j列的最优解
思考：
先考虑从上向下递推，自己画图自己走一遍
原三角形，设置一个最优解三角形
需要画出最优解三角形，最优解替换最后一层，再递推下去，最左侧与最右侧的路径是固定的，其余位置要判断
实际证明，下一层位置，只能从上一层某两个位置，到达
从下往上考虑同样要画出三角形
结论：从上到下思考，要考虑最左侧，最右侧特殊情况，而从下向上思考无需考虑特殊情况
算法：
1，设置一个二维数组，最优值三角形dp[][]，初始化为0，dp[i][j]代表了当前点最优解
2，从三角形低向上进行dp
a，边界：三角形最下一层就是最优值
b，利用i循环，从倒数第二层递推到最上面一层，对于每层各列，进行dp
对于第i行，第j列最优解dp[i][j]，前一个状态的两个位置的最优解为dp[i+1][j],dp[i+1][j+1]
递推式dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]
3,返回dp[0][0]
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0){
            return 0;//特殊情况的处理
        }
        std::vector<std::vector<int>> dp;//设置dp二维数组
        for(int i = 0; i < triangle.size(); i++){
            dp.push_back(std::vector<int>());
            for(int j = 0; j < triangle[i].size(); j++){
                dp[i].push_back(0);//初始化设置一个全是0的dp数组
            }
        }
        for(int i = 0; i < dp.size(); i++){
            dp[dp.size() - 1][i] = triangle[dp.size() - 1][i];//边界是三角形最后一层，每一个点的最优解就是自身
        }
        for(int i = dp.size() - 2; i >= 0; i--){//从倒数第二层dp到第0层
            for(int j = 0; j < dp[i].size(); j++){//每一行dp
                dp[i][j] = std::min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
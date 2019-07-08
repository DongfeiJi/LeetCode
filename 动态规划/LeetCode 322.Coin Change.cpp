/*
c++刷题答案：https://github.com/DongfeiJi/LeetCode
这道题做过，但是有一点不同，因为钞票和金额是指定的不包含全部种类面值，用贪心算法（每次拿最大的钞票）很容易遇到反例
算法；
钞票面值coins[1,2,5,7,10] 金额；14
状态dp[i]代表金额i的最优解
数组dp存储金额1，2，3，。。。14的最优解
递推关系：
对于金额i，可有金额i-1与面值为1的钞票表示，或者i-2与面值为2的钞票表示，总结规律i可由i-coins[?]与coins[?]表示
因此dp[i]可以有dp[i-coins[?]]进行状态转移得到
推导出状态转移方程为：dp[i]=min(dp[i-1],dp[i-2],dp[i-5],dp[i-7],dp[i-10])+1,因为张数最少的再加上1张
边界：
边界就是dp[coin[j]]=1或者-1，一共用面值最大的那么多个边界
因此，可以设dp[0]=0,来简化边界
dp[1]=1+dp[0]
dp[2]=1+dp[0]
.....
最终：
对于coins[]={1,2,3,5,7,10}
设i表示金额，coins[j]代表第j个面值
当i-coins[j] >= 0且dp[i-coins[j]] != -1时候，（理解一下就是当前金额大于面值，并且上一个状态可以被表示）
j=0,1,2,3,4 coins[j]=1,2,3,5,7,10
dp[i]=getmin(dp[i-coins[j]])+1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp;
        for(int i = 0; i <= amount; i++){
            dp.push_back(-1);//初始化dp数组全部为-1，用于从dp0开始递推
        }
        dp[0]=0;//简化后的边界条件
        for(int i = 1; i <= amount; i++){//循环全部金额
            for(int j = 0; j < coins.size(); j++){//循环全部面值，即循环全部可到达状态
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1){//理解一下就是当前金额大于面值，并且上一个状态可以被表示,下面递推求最小
                    if(dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1){//理解为当前未计算过或者当前不是最优解，下面才要递推dp
                        dp[i] = dp[i - coins[j]] + 1;//相当于dp[i]=getmin(dp[i-coins[j]])+1
                    }
                }
            }
        }
        return dp[amount];
    }
};
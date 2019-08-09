/*
c++刷题答案：https://github.com/DongfeiJi/LeetCode
经典dp算法！！！！！！！
暴力枚举：连续子段，复杂度为？
dp算法，dp状态dpi表示以第i个数字结尾的最大子段和，因为相邻，因此dp算法状态之间是向前看找关系，且相邻
算法：
求n个数的最大子段和，转换为求以第1，2，。。。n结尾的最大子段和，最后再求最大，就是结果
dp算法过程：
1，第i个状态是以第i个数字为结尾的最大子段和
2，边界：dp0=nums[0] 
3,递推关系：dpi=max（dp[i-1]+nums[i],nums[i]）,这里要从状态定义开始想，因为重点是考虑第i个数字为结尾，所以num[i]一定有，
然后考率，如果dp[i-1]大于0，就带上，小于0就不带，所以最后简化递推式如上。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> dp(nums.size(),0);
        dp[0] = nums [0];//边界
        int max_res = dp[0];//定义要求所有状态的最大值
        for(int i = 1; i < nums.size(); i++){
            dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
            if(dp[i] >= max_res){
                max_res = dp[i];
            }
        }
        return max_res;
    }
};
/*
C++刷题记录:https://github.com/DongfeiJi/LeetCode
经验：求最短一般用BFS，试验用DFS+回溯
本题需要试探，类似于求集合的问题，用DFS
几个问题？1，回溯如何设计？与集合问题结合2，递归回溯DFS何时返回1？3，普通回溯DFS优化如何剪枝？4，位运算法
暴力回溯法算法：
将每个火柴回溯的放在每个边上，放完n个后，检查四个边是否相同，相同返回1，否则返回0；回溯均无法满足，返回0.
这种方法时间复杂度太高4的n次方
优化：
1，n个火柴总和对4取余要等于0，否则返回假
2，将火柴排序，先尝试大的，减少回溯，相当于改变数据分布，很适合本题，减少回溯次数
3，每次放置，每条边不放置超过总和的1/4

*/
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4){
            return false;
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 4){//n个火柴总和对4取余要等于0，如果sum%4有余数，就是不整除，返回假
            return false;
        }
        std::sort(nums.rbegin(), nums.rend());//逆着排序就是r，这是从大到小排序
        int bucket[4] = {0};//设置4个边
        return generate(0, nums, sum / 4, bucket);
    }
private://回溯深度搜索
    bool generate(int i, std::vector<int> &nums, int target, int bucket[]){//i相当于第i个火柴，target相当于每条边的长度，bucket相当于缓存边的长度
        if(i >= nums.size()){//就是所有火柴都摆放完毕，相当于递归跳出条件
            return bucket[0] == target && bucket[1] == target && bucket[2] == target && bucket[3] == target;
        }
        for(int j = 0; j < 4; j++){//在四个边尝试
            if(bucket[j] + nums[i] > target){
                continue;//如果发现再放就大于target了，就跳出contune，搞下一个边
            }
            bucket[j] += nums[i];
            if(generate(i + 1, nums, target, bucket)){
                return true;
            }
            bucket[j] -= nums[i];//回溯，要把该火柴从该边拿出来，然后继续回溯
        }
        return false;     
    }
};
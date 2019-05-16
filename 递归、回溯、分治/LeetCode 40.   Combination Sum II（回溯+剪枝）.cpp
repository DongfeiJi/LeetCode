/*
首先这道题可以再第90题，子集II，上加一段代码，即在主public函数体里，加代码嵌套for循环遍历求result[i][j]
但是回溯递归复杂度太高2^n，过不掉
因此得出一个结论：一定要利用题中所给全部信息，本题还未用到target这一条件
因此对于回溯算法，我们可以采用target这一条件进行剪枝，即已选择的sum大于target后面无需遍历，直接返回，但是同时不要忘记递归结束条件，同时回溯会影响sum，因此回溯sum要减num[i]
深度搜索中剪枝很重要
set 是用    1,set.insert(?)      2,set.find(?) == set.end()这是集合中没找到（先sort）
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;
        std::sort(candidates.begin(),candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums,
                  std::vector<std::vector<int>>& result, 
                  std::vector<int>& item,
                  std::set<std::vector<int>>& res_set,
                  int sum, int target){//sum就是用于计算当前子集集合的元素和
        if(i >= nums.size() || sum > target){
            return;//递归终止条件+剪枝终止条件
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if(target == sum && res_set.find(item)  == res_set.end()){//如和为target或者set中未出现
            res_set.insert(item);//set insert 一定和result push放在一起
            result.push_back(item);
        }//前向搜索递归处理
        generate(i+1, nums, result, item, res_set, sum, target);
        sum -= nums[i];//回溯这里千万不要忘记回退
        item.pop_back();//这两个是回溯递归处理
        generate(i+1, nums, result, item, res_set, sum, target);
    }
};
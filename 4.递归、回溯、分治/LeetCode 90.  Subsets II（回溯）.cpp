/*
这道题与子集1不同，不能用前面的方法，因为无论是回溯还是位运算，都会产生重复的自己，如122，212
重复原因有：1，不同位置元素组成顺序相同的重复子集 2，组成顺序虽然不同，但是仍然表示同一个子集
解决方法，对原始nums数组进行排序，此时出现的重复情况都是顺序完全相同的子集，再使用set去重
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> item;
        std::set<std::vector<int>> res_set;//用于去重的set
        std::sort(nums.begin(),nums.end());//排序，此时重复子集仅仅有顺序相同的情况，便于set去重
        result.push_back(item);//加入空集，这也是子集
        generate(0, nums, result, item, res_set);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums, 
                  std::vector<std::vector<int>>& result,
                  std::vector<int>& item,
                  std::set<std::vector<int>>& res_set){
        if(i >= nums.size()){
            return;//递归返回
        }
        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){
            res_set.insert(item);
            result.push_back(item);
            //如果set中无法找到item，那么item放入set，并且放入result
        }
        generate(i+1, nums, result, item, res_set);
        item.pop_back();//回溯递归
        generate(i+1, nums, result, item, res_set);
    }
};
/*
vector<vector<int>> 二维数组---------比如[[3],[1],[1,2],[1,2,3]]
思考：生成子集其实就是对各个元素是否选择的问题，那么只用循环可以实现？？如何生成[1],[1,2],[1,2,3]
回溯算法，就是返回试探法。
回溯法解答：
1，对于每个元素都有放入和不放入集合中的选择
对该元素放入，递归的进行后续元素的选择，进行回溯试探；再对于该元素不放入，递归的进行后续元素的回溯试探
回溯法有种枚举的感觉暴力试探，复杂度很高2^n
可以用递归树辅助理解，同时回溯可以采用最短带权路径问题解释
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;//存储最终结果的二维数组
        std::vector<int> item;//回溯产生子集的数组
        result.push_back(item);//注意注意注意！！！空集也是子集
        generate(0, nums, item, result);
        return result;
    }
private:
    void generate(int i, std::vector<int>& nums, 
                  std::vector<int>& item,
                  std::vector<std::vector<int>> &result){
        if(i >= nums.size()){//递归结束条件
            return;
        }
        item.push_back(nums[i]);//第一个元素存入item
        result.push_back(item);//item存入result
        generate(i+1, nums, item, result);//递归目前返回1   1，2   1，2，3
        item.pop_back();//回溯，对最后一个选择进行回溯试探
        generate(i+1, nums, item, result);//在进行递归返回 目前是pop出去了3 再递归pop2
    }
};
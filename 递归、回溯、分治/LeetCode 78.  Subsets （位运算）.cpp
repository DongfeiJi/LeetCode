/*！！！！！！！！！！！！！！上一个提交是回溯法，复习注意！！！！！！！！！！！
位运算法：&  |  ^  ~      <<左移相当于*2          >>右移相当于/2
对于集合[1,2,3],可以用000，001......111，表示一共8个子集，空集情况也包括了
可以画出位运算表，就用[1，2，3]等效为[A,B,C]，其中ABC分为出现和不出现两种情况
A元素100 B元素010 C元素001 
外围for循环是所有子集i（共2的n次方个子集），内部for循环是子集i与各个元素j（共n个元素ABC）与运算，
用来判断元素j是否出现在这个子集i里面，并且push到item表示这个子集
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int all_set = 1 << nums.size();//1<<n,就是2的n次方，因为左移一位就是*2
        for(int i = 0; i < all_set; i++){//遍历全部子集
            std::vector<int> item;//存储子集
            for(int j = 0; j < nums.size(); j++){//遍历nums中全部元素001 010 100
                if(i &(1<<j)){//如果该元素与运算子集为1，那么说明元素在集合里
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }
};
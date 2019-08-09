#include <stdio.h>

#include <vector>
/*
其实就是看这个数列上下折返多少次
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int up = 1;
        int down = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) up = down + 1;
            if(nums[i] < nums[i-1]) down = up + 1;
        }
        return max(up, down);
        
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);
	Solution solve;
	printf("%d\n", solve.wiggleMaxLength(nums));
	return 0;
}

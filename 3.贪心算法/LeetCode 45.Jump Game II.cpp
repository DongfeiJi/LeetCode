/*
本题与跳跃问题1的不同在于，本题数组一定可以跳到最后，问题是如何选择跳跃策略，使跳跃次数最少
思考：在到i位置之前，跳的早了，次数变大，跳的太晚了，那么跳不到结尾，所以如何选择跳跃策略？
答案：在0-i范围内，选择一个可以跳到更远的下标进行跳跃
对与nums数组，定义一个当前可达到最远位置，再定义一个当前范围内，各个位置最远可跳跃的位置
贪心是要让跳跃次数更少，那么我们贪心的就不跳，只有在必须跳的时候才跳
即在i的范围内一定要跳，否则断掉了，画图画图
*/
#include <stdio.h>
#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return 0;//如果只有一个数，那么不用跳跃
	    }
        int current_max_index = nums[0] + 0;//当前可达到的最远位置,就是感受视野数组第0位
        int pre_max_max_index = nums[0] + 0;//遍历当前范围中，可以达到的最远位置
        int jump_min = 1;//，因为排除了不用跳跃情况，这里默认跳了一步，即已经设定了范围
        for (int i = 1; i < nums.size(); i++){//精髓，i用于遍历，能不跳就不跳 
        	if (i > current_max_index){//如果i扫描到已经到达界限，那么要跳跃
        		jump_min++;
	        	current_max_index = pre_max_max_index;//跳跃次数+1，并且更新范围
	        }
        	if (pre_max_max_index < nums[i] + i){
       			pre_max_max_index = nums[i] + i;
        	}//这里相当于循环扫描，当前范围内可以跳到的最远的距离，一定要后面更新
        }
        return jump_min;
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.jump(nums));
	return 0;
}

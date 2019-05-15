#include <stdio.h>

#include <vector>
/*
首先观察数据以及题意要求，理解本题的本质，后一个数比前面小-大-小-大这样
然后举例子，比如实例2中，前6位，1 17 5 10 13 15，可以构成的摇摆数列有三个，那么选哪个显而易见
所以贪心策略就出来了：在递增子序列部分，选最大的数，贪心尽量使递增子序列下一个数成为摇摆序列。递减相反
即贪心的只保留递增或者递减子序列中的首尾元素
证明贪心比较麻烦，可以简单看下有无反例，其次可以手撸对数器证明
设计代码可以采用状态机思考 begin、up、down，如果up与down切换，那么count++（num[i]与num[i—1]比），这里可以画图帮助理解
*/
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
    	if (nums.size() < 2){
	    	return nums.size();//一个也是摆动数列
	    }
	    static const int BEGIN = 0;
	    static const int UP = 1;
	    static const int DOWN = 2;//定义扫描序列的三个状态，注意这里变量一定要不同
	    int STATE = BEGIN;
	    int max_length = 1;
    	for (int i = 1; i < nums.size(); i++){
    		switch(STATE){
	    	case BEGIN://开始状态只有到up/down才count++
	    		if (nums[i-1] < nums[i]){
	    			STATE = UP;
		    		max_length++;
		    	}
		    	else if (nums[i-1] > nums[i]){
	    			STATE = DOWN;
	    			max_length++;
	    		}
	    		break;//如果相等直接break
	    	case UP:
	    		if (nums[i-1] > nums[i]){//up状态只有到down才count++
	    			STATE = DOWN;
		    		max_length++;
		    	}
		    	break;
	    	case DOWN:
	    		if (nums[i-1] < nums[i]){//down状态只有到up才count++
	    			STATE = UP;
		    		max_length++;
		    	}
		    	break;
		    }
	    }
    	return max_length;
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

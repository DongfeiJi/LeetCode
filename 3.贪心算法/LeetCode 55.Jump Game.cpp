/*
贪心：能不跳就不跳×感受视野最远√
分析：无法直观确定从第0个位置，下一步跳到哪里，因此考虑若当前位置可以跳的范围内如何跳下一个位置，采取什么策略？
策略分析：举例子画图，用线段表示题中可以跳多远的含义，同时想想一个概念感受视野，就可得出贪心策略，第i个index位置可以最远跳j个即第i+j的index
因此贪心策略就是要更广的感受视野，因为能跳到更远那么就可以跳到近的地方，所以在第i个位置，应该选跳到跳跃范围内indxe【k】可以跳到的更远的点
定义：
下标：0 1 2 3 4
值(): 2 3 1 1 4 这就是该位置最远可以跳几步
下标：2 4 3 4 8  这就是该位置最远跳到哪里---感受视野
只需处理感受视野数组，对于当前位置jump，扫描到数组尾部并且扫描到的数大于了最大可以跳到的位置停止扫描，选取为可以跳到的跳到更远位置的下标记录为max_index
*/
#include <stdio.h>
#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        std::vector<int> index;//最远可以跳到的位置，相当于感受视野
        for (int i = 0; i < nums.size(); i++){
        	index.push_back(i + nums[i]);//计算index数组
        }
        int jump = 0;
        int max_index = index[0];
        while(jump < index.size() && jump <= max_index){//如果jump没到结尾即可扫描，或者jump大于感受视野，此时jump不++
        	if (max_index < index[jump]){
	        	max_index = index[jump];//贪心策略实现，选取为可以跳到的跳到更远位置的下标记录为max_index
	        }
        	jump++;
        }
        if (jump == index.size()){
        	return true;//最后jump相当于溢出数组下标了，即到达了结尾
        }
        return false;
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
	printf("%d\n", solve.canJump(nums));
	return 0;
}

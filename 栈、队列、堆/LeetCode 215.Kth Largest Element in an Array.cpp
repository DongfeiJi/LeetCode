/*
本题主要用到最大堆，最小堆性质，优先级队列就是最大最小堆，注意c++的模板和stl写法
std::priority_queue<int> big_heap;//默认构造最大堆
std::priority_queue<int,std::vector<int>,std::greater<int>> Q;//构造最小堆
std::priority_queue<int,std::vector<int>,std::less<int>> Q;//构造最大堆
思想一：直接快排，复杂度NLogN
思想二：维护一个K大小的最小堆，1，一开始堆元素小于K，那么直接push；2，当堆大小达到K，若新元素大于堆顶，弹出堆顶，新元素加入堆；3，若新元素小于堆顶，丢弃当前值
分析：由于堆是最小堆，堆顶是堆的最小，新元素都比堆顶小，所以K大小的堆堆顶就是第k大的数。即最小堆里都是最大的，而最小堆堆顶，就是第k个最大的数，时间复杂度，NlogK
最小堆，是一种经过排序的完全二叉树，其中任一非终端节点的数据值均不大于其左子节点和右子节点的值
本题思路：求第k大，那就是最小堆里面的堆顶，即维护的最小堆，是数组中的较大数
*/
#include <stdio.h>

#include <vector>
#include <queue>
class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > Q;//最小堆
        for (int i = 0; i < nums.size(); i++){//遍历数组
        	if (Q.size() < k){//如果堆中元素小于k，那么继续push
	        	Q.push(nums[i]);
	        }
	        else if (Q.top() < nums[i]){
        		Q.pop();//如果新元素比最小堆堆顶大，那么弹出堆顶，压入新元素，这就是保证此堆是前K大
	        	Q.push(nums[i]);
	        }
        }
        return Q.top();
    }
};

int main(){
	std::vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(4);
	Solution solve;
	printf("%d\n", solve.findKthLargest(nums, 2));	
	return 0;
}

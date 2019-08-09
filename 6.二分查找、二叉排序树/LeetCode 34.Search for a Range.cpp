/*
复杂度有要求，二分法，有重复元素，所以在二分代码上修改限制条件转化问题
因为是要搜索某一个target，因此要修改target=nums[mid]的代码，想一下返回值就是target区间的左右端点
因此可以先搜左端点再搜右端点两种情况
对于搜target左端点：当target=nums[mid]，如果mid=0或者target>nums[mid-1]那么mid就是target左端点
否则说明target左端点还在左边，更新搜索区间的end = mid-1继续搜索
对于搜索target右端点：当target=nums[mid]，如果mid=nums.size()-1或者target<nums[mid+1],那么mid就是target右端点，否则说明target右端点还在右边，更新搜索区间begin=mid+1
如果嵌入到class里面if判断代码可读性不高，因此应子函数调用实现
*/
#include <stdio.h>

#include <vector>

int left_bound(std::vector<int>& nums, int target){
	int begin = 0;
	int end = nums.size() - 1;
	while(begin <= end){//注意这个循环条件
		int mid = (begin + end) / 2;
		if (target == nums[mid]){
			if (mid == 0 || nums[mid -1] < target){
				return mid;
			}
			end = mid - 1;
		}
		else if (target < nums[mid]){
			end = mid - 1;
		}
		else if (target > nums[mid]){
			begin = mid + 1;
		}
	}
	return -1;//这里注意是根据题意返回的
}

int right_bound(std::vector<int>& nums, int target){
	int begin = 0;
	int end = nums.size() - 1;
	while(begin <= end){
		int mid = (begin + end) / 2;
		if (target == nums[mid]){
			if (mid == nums.size() - 1 || nums[mid + 1] > target){
				return mid;
			}
			begin = mid + 1;
		}
		else if (target < nums[mid]){
			end = mid - 1;
		}
		else if (target > nums[mid]){
			begin = mid + 1;
		}
	}
	return -1;
}

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result;
        result.push_back(left_bound(nums, target));
        result.push_back(right_bound(nums, target));
        return result;
    }
};

int main(){
	int test[] = {5, 7, 7, 8, 8, 8, 8, 10};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 12; i++){
		std::vector<int> result = solve.searchRange(nums, i);
		printf("%d : [%d, %d]\n",i , result[0], result[1]);
	}
	return 0;
}

/*
二分查找，递归版，非递归必须掌握，切记二分法一定不要忘记两端特例
对于递归与非递归，如果题中含有回溯思想，那么用递归，如果逻辑简单可以用非递归实现
本题：读题理解，看例子，一般对于有序数组，先想二分，返回mid是否可以解题？
思考：当target在nums中出现，就是普通二分，若没出现都有哪些情况？
1，target<nums[mid]&&target>nums[mid-1]
2,target>nums[mid]&&target<nums[mid+1]
3,mid=0 mid=nums.size()-1 这是元素完全大于或者完全小于nums的情况
伪代码：直接在二分上面添加代码即可！！！！！！！！！！！！
当target=nums[mid] index=mid
当target<nums[mid] 如果mid==0或者target>nums[mid-1] index=mid
当target>nums[mid] 如果mid=nums.size()-1或者target<nums[mid+1] index=mid+1
实质就是实时比对target与nums[mid]以及mid+1或者mid-1的情况
*/
#include <stdio.h>

#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int index = -1;
		int begin = 0;
		int end = nums.size() - 1;
		while (index == -1){
			int mid = (begin + end) / 2;
			if (target == nums[mid]){
				index = mid;
			}
			else if (target < nums[mid]){
				if (mid == 0 || target > nums[mid - 1]){
					index = mid;
				}//这里在mid为左端点时候，或者大于mid-1又小于mid时候，index = mid
				end = mid - 1;
			}
			else if (target > nums[mid]){
				if (mid == nums.size() - 1 || target < nums[mid + 1]){
					index = mid + 1;
				}//这里在mid为右端点时候，或者大于mid又小于mid+1时候，index = mid+1
				begin = mid + 1;
			}
		}
		return index;
    }
};

int main(){
	int test[] = {1, 3, 5, 6};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 4; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 8; i++){
		printf("i = %d index = %d\n", i, solve.searchInsert(nums, i));
	}
	return 0;
}

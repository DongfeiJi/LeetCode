/*
本题由于给定是排序数组，那么可以采用二分，但是由于是随机旋转了的数组，并不是严格的排序
要仔细思考：可以任意举例子，应用原始二分查找，看看不适用的原因，然后修改二分查找即可。
分析：旋转数组，begin值>end值，如7 9 12 15 20 1 3 6
如查找12：可以正确查找，因为begin值小于mid，所以是单调递增的。又12大于begin7，所以进入正常二分
如查找3：由于3小于mid，begin大于3，所以左侧区间没有3了，因为3在旋转区间里面了
因此：要修改二分查找，将可能出现在旋转区间考虑进去，原来二分是左右思想，现在就是递增区间旋转区间思想
伪代码：
A,target=nums[mid] 直接返回index
B,targt<nums[mid]
1，begin值小于mid值，说明[begin，mid-1]是递增区间，[mid+1,end]是旋转区间
如果target大于等于begin值，就在递增区间查找
如果target小于begin值，就去旋转区间查找
2，begin值大于mid值，说明[begin，mid-1]是旋转区间，[mid+1,end]是递增区间
直接去旋转区间查找，因为target小于mid值
3，begin值等于mid值，这其实就是最小子问题，如[6,1],查找1，直接去[mid+1，end]找
C,target>nums[mid]
1，begin值小于mid值，说明[begin，mid-1]是递增区间，[mid+1,end]是旋转区间
直接去旋转区间查找，因为target大于mid值，完全大于递增区间
2，begin值大于mid值，说明[begin，mid-1]是旋转区间，[mid+1,end]是递增区间
如果target大于等于begin值，就在旋转区间查找
如果target小于begin值，就去递增区间查找
3，begin值等于mid值，这其实就是最小子问题，如[6,7],查找7，直接去[mid+1，end]找
其实就是以旋转区间和递增区间分治，因为target虽然变了，但是旋转区间没变
*/
#include <stdio.h>

#include <vector>
//本题就是将二分查找由左右两半区间，改为递增区间和旋转区间而已。
//用begin和mid之间关系判断区间，用begin和target判断在哪查找
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
    	int begin = 0;
		int end = nums.size() - 1;
		while(begin <= end){
			int mid = (begin + end) / 2;
			if (target == nums[mid]){//二分查找的框架，先把三个花括号写出来，再补里面的东西
				return mid;
			}
			else if (target < nums[mid]){
				if (nums[begin] < nums[mid]){//[begin，mid-1]递增区间[mid+1，end]旋转区间
					if (target >= nums[begin]){
						end = mid - 1;//target大于begin，在递增区间里搜索
					}
					else{
						begin = mid + 1;//否则去旋转区间搜索
					}
				}
				else if (nums[begin] > nums[mid]){//[begin，mid-1]旋转区间[mid+1，end]递增区间
					end = mid -1;//由于target小于mid，右侧又为递增区间，所以只能去左侧旋转区间搜索
				}
				else if (nums[begin] == nums[mid]){//此时是两个数字，因为/总是向下取整 如21 找1
					begin = mid + 1;//两个数字，因为已经不是等于mid情况，所以只能去右侧搜索
				}
			}
			else if (target > nums[mid]){
				if (nums[begin] < nums[mid]){//[begin，mid-1]递增区间[mid+1，end]旋转区间
					begin = mid + 1;//target大于mid，但是target也大于begin，说明大值在旋转区间里
				}
				else if (nums[begin] > nums[mid]){//[begin，mid-1]旋转区间[mid+1，end]递增区间
					if (target >= nums[begin]){//target大于mid，所以去递增区间查找
						end = mid - 1;
					}
					else{
						begin = mid + 1;//否则去旋转区间搜索
					}
				}
				else if (nums[begin] == nums[mid]){//此时是两个数字 如23 找3
					begin = mid + 1;//两个数字，因为已经不是等于mid情况，所以只能去右侧搜索
				}
			}
		}
		return -1;
    }
};

int main(){
	int test[] = {9, 12, 15, 20, 1, 3, 6, 7};
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++){
		printf("%d : %d\n", i, solve.search(nums, i));
	}
	return 0;
}

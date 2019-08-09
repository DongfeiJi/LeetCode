/*
统计一个数字在排序数组中出现的次数。

既然是已经排序好的数组，那么第一个想到的就是二分查找法。
做法就是使用二分法找到数字在数组中出现的第一个位置，再利用二分法找到数字在数组中出现的第二个位置。
时间复杂度为O(logn + logn)，最终的时间复杂度为O(logn)。
举个例子，找到数字k在数组data中出现的次数。
数组data中，数字k出现的第一个位置：
我们对数组data进行二分，如果数组中间的数字小于k，说明k应该出现在中间位置的右边；
如果数组中间的数字大于k，说明k应该出现在中间位置的左边；如果数组中间的数字等于k，
并且中间位置的前一个数字不等于k，说明这个中间数字就是数字k出现的第一个位置。
同理，数字k出现的最后一个位置，也是这样找的。但是判断少有不同。我们使用两个函数分别获得他们。
个人理解：就是二分法，并且求出第一次出现的位置，以及最后一次出现的位置，在data[mid]==k，下面进行判断即可
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int length = data.size();
        if(length == 0){
            return 0;//特殊情况处理
        }
        int first = GetFirstK(data, k, 0, length - 1);
        int last = GetLastK(data, k , 0, length - 1);
        if(first != -1 && last != -1){
            return last - first + 1;//求左右下标，都存在，返回差值+1即可
        }
        return 0;//这里注意，不存在用return -1表示，return 0表示出现0次，递归跳出用return -1
    }
private:
    int GetFirstK(vector<int> data, int k, int begin, int end){//递归迭代法求第一次出现的下标
        if(begin > end){
            return -1;//递归跳出条件
        }
        int mid = begin + (end - begin)/2;
        if(data[mid] == k){//mid就是k的时候，继续判断是不是第一个
            if((mid > 0 && data[mid - 1] != k) || mid == 0){
                //此时有两种情况，一个就是正常的第一次出现，一个是下标为0
                return mid;
            }
            else{
                end = mid - 1;//这里注意，这是因为可能此时的mid是出现好多次数值的中间，
                //又由于找的是第一个出现的k，所以更新end
            }
        }
        else if(data[mid] > k){
            end = mid - 1;
        }
        else{
            begin = mid + 1;
        }
        return GetFirstK(data, k, begin, end);
    }
    int GetLastK(vector<int> data, int k, int begin, int end){//循环法求最后出现的下标
        int length = data.size();
        int mid = begin + (end - begin)/2;
        while(begin <= end){
            if(data[mid] == k){//找到mid就是k时候，继续判断
                if((mid < length - 1 && data[mid + 1] != k) || mid == length - 1){
                    return mid;//同上，此时判断是最后一个出现的才会return，或者是就是结尾的下标也可以直接返回
                }
                else{
                    begin = mid + 1;//此时找到的mid就是出现次数的中间
                    //因为要找的是最后一个出现时的下标，所有找右边，更新begin
                }
            }
            else if(data[mid] > k){
                end = mid - 1;
            }
            else{
                begin = mid + 1;
            }
            mid = begin + (end - begin)/2;//这里不要忘了更新begin和end后，用来循环也要更新min
            //这就是递归与循环的区别，递归自动实现了mid求取，循环一定要自己写进去
        }
        return -1;//什么都没返回，就返回-1，此时data中不存在k
    }
};

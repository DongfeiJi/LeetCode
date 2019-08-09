/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，
该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();                            //数组长度
        if(size == 0){
            return 0;
        }
        int left = 0;                                            //左指针
        int right = size - 1;                                    //右指针
        int mid = 0;                                            //中间指针
        while(rotateArray[left] >= rotateArray[right]){            //确保旋转
            if(right - left == 1){                                //左右指针相邻
                mid = right;
                break;
            }
            mid = left + (right - left) / 2;                    //计算中间指针位置
            //特殊情况：如果无法确定中间元素是属于前面还是后面的递增子数组，只能顺序查找
            if(rotateArray[left] == rotateArray[right] && rotateArray[mid] == rotateArray[left]){
                return MinInOrder(rotateArray, left, right);
            }
            //中间元素位于前面的递增子数组，此时最小元素位于中间元素的后面
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }
            //中间元素位于后面的递增子数组，此时最小元素位于中间元素的前面
            else{
                right = mid;
            }
        }
        return rotateArray[mid];
    }
private:
    //顺序寻找最小值
    int MinInOrder(vector<int> &num, int left, int right){
        int result = num[left];
        for(int i = left + 1; i < right; i++){
            if(num[i] < result){
                result = num[i];
            }
        }
        return result;
    }
};
思路：
二分法，用while保证旋转情况下，这是因为也考虑数组没有旋转的情况，就没必要二分了，此时就是mid=0，直接返回mid即可
旋转时，一直二分，一直到左右指针相邻，且代码里面right更小，给mid赋值为right，返回mid
特殊：考虑到10111这种情况，注释里面包含此情况解决代码，只能用简单查找求最小了
*/
class Solution {
public://此代码没有考虑到10111这种情况，注释里面包含此情况解决代码，只能用简单查找求最小了
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if(!size){
            return 0;//判断特殊情况
        }
        int left = 0;
        int right = size - 1;
        int mid = 0;//二分法
        while(rotateArray[left] >= rotateArray[right]){//确保旋转
            if(right - left == 1){//这是跳出返回条件，左右指针相邻
                mid = right;//因为返回mid，这里要取小的，所以mid取的就是else的right
                break;
            }
            mid = left + (right - left) / 2;
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }
            else{
                right = mid;//二分法，这里返回的是最小值，mid，所以right更容易最小
            }
        }
        return rotateArray[mid];//这也考虑到了没有旋转的条件
    }
};

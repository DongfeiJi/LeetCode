/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

还可以把当前序列当成是一个下标和下标对应值是相同的数组（时间复杂度为O(n),空间复杂度为O(1)）；
遍历数组，判断当前位的值和下标是否相等：
若相等，则遍历下一位；
若不等，则将当前位置i上的元素和a[i]位置上的元素比较：若它们相等，则找到了第一个相同的元素；
若不等，则将它们两交换。换完之后a[i]位置上的值和它的下标是对应的，但i位置上的元素和下标并不一定对应；
重复2的操作，直到当前位置i的值也为i，将i向后移一位，再重复2。
举例说明：{2,3,1,0,2,5,3}
0(索引值)和2(索引值位置的元素)不相等，并且2(索引值位置的元素)和1(以该索引值位置的元素2为索引值的位置的元素)不相等，则交换位置，数组变为：{1,3,2,0,2,5,3}；
0(索引值)和1(索引值位置的元素)仍然不相等，并且1(索引值位置的元素)和3(以该索引值位置的元素1为索引值的位置的元素)不相等，则交换位置，数组变为：{3,1,2,0,2,5,3}；
0(索引值)和3(索引值位置的元素)仍然不相等，并且3(索引值位置的元素)和0(以该索引值位置的元素3为索引值的位置的元素)不相等，则交换位置，数组变为：{0,1,2,3,2,5,3}；
0(索引值)和0(索引值位置的元素)相等，遍历下一个元素；
1(索引值)和1(索引值位置的元素)相等，遍历下一个元素；
2(索引值)和2(索引值位置的元素)相等，遍历下一个元素；
3(索引值)和3(索引值位置的元素)相等，遍历下一个元素；
4(索引值)和2(索引值位置的元素)不相等，但是2(索引值位置的元素)和2(以该索引值位置的元素2为索引值的位置的元素)相等，则找到了第一个重复的元素。
总结：
核心就是判断下标i和a[i]是否相等，不等就交换，使数组变成值和下标对应的数组，后面一旦遍历某位置值与其值对应位置的值相等，那就是重复了
1，判断输入为空，length小于等于0，非法输入
2，判断数组里面的值不满足题意的，非法输入
3，for遍历，while当前位置值不等于下标，那么a，当前值与以当前值为下标的值相等，找到重复，返回真。b，交换
4，都不是，返回假
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0){
            return false;// 非法输入
        }
        for(int i = 0; i < length; i++){
            if(numbers[i] < 0 || numbers[i] > length - 1){
                return false;// 非法输入
            }
        }
        // 遍历查找第一个重复的数
        for(int i = 0; i < length; i++){
            //其实while多用于维护达成该条件，就是保证numbers[i] == i
            while(numbers[i] != i){//当前值不等的时候才会判断，相等直接向下走for循环了
                if(numbers[i] == numbers[numbers[i]]){//这就是重复值了
                    *duplication = numbers[i];
                    return true;
                }
                else{
                    swap(numbers[i], numbers[numbers[i]]);//不是重复值，就交换，直到numbers[i] == i
                }
            }
        }
        return false;//没有返回true，返回false
    }
};
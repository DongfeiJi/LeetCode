/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。

主要思想：最大堆 | 最小堆
我们将数据分为两部分，位于左边最大堆的数据比右边最小堆的数据要小，
左、右两边内部的数据没有排序，也可以根据左边最大的数及右边最小的数得到中位数。
接下来考虑用最大堆和最小堆实现的一些细节。
首先要保证数据平均分配到两个堆中，因此两个堆中数据的数目之差不能超过1.
为了实现平均分配，可以在数据的总数目是偶数时把新数据插入到最小堆中，否则插入到最大堆中。
此外，还要保证最大堆中所有数据小于最小堆中数据。
所以，新传入的数据需要先和最大堆的最大值或者最小堆中的最小值进行比较。
以总数目为偶数为例，按照我们制定的规则，新的数据会被插入到最小堆中，
但是在这之前，我们需要判断这个数据和最大堆中的最大值谁更大，
如果最大堆中的数据比较大，那么我们就需要把当前数据插入最大堆，
然后弹出新的最大值，再插入到最小堆中。
由于最终插入到最小堆的数字是原最大堆中最大的数字，这样就保证了最小堆中所有数字都大于最大堆的数字。
下面代码中，我们基于stl中的函数push_heap、pop_heap以及vector实现堆。
比较函数less和greater分别用来实现最大堆和最小堆。

算法核心:就是维护一个最大堆和最小堆，最大堆最大的比最小堆最小的小即可，求中位数即保证两个堆大小差距不超过1，然后判断奇偶
对于插入函数：设想：max在左，min在右
1，if判断已有数据是奇数还是偶数，用&1实现，
1.1，是偶数就把当前值放入最小堆
在放入最小堆前，先if判断，最大堆size大于0+当前值小于最大堆最大值，此时
最大堆push进去num
调整最大堆push_heap(max.begin(), max.end(), less<int>());
再次取出最大值赋值给num
最大堆pop一下pop_heap(max.begin(), max.end(), less<int>());max.pop_back();
之后：
在最小堆push num
调整最小堆push_heap(min.begin(), min.end(), greater<int>());
1.2，否则，是奇数就把当前值放入最大堆
再放入最大堆之前，先if判断，最小堆size大于0+当前值大于最小堆最小值，此时
最小堆push进去num
调整最小堆 push_heap(min.begin(), min.end(), greater<int>());
取出最小堆最小的数，赋值给num
最小堆pop， pop_heap(min.begin(), min.end(), greater<int>());min.pop_back();
之后：
最大堆push num
调整最大堆push_heap(max.begin(), max.end(), less<int>());

对于求位数函数：
1，统计数据总大小
2，非法值，size为0，返回0
3，如果为偶数，返回平均数
4，否则，返回最小堆最小值
*/
class Solution {
public:
    void Insert(int num){
        if(((max.size() + min.size()) & 1) == 0){// 如果已有数据为偶数，则放入最小堆
            if(max.size() > 0 && num < max[0]){//判断当前值是不是比最大堆最大值还小，因为要保证最大堆全部小于最小堆
                max.push_back(num);//先push到最大堆
                push_heap(max.begin(), max.end(), less<int>());//调整
                num = max[0];//取出最大值
                pop_heap(max.begin(), max.end(), less<int>());//弹出最大值
                max.pop_back();
            }//经过这个num始终是比最大堆最大值还大的值，此时可以安心放入最小堆
            min.push_back(num);//放入最小堆
            push_heap(min.begin(), min.end(), greater<int>());//调整
        }
        else{// 已有数据为奇数，则放入最大堆
            if(min.size() > 0 && num > min[0]){//如果当前值比最小堆的最小值大
                min.push_back(num);//放入最小堆
                push_heap(min.begin(), min.end(), greater<int>());//调整
                num = min[0];//取出最小堆新的最小值
                pop_heap(min.begin(), min.end(), greater<int>());//弹出最小值
                min.pop_back();
            }
            max.push_back(num);//放入最大堆
            push_heap(max.begin(), max.end(), less<int>());//调整
        }
    }

    double GetMedian(){ 
        int size = max.size() + min.size();
        if(size <= 0){//非法值小于等于0
            return -1;
        }
        if((size & 1) == 0){//如果数据是偶数，这里注意 & 的优先级 在 == 后面
            return (max[0] + min[0]) / 2.0;
        }
        else{//数据是奇数
            return min[0];
        }
    }
private:
    // 使用vector建立最大堆和最小堆,min是最小堆数组,max是最大堆数组
    vector<int> min;
    vector<int> max;
};
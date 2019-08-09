/*
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

方法1：最简单的方法就是先排序，然后在遍历输出最小的K个数，方法简单粗暴。
算法：
1，定义result
2，非法输入判定，input为空+k大于input的大小
3，排序
4，遍历k和，取出push到result
5，return result
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
        if(input.empty() || k > input.size()){
            return result;
        }
        sort(input.begin(), input.end());
        for(int i = 0; i < k; i++){
            result.push_back(input[i]);
        }
        return result;
    }
};
*/
////////////////////////////////////////////////////////////////////////////
/*
补充知识：
对于二叉树模拟大根堆：（大根堆就是每个子树的最大值，都是头结点）
从0开始存储，那么第i个结点的左孩子就是2*i+1，右孩子就是2*i+2，已知子节点，求父节点用（i-1）/2

优化方法1：大根堆（数组实现）
这种思想主要就是维护一个大小为k的数据容器；
首先创建一个大小为k的数据容器来存储最小的k个数字，接下来我们每次从输入的n个整数中读取一个数，
比较待插入的整数和容器中的最大值，如果比已有的最大值小，就插入容器替换这个最大值；
否则就不进行操作，因为这个数比容器的最大值还要大。
我们需要对容器做的操作有：
在k个整数中找到最大数。
在容器中删除最大值。
插入一个新的数字。
如果用一个二叉树来实现这个数据容器，那么我们可以在O(logk) O(logk)O(logk)时间内实现这三个步骤。
因此对于n个输入数字而言，总的时间效率就是O(nlogk) O(nlogk)O(nlogk)，这种思路特别适合处理海量数据。
也可以直接使用STL实现中的堆排序，STL中并没有实现堆这种数据结构，但是algorithm中实现了堆排序算法。
主要就是四个函数，make_heap()，pop_heap()，push_heap()，sort_heap()。

算法：
1，定义result空数组
2，非法输入判断 input空+k大于input的size+k小于等于0
3，for循环先push k个input元素到result，这里result就是我们要维护的大根堆
4，初始化堆，for循环从最大的非叶子节点开始（len/2）,到根节点（0）终止，调用调整子函数调整是至下而上的
5，从input下标k开始，for循环遍历到最后
5.1，if判断如果新的值小于大根堆最大值即result[0]，就替换，然后调整
6，返回result
子函数：从某一点开始调整大根堆，返回void，输入时大根堆数组，起始父亲节点，长度length
1，保存父亲值为temp，定义父亲节点i，孩子节点j；
2，for循环全部左孩子，从上而下的思想，
2.1，if判断，左孩子j在length范围，并且左孩子小于右孩子，孩子下标转换到右孩子++j
2.2，if判断，父亲节点temp大于最大的孩子，说明调整结束，break
2.3，否则，父亲节点值赋值为孩子节点input[i] = input[j]，父亲节点下标换到孩子节点下标i=j
2.4，最后由于只是将父亲节点换了，所以最后一步要将调整到的节点位置赋值为保存好的父亲节点，这里其实也就是起始节点
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || input.size() < k || k <= 0) return res;
        for(int i = 0; i < k; ++i){
            res.push_back(input[i]);
        }
        //for循环从最大的非叶子节点开始（k/2）,到根节点（0）终止，调用调整子函数调整是至下而上的
        for(int i = k/2-1; i >= 0; i--){ //初始化为大根堆
            adjustHeap(res, i, k);//这里不用adjustHeap(res, 0, k);因为adjustHeap只是调整一个节点变化的情况
        }
        //adjustHeap(res, 0, k);//初始化为大根堆
        for(int i = k; i < input.size(); i++){
            if(input[i] < res[0]){   // 存在更小的数字时
                res[0] = input[i];
                adjustHeap(res, 0, k);   // 重新调整堆
            }
        }
        return res;
    }
    void adjustHeap(vector<int> &input, int i, int length){//调整大根堆，从i开始
        int temp = input[i], j;//i是父节点，j是孩子节点，保存父节点
        for(j = 2*i + 1; j <=length; j = j*2 + 1){//循环所有子树，这里是遍历所有左孩子实现的，因为下面有选取左右孩子的操作
            // 沿关键字较大的孩子结点向下筛选
            if(j <= length && input[j] < input[j+1]){//这是取左右孩子最大的孩子
                ++j;   // 较大孩子的下标
            }
            if(temp >= input[j])//如果父节点较大，就break
                break;
            input[i] = input[j];//将父亲节点赋值为父亲左右孩子中的最大值
            i = j;//父亲跑到孩子节点，用来循环迭代
        }
        input[i] = temp;//将父节点还原赋值给调整停止的地方，此处就是大根堆调整好的地方
    }
    //堆排序
    void Heapsort(vector<int> &input, int length){
        for(int i = length/2 - 1; i >= 0; i--){
            adjustHeap(input, i, length);    //初始化堆
        }
        for(int i = length-1; i >= 0; i--){
            swap(input[i], input[0]);//剪枝，最大值换到最小
            adjustHeap(input, 0, i);// 重新调整堆
        }
    }
};

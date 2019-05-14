/*
思想一：数组，每次添加或者查找中位数，排序，
复杂度：1，添加元素时候排序，插排，加数oN，找中位数o1
2，找中位数时候排序，加数01，找中位数归并nlogn（若用最小堆找前k大数那个算法，nlogn/2）
总体就是oN2
思想二：用最大堆最小堆实现，分别存储一般数据，维持最大堆堆顶比最小堆堆顶小
分析最小堆里的数据均比最大堆里面数据大，且堆顶正好可以推出中间值。
总数据流为偶数，则两个堆一样大，中位数就是取平均两个堆顶。
总数据流为奇数，则两个堆谁大一个，中位数就是这个堆堆顶。
维护思路：保证两个堆的size最多差一，保证最大堆堆顶小于最小堆堆顶
情况1，两个堆size一样，新元素<最大堆堆顶，压入最大堆，否则压入最小堆
情况2，最大堆比最小堆多一个元素
a，新元素>最大堆堆顶，直接压入最小堆维持平衡
b，新元素<最大堆堆顶，此时复杂，将最大堆堆顶push到最小堆，再pop最大堆，最后压入新元素到最大堆
情况3，最大堆比最小堆少一个元素
a，新元素<最小堆堆顶，直接压入最大堆
b，新元素>最小堆堆顶，最小堆堆顶push到最大堆，然后pop最小堆，最后压入新元素到最小堆
返回值就是size相同，堆顶加和/2，否则谁size大，返回谁堆顶
复杂度：找中位数o1，加元素logN
*/
#include <stdio.h>

#include <queue>

class MedianFinder {
public:
    MedianFinder() {
    }
    void addNum(int num) {
    	if (big_queue.empty()){
	    	big_queue.push(num);
	    	return;//先往最大堆丢一个
	    }
        if (big_queue.size() == small_queue.size()){//情况1两个堆大小相同
        	if (num < big_queue.top()){
	        	big_queue.push(num);//如果新元素小于最大堆堆顶，放入最大堆
	        }
	        else{
        		small_queue.push(num);//否则放入最小堆
        	}
        }
        else if(big_queue.size() > small_queue.size()){//情况2最大堆size大
        	if (num > big_queue.top()){
	        	small_queue.push(num);//如果新元素大于最大堆，那么push到最小堆
	        }
	        else{
        		small_queue.push(big_queue.top());
        		big_queue.pop();
        		big_queue.push(num);
				//否则，将最大对堆顶push到最小堆，pop下后，再往最大堆里push新元素
        	}
        }
        else if(big_queue.size() < small_queue.size()){//情况3，最小堆size大
        	if (num < small_queue.top()){
	        	big_queue.push(num);//如果新元素小于最小堆堆顶，新元素push到最大堆
	        }
	        else{
        		big_queue.push(small_queue.top());
        		small_queue.pop();
        		small_queue.push(num);
				//否则，最小堆堆顶push到最大堆，pop后，新元素加入最小堆
        	}
        }
    }
    double findMedian(){
    	if (big_queue.size() == small_queue.size()){
        	return (big_queue.top() + small_queue.top()) / 2;
        }
        else if (big_queue.size() > small_queue.size()){
        	return big_queue.top();
        }
        return small_queue.top();
    }
private:
	std::priority_queue<double> big_queue;
	std::priority_queue<double, std::vector<double>,
					std::greater<double> > small_queue;
};

int main(){
	MedianFinder M;
	int test[] = {6, 10, 1, 7, 99, 4, 33};
	for (int i = 0; i < 7; i++){
		M.addNum(test[i]);
		printf("%lf\n", M.findMedian());
	}
	return 0;
}

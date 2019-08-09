/*
思考：首先将样例画图，找出规律理解题意，其次举例子，1个气球最少用1个箭，2个重叠气球最少用一个箭，3个重叠气球最少用一个箭
因此，尽量使气球重叠部分最多一些，那么如何算法化呢？当然是排序，然后遍历维护射击区间。
1，排序，按照左端点。
2，遍历气球数组，维护一个设计区间，初始化就是第一个气球的区间，同时贪心尽可能多的击穿更多气球，然后更新设计区间。
3，直到没有新的气球可以被击穿，那么增加箭，同时维护一个新的射击区间。
*/
#include <stdio.h>

#include <algorithm>
#include <vector>

bool cmp(const std::vector<int> &a, const std::vector<int > &b) {
    return a[0] < b[0];//用于无需考虑左端点相同时候的排序,（sort排序结构体也会用到，这里return <代表升序）
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0){
	    	return 0;//传入数据为空直接返回
	    }
    	std::sort(points.begin(), points.end(), cmp);//按照左端点排序
    	int shoot_num = 1;
    	int shoot_begin = points[0][0];
    	int shoot_end = points[0][1];//初始化弓箭数目，第一个维护射击区间，就是第一个气球的左右端点
    	for (int i = 1; i < points.size(); i++){//此处就是遍历气球，更新射击空间，看最多可以射爆多少个气球
	    	if (points[i][0] <= shoot_end){
	    		shoot_begin = points[i][0]; //新气球左端点小于设计区间右端点，那么说明可以击穿，更新射击区间左端点
    			if (points[i][1] < shoot_end){
			    	shoot_end = points[i][1];//新球右端点小于设计区间左端点，那么说明可以击穿，更新设计区间右端点
                    //设计区间维护其实就是在不断缩小射击区间
			    }
	    	}
	    	else{//不满足情况时，多用一个弓箭
	    		shoot_num++;
	    		shoot_begin = points[i][0];
	    		shoot_end = points[i][1];//初始化新的弓箭设计区域
	    	}
	    }
	    return shoot_num;    
    }
};


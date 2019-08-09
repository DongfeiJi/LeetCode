/*
贪心，尽可能满足当前目标损失最小的策略。
思想：其实可以想象，如果你来分，如何去分？怎么算法化？肯定是先从需求小的孩子开始满足，并且用最小的糖果，这样可以满足更多的孩子。
因此：先排序，然后定义两个数组下标用来记录，如果孩子需求小于糖果，孩子++，糖果要一直++。
*/
#include <stdio.h>

#include <vector>
#include <algorithm>
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    	std::sort(g.begin(), g.end());
    	std::sort(s.begin(), s.end());
    	int child = 0;
    	int cookie = 0;
    	while(child < g.size() && cookie < s.size()){
	    	if (g[child] <= s[cookie]){
	    		child++;
			}
			cookie++;
	    }
    	return child;
    }
};

int main(){
	Solution solve;
	std::vector<int> g;
	std::vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);	
	printf("%d\n", solve.findContentChildren(g, s));
	return 0;
}

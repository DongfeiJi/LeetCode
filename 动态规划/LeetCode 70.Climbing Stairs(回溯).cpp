#include <stdio.h>

class Solution {
public:
    int climbStairs(int n) {
    	if (n == 1 || n == 2){
			return n;
		}
	    return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main(){
	Solution solve;
	printf("%d\n", solve.climbStairs(3));	
	return 0;
}

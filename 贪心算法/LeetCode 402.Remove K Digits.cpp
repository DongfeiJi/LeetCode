/*
一开始一定要多举例子理解题意，对于实例1，去掉三个数，1432，1322，1221，1219.。。。。
为什么采用字符串？因为数字可能特别大，因此返回值也应该是字符串表示数
分析：举例1432219，k=1，全部枚举出来，我们可以知道应该尽可能的让新数字，优先最高位最小，其次次高位。。。。。
因此，从高位开始遍历，如果对应数字大于下一位，则去掉
暴力法太复杂，因此采用栈实现，对于num，一个一个push，那么若栈top大于push的数，则pop后再push，同时k--。（栈为空或k==0不能继续pop了）
还要考虑如下：
1，全部扫描后，k》0
2，遇到0
3，如何将最后结果存储为字符串返回
*/
#include <stdio.h>

#include <string>
#include <vector>

class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
    	std::vector<int> S;//用vector当作栈，因为他也可以遍历，这里不用初始化，他有构造函数
    	std::string result = "";//结果
    	for (int i = 0; i < num.length(); i++){//从最高为循环扫描字符串
	    	int number = num[i] - '0';//字符转数字
	    	while(S.size() != 0 && S[S.size()-1] > number && k > 0){
				//pop就是删除的条件，栈顶大于新数字删，栈不为空可以删。k大于0可以删
	    		S.pop_back();//vector也有栈类似功能pop_back
	    		k--;
	    	}
	    	if (number != 0 || S.size() != 0){//push是保留数字的情况，1，数字不为0 2，栈不为空（就是无前导0）
	    		S.push_back(number);
	    	}
	    }
	    while(S.size() != 0 && k > 0){//栈不空 k大于0 仍然可以删
    		S.pop_back();
    		k--;//比如123456 k=2 的情况
    	}
	    for (int i = 0; i < S.size(); i++){//数字转字符
    		result.append(1, '0' + S[i]);//前面的1是指添加一个的意思
    	}
    	if (result == ""){//全都删了输出的是0.比如12 k=2
	    	result = "0";
	    }
    	return result;
    }
};

int main(){
	Solution solve;
	std::string result = solve.removeKdigits("1432219", 3);
	printf("%s\n", result.c_str());
	std::string result2 = solve.removeKdigits("100200", 1);
	printf("%s\n", result2.c_str());
	return 0;
}

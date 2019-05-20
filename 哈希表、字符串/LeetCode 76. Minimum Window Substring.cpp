/*
枚举法：对于s，枚举所有的子字符串，包含t即可，优化到oN
因为无需考虑顺序，所以用哈希映射
算法思路：
1，设置两个字符哈希数组，map_s map_t，前者用于代表当前维护的窗口区间各个字符数量，后者代表字符串t的各个字符数量
2，设置begin与i滑动窗口
3，i向后扫描s中字符，直到找到全部t，继续扫描时，循环检查begin是不是可以往前移动（因为要求最短）
如果begin指向的字符在map_t中没出现，向前移动begin
如果begin指向的字符在map_t中出现了，同时该窗口区间该字符数量比t多，向前移动，并且更新map_s--
否则不能移动begin，跳出检查
4，指针i每向前扫描一个字符，就检查一下，更新最终结果
思想：本题中是要维护一个包含t中全部字符的最短的滑动窗口，因此就是尽可能的将begin往前移动，使其更短。（贪心）
*/
#include <stdio.h>

#include <string>
#include <vector>

class Solution {
private:
	bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){//用来判断s中是否全部包括了t中的全部字母
    	for (int i = 0; i < vec_t.size(); i++){
    		if (map_s[vec_t[i]] < map_t[vec_t[i]]){
		    	return false;
		    }
	    }
	    return true;
    }
public:
    std::string minWindow(std::string s, std::string t) {
        const int MAX_ARRAY_LEN = 128;//char 0-127 利用数组下标记录字符个数
        int map_t[MAX_ARRAY_LEN] = {0};//记录t字符串各字符个数
        int map_s[MAX_ARRAY_LEN] = {0};//记录s字符串各字符个数
        std::vector<int> vec_t;//记录t中都有哪些字符
        for (int i = 0; i < t.length(); i++){
        	map_t[t[i]]++;//建立映射，记录t中字符个数
        }
        for (int i = 0; i < MAX_ARRAY_LEN; i++){
        	if (map_t[i] > 0){
	        	vec_t.push_back(i); 
				//用数组再次记录t中字符的int key，用于判断滑动窗口is_window_ok是否符合题意
	        }
        }
        
        int window_begin = 0;
        std::string result;
        for (int i = 0; i < s.length(); i++){//滑动窗口尾指针
        	map_s[s[i]]++;//每扫描一个建立一个滑动窗口s的映射
        	while(window_begin < i){//循环判断条件，贪心想尽量将begin往前移动
        		char begin_ch = s[window_begin];//记录begin的字符
	        	if (map_t[begin_ch] == 0){
	        		window_begin++;//如果begin指针指向的字符没有在t中出现
	        	}
	        	else if	(map_s[begin_ch] > map_t[begin_ch]){//滑动窗口begin指向字符，数量比t中多
	        		map_s[begin_ch]--;
	        		window_begin++;//begin继续向前移动并且哈希映射中，map_s[begin_ch]--用于begin继续前移判断
	        	}
	        	else{
	        		break;
	        	}
	        }
	        if (is_window_ok(map_s, map_t, vec_t)){//如果滑动窗口满足条件，滑动窗口包含全部t字符
        		int new_window_len = i - window_begin + 1; //这里是求更新后的滑动窗口长度，用于提取字符存入result
        		if (result == "" || result.length() > new_window_len){//不要忘了初始情况！！！！
		        	result = s.substr(window_begin, new_window_len);//注意str.substr（begin，len）用法
				}
        	}
        }
        return result;
    }
};

int main(){
	
	Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
	
	return 0;	
}

/*注意子串不是子序列，子串要连在一起
对于pwwkew，枚举全部情况
p pw pww pwwk pwwke pwwkew 这是以p开头的全部情况，还有以其他开头的情况，两个指针即可实现，oN2复杂
因此需要优化，考虑哪些枚举无意义？比如p开头，pww已经重复，后面的枚举均无效，还有对于后面的e和w，前面枚举过，因此无效。所以采取算法，优化到oN。不考虑oNlogN，因为这一般是分治和树的复杂度。
即两层循环改为一层扫描，因为要维护一个最长字串，所以可以采用滑动窗口法。
算法思路：
1，设置一个记录字符数量的字符哈希，char_map
2，设置一个记录当前满足条件的最长子串变量word
3，设置两个指针，记作指针begin和指针i，相当于滑动窗口
4，设置最长满足条件的字串长度result
5，i循环扫描字符传中的字符，使用char_map记录字符数量
如果word没有该字符，对word尾部添加字符并且检查result是否需要更新
若出现了，begin向前移动，更新char_map，直到s[i]数量为1，更新word，将word赋值为begin与i之间的字串
复杂度oN
思想就在于：先定义好结果变量result，并且根据实际情况更新，基于begin与i维护一个窗口，并且向前滑动，抛弃掉那些无需遍历的子串，然后实时更新result，相当于双指针实现两层循环去掉无需遍历的情况。
*/
#include <stdio.h>

#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
    	int begin = 0;//begin与i构成滑动窗口
    	int result = 0;
    	std::string word = "";
    	int char_map[128] = {0};//字符哈希
    	for (int i = 0; i < s.length(); i++){
    		char_map[s[i]]++;//建立字符哈希映射，字符---字符数量
    		if (char_map[s[i]] == 1){//字符数量为1说明word没有出现该字符
			//这里重点，实现了map的find功能，即不断遍历创建哈希映射++，if判断如果为1，就是没出现过
		    	word += s[i];//word扩展
		    	if (result < word.length()){
	    			result = word.length();//结果始终更新为最大数量
	    		}
		    }
		    else{//此时char_map[s[i]] 大于1
    			while(begin < i && char_map[s[i]] > 1){//要维护用while，每个字符数量为1就是满足条件，跳出循环
    				char_map[s[begin]]--;
		    		begin++;
		    	}
		    	word = "";//重置word临时变量
		    	for (int j = begin; j <= i; j++){
	    			word += s[j];//将新的滑动窗口存入word
	    		}
    		}//此时由于滑动窗口变小了无需更新result，因此result一定存在于i遇到的是前面哈希表没有的字符
	    }
    	return result;
    }
};

int main(){
	std::string s = "abcbadab";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));	
	return 0;
}

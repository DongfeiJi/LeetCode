/*
记录一波哈希表，哈希表其实就是散列映射关系，重要在其映射思想
哈希函数：其实就是映射函数，整数就是对哈希表长度取余，字符就是先求和字符串转化整数，再取余
字符哈希：定义char_map数组长度128，对于一个字符，直接使char_map[str[i]]++,再从0遍历char_map下标
哈希排序整数：给定一定范围数据列表，定义hash_map大小为数据值上限，遍历数据，使hash_map[random[i]]++，再重新从0遍历hash_map下标。
为了解决映射到同一个key，提出拉链法，用ListNode数据结构，哈希函数整数映射，插入用头插法，还有查找函数
上面是哈希表实现的算unorder_map，还有stl的map，用红黑树实现，是order_map
	std::map<std::string, int> hash_map;	
	std::string str1 = "abc";
	hash_map[str1] = 1;	
	if (hash_map.find(str1) != hash_map.end())
		printf("%s is in hash_map, value is %d\n",str1.c_str(), hash_map[str1]);	
	std::map<std::string, int> ::iterator it;
	for (it = hash_map.begin(); it != hash_map.end(); it++)
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);
对于本题：
分析例子：abccccdd，里面1个a，1个b，4个c，2个d
对于回文，全偶数或者全偶数加一个中心字符
算法：1，偶数全部使用 2，奇数，丢掉一个字符，剩下的偶数全部使用 3，剩下的单个字符选一个作为中心字符
1，利用字符哈希，统计s中字符数量
2，设置最长回文串偶数字符长度为max_length = 0
3, 设置是否有中心点标记 flag = 0
4，遍历每一个字符，字符数记作count，若count为偶数，max_lenth +=count；若为奇数，max_length +=count-1,falg=1
5,最终结果为max_length+flag
*/
#include <stdio.h>

#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
    	int char_map[128] = {0};//字符哈希范围0-127
    	int max_length = 0;
    	int flag = 0;
    	for (int i = 0; i < s.length(); i++){
	    	char_map[s[i]]++;//key是字符ASCII码，value就是出现次数++
	    }
	    for (int i = 0; i < 128; i++){//遍历哈希表
    		if (char_map[i] % 2 == 0){//对应字符出现频次为偶数
		    	max_length += char_map[i];
		    }
		    else{//如果为奇数
    			max_length += char_map[i] - 1;
    			flag = 1;
    		}
    	}
    	return max_length + flag;
    }
};

int main(){
	std::string s = "abccccddaa";
	Solution solve;
	printf("%d\n", solve.longestPalindrome(s));
	return 0;
}

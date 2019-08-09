/*
方法一：枚举，因为限制了长度为10，这个循环那就是常数级别，所以是o10N，就是oN，后面位运算方法二是oN
枚举DNA字符串中所有长度为10的子串，插入哈希map，key为子串，value为数量
然后遍历哈希map，将数量超过1的子串存储到结果中
*/
#include <stdio.h>

#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::map<std::string, int> word_map;//建立<序列，序列数量>的映射
    	std::vector<std::string> result;
    	for (int i = 0; i < s.length(); i++){
    		std::string word = s.substr(i, 10);//提取子字符串，从i开始延后10个字符
	    	if (word_map.find(word) != word_map.end()){ //哈希表中word不是在最后发现的，就是word在哈希里面
	    		word_map[word] += 1;
	    	}
	    	else{//如果不在就置1
	    		word_map[word] = 1;
	    	}
	    }
	    std::map<std::string, int> ::iterator it;
		 //创建一个map对应类型的迭代器，it相当于一个对象指针，有first和second
	    for (it = word_map.begin(); it != word_map.end(); it++){
    		if (it->second > 1){
		    	result.push_back(it->first);
		    }
    	}
    	return result;
    }
};

int main(){
	std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
	return 0;
}

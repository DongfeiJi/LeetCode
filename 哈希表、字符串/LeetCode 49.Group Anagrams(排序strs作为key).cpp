/*方法一：
异位词分组：出现的各个字符数相同，那么他们应该是同一个分组
如何建立哈希表？怎么设计key和value，将各个字符数相同的字符串映射到一起？
因此key可以是一个单词将字符排序，value用向量vector表示，包括异位词，如aet->eat,tea,ate
算法：设置字符串到字符串向量的哈希表anagram，遍历字符串中的向量strs[i]
1,设置临时变量str=strs[i],对str排序
2，如str未出现在哈希表中，设置str到一个空字符串向量的映射，此时str就是key，字符串向量向量就是value
3，将str[i]添加到字符串向量anagram[str]中
遍历哈希表，将全部key对应的value push到result中
*/
#include <stdio.h>

#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		std::map<std::string, std::vector<std::string> > anagram;//key是内部排序的各个单词，value该key的全部异位词
		std::vector<std::vector<std::string> > result;		
		for (int i = 0; i < strs.size(); i++){//遍历全部单词
			std::string str = strs[i];
			std::sort(str.begin(), str.end());//对单词内部排序作为key
			if (anagram.find(str) == anagram.end()){//如果迭代器找到最后，没找到str
				std::vector<std::string> item;//设置一个空的字符串向量
				anagram[str] = item;//建立key和value的映射
			}
			anagram[str].push_back(strs[i]);//在对应字符串向量中push结果
		}
		std::map<std::string, std::vector<std::string> > ::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++){
			result.push_back((*it).second);//这里传的一定是it指针，因为结果是一个vector
		}//这里注意迭代器用法，先声明，然后从begin，不等于end，it++，最后放入迭代器指针的第二个东西
    	return result;
    }
};

int main(){
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution solve;
	std::vector<std::vector<std::string> > result 
		= solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}

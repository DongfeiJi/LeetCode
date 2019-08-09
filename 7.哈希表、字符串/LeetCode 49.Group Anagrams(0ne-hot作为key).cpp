/*
这是方法二，与方法一区别就在于映射设计的多样化
异位词分组：出现的各个字符数相同，那么他们应该是同一个分组
如何建立哈希表？怎么设计key和value，将各个字符数相同的字符串映射到一起？
因此key可以是一个单词将字符排序，value用向量vector表示，包括异位词，如aet->eat,tea,ate
思想：将key设计为以26个字母构成的one-hot标签，value仍是字符串向量，这是映射再映射思想
算法：设置vector到字符串向量的哈希表anagram，遍历输入strs中的单词strs[i]
1，统计str[i]中各个字符数量，存储到vec
2，若vec未在anagarm中出现过，设置vec到一个空字符串向量的映射
3，将str[i]添加到字符串向量anagram[vec]中
遍历哈希表anagram，将全部key对应的value push到ruselt里面
*/
//总结：设计哈希表，作为key的一定是能唯一确定种类或者身份的，如one-hot label或者排序后词根
#include <stdio.h>

#include <vector>
#include <string>
#include <map>

void change_to_vector(std::string &str, std::vector<int> &vec){
	for (int i = 0; i < 26; i++){
		vec.push_back(0);
	}//初始化26个vector的value=0
	for (int i = 0; i < str.length(); i++){
		vec[str[i]-'a']++;//字符哈希映射
	}
}

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		std::map<std::vector<int>, std::vector<std::string> > anagram; //key是内部排序的各个单词，value该key的全部异位词
		std::vector<std::vector<std::string> > result;		
		for (int i = 0; i < strs.size(); i++){//遍历全部单词
			std::vector<int> vec;//声明初始化key是向量
			change_to_vector(strs[i], vec);//转换为0-1hot label 作为key
			if (anagram.find(vec) == anagram.end()){//哈希表中未找到此时对应的key
				std::vector<std::string> item;
				anagram[vec] = item;//建立映射
			}
			anagram[vec].push_back(strs[i]);//在对应映射的value中push结果
		}
		std::map<std::vector<int>,std::vector<std::string> > ::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++){
			result.push_back((*it).second);//这里因为是传入数组，因此一定是（*it）
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
	std::vector<std::vector<std::string> > result = solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}

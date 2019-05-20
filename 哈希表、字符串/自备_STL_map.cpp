#include <stdio.h>
#include <map>
#include <string>



int main(){
	std::map<std::string, int> hash_map;	
	std::string str1 = "abc";
	std::string str2 = "aaa";
	std::string str3 = "xxxxx";	
	hash_map[str1] = 1;
	hash_map[str2] = 2;
	hash_map[str3] = 100;//建立map字符到数字的映射	
	if (hash_map.find(str1) != hash_map.end()){//找到str1在map里 
		printf("%s is in hash_map, value is %d\n",
			str1.c_str(), hash_map[str1]);// c_str()：生成一个const char*指针，指向以空字符终止的数组。 
	}	
	std::map<std::string, int> ::iterator it;//声明一个map类型的迭代器指针 
	for (it = hash_map.begin(); it != hash_map.end(); it++){//从map  begin到end进行遍历 
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);
	}	
	return 0;
}

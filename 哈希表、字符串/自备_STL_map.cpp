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
	hash_map[str3] = 100;//����map�ַ������ֵ�ӳ��	
	if (hash_map.find(str1) != hash_map.end()){//�ҵ�str1��map�� 
		printf("%s is in hash_map, value is %d\n",
			str1.c_str(), hash_map[str1]);// c_str()������һ��const char*ָ�룬ָ���Կ��ַ���ֹ�����顣 
	}	
	std::map<std::string, int> ::iterator it;//����һ��map���͵ĵ�����ָ�� 
	for (it = hash_map.begin(); it != hash_map.end(); it++){//��map  begin��end���б��� 
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);
	}	
	return 0;
}

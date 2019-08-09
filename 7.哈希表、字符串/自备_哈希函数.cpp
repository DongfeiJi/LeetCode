//哈希函数就是建立一个不是一对一的映射关系（1对1也可以），分为针对整型的哈希函数与针对字符型哈希函数
//哈希函数一般就是对哈希表长取余数
//哈希表重点在于建立映射关系 
#include <stdio.h>
#include <string>

int int_func(int key, int table_len){
	return key % table_len;
}

int string_func(std::string key, int table_len){
	int sum = 0;
	for (int i = 0; i < key.length(); i++){
		sum += key[i];
	}
	return sum % table_len;
}

int main(){
	const int TABLE_LEN = 10;
	int hash_map[TABLE_LEN] = {0};	
	hash_map[int_func(99999995, TABLE_LEN)]++;
	hash_map[int_func(5, TABLE_LEN)]++;//这两个在哈希表中将会是同一位置 
	hash_map[string_func("abc", TABLE_LEN)]++;
	hash_map[string_func("bac", TABLE_LEN)]++;//这两个在哈希表中将会是同一位置	
	for (int i = 0; i < TABLE_LEN; i++){
		printf("hash_map[%d] = %d\n", i, hash_map[i]);
	}
	return 0;
}



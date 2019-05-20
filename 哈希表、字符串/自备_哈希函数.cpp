//��ϣ�������ǽ���һ������һ��һ��ӳ���ϵ��1��1Ҳ���ԣ�����Ϊ������͵Ĺ�ϣ����������ַ��͹�ϣ����
//��ϣ����һ����ǶԹ�ϣ��ȡ����
//��ϣ���ص����ڽ���ӳ���ϵ 
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
	hash_map[int_func(5, TABLE_LEN)]++;//�������ڹ�ϣ���н�����ͬһλ�� 
	hash_map[string_func("abc", TABLE_LEN)]++;
	hash_map[string_func("bac", TABLE_LEN)]++;//�������ڹ�ϣ���н�����ͬһλ��	
	for (int i = 0; i < TABLE_LEN; i++){
		printf("hash_map[%d] = %d\n", i, hash_map[i]);
	}
	return 0;
}



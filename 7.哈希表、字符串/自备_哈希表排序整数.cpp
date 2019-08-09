//哈希表排序整数，实质在于将随机顺序数组，作为哈希表下标，映射到哈希表里面 
//由于哈希表下标有序，因此哈希表value>0的顺序打印就是排序后的 
#include <stdio.h>

int main(){
	int random[10] = {999, 1, 444, 7, 20, 9, 1, 3, 7, 7};
	int hash_map[1000] = {0};//哈希表开的大小一般是列表数据的最大值
	for (int i = 0; i < 10; i++){
		hash_map[random[i]]++;//建立哈希映射
	}	
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < hash_map[i]; j++){//这里注意可以包括重复值，只需一直让value打印到足够数量即可，for实现
			printf("%d\n", i);
		}
	}	
	return 0;
}


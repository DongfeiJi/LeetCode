//字符哈希是整型下标（字符ASCII码的数值）-----字符的映射，一共128位
#include <stdio.h>
#include <string>

int main(){
	int char_map[128] = {0};//整型数组实现字符哈希128位
	std::string str = "abcdefgaaxxy";
	
	for (int i = 0; i < str.length(); i++){
		char_map[str[i]]++;//对应字符转整数的下标对应的value++
	}
	
	for (int i = 0; i < 128; i++){
		if (char_map[i] > 0){
			printf("[%c][%d] : %d\n", i, i, char_map[i]);//遍历哈希数组value的值大于0，说明存在这个字符，[a][97] : 3即存在3个a 
		}
	}
	return 0;
}


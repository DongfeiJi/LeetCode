
#include <stdio.h>
#include <string>
#include <vector>

bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){//用来判断map_s[]是否包含map_t[]中全部字符
	for (int i = 0; i < vec_t.size(); i++){
		if (map_s[vec_t[i]] < map_t[vec_t[i]]){
			return false;
		}
	}
	return true;
}

int main(){
	std::string s = "ADOBECODEBANC";
	std::string t = "ABCDAB";
	const int MAX_ARRAY_LEN = 128;
	int map_t[MAX_ARRAY_LEN] = {0};
 	int map_s[MAX_ARRAY_LEN] = {0};
 	std::vector<int> vec_t;
 	
 	for (int i = 0; i < s.length(); i++){//建立map_s字符哈希
 		map_s[s[i]]++;
   	}
 	for (int i = 0; i < t.length(); i++){//建立map_t[]字符哈希
 		map_t[t[i]]++;
   	}
   	for (int i = 0; i < MAX_ARRAY_LEN; i++){
   		if (map_t[i] > 0){
    		vec_t.push_back(i);//保存t中出现字符的全部key到数组
      	}
  	}
  	
  	printf("String S %s 's char number:\n", s.c_str());
  	for (int i = 0; i < MAX_ARRAY_LEN; i++){
	  	if (map_s[i]>0){
	  		printf("%c : %d\n", i, map_s[i]);//打印s中的key-value，其中key是字符 
	  	}
  	}
  	printf("String T %s 's char number:\n", t.c_str());
  	for (int i = 0; i < MAX_ARRAY_LEN; i++){
	  	if (map_t[i]>0){
	  		printf("%c : %d\n", i, map_t[i]);//打印t中的key-value，其中key是字符 
	  	}
  	}
  	printf("String T %s 's char:\n", t.c_str());
  	for(int i = 0; i < vec_t.size(); i++){
		printf("%c\n",vec_t[i]);  	//打印t中全部key， 其中key是字符 
  	}	
	printf("is_window_ok = %d\n", is_window_ok(map_s, map_t, vec_t));//判断是否ok	
	return 0;
}


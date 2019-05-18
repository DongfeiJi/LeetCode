#include <stdio.h>
#include <string>

int main(){
	std::string str = "123#456#10000#1#";
	int val = 0;
	for (int i = 0; i < str.length(); i++){
		if (str[i] == '#'){
			printf("val = %d\n", val);
			val = 0;
		}
		else{
			val = val * 10 + str[i] - '0';
		}
	}
	return 0;
}


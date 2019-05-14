
#include <stdio.h>
#include <queue>
int main(){	
	std::queue<int> Q;
	if (Q.empty()){
		printf("Q is empty!\n");
	}
	Q.push(5);
	Q.push(6);
	Q.push(10);
	printf("Q.front = %d\n", Q.front());
	Q.pop();
	Q.pop();
	printf("Q.front = %d\n", Q.front());
	Q.push(1);
	printf("Q.back = %d\n", Q.back());
	printf("Q.size = %d\n", Q.size());
	return 0;
}



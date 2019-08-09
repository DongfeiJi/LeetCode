
#include <stdio.h>
#include <queue>
int main(){
	std::priority_queue<int> big_heap;//默认大根堆
	std::priority_queue<int, std::vector<int>,
					std::greater<int> > small_heap;//小根堆
	std::priority_queue<int, std::vector<int>,
					std::less<int> > big_heap2;//大根堆
					
	if (big_heap.empty()){
		printf("big_heap is empty!\n");
	}	
	int test[] = {6, 10, 1, 7, 99, 4, 33};
	for (int i = 0; i < 7; i++){
		big_heap.push(test[i]);
	}
	printf("big_heap.top = %d\n", big_heap.top());
	big_heap.push(1000);
	printf("big_heap.top = %d\n", big_heap.top());
	for (int i = 0; i < 3; i++){
		big_heap.pop();
	}
	printf("big_heap.top = %d\n", big_heap.top());
	printf("big_heap.size = %d\n", big_heap.size());
	return 0;
}


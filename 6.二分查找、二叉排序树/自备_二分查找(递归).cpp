#include <stdio.h>

#include <vector>

bool binary_search(std::vector<int> &sort_array,
				   int begin, int end, int target){
	if (begin > end){
		return false;
	}
	int mid = (begin + end) / 2;
	if (target == sort_array[mid]){
		return true;
	}
	else if (target < sort_array[mid]){
		return binary_search(sort_array, begin, mid-1, target);
	}
	else if (target > sort_array[mid]){
		return binary_search(sort_array, mid + 1, end, target);
	}
}

std::vector<int> search_array(std::vector<int> &sort_array,
							  std::vector<int> &random_array){
	std::vector<int> result;
	for (int i = 0; i < random_array.size(); i++){
		int res = binary_search(sort_array,
								0,
								sort_array.size() - 1,
								random_array[i]);
		result.push_back(res);
	}
	return result;
}

int main(){
	int A[] = {-1, 2, 5, 20, 90, 100, 207, 800};
	int B[] = {50, 90, 3, -1, 207, 80};
	std::vector<int> sort_array;
	std::vector<int> random_array;
	std::vector<int> C;
	for (int i = 0; i < 8; i++){
		sort_array.push_back(A[i]);
	}
	for (int i = 0; i < 6; i++){
		random_array.push_back(B[i]);
	}
	C = search_array(sort_array, random_array);
	for (int i = 0; i < C.size(); i++){
		printf("%d\n", C[i]);
	}
	return 0;
}

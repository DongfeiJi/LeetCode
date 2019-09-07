快排版本2;
//快排核心就是选定一个数，大于它的放在右侧。小于他的放在左侧
int findmiddle(int a, int b, int c){
	if(a >= b && a <= c){
		return a;
	}
	else if(b >= a && b <= c){
		return b;
	}
	else{
		return c;
	}
}

void quicksortHelper(vector<int>& a, int start, int end){
	if(start >= end){
		return;
	}
	int l = start, r = end;//大于区和小于区
	int privot = findmiddle(a[start], a[end], a[start + (end - start) / 2]);//基准
	while(l <= r){
		while(l <= r && a[r] > privot) r--;//如果右侧的当前值大于基准，不处理，就是r--
		while(l <= r && a[l] < privot) l++;//如果左侧的当前值小于基准，不处理，就是l++
		//此时就是r下标是右侧第一个小于基准的
		//l下标就是左侧第一个大于基准的
		if(l <= r) swap(arr[l++],arr[r--]);//此时交换，保证大于区小于区符合条件
	}
	quicksortHelper(a, start, r);
	quicksortHelper(a, l, end);
}


void quicksort(vector<int>& a)
{
    quicksortHelper(a, 0, a.size() - 1);
}
���Ű汾2;
//���ź��ľ���ѡ��һ�������������ķ����ҲࡣС�����ķ������
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
	int l = start, r = end;//��������С����
	int privot = findmiddle(a[start], a[end], a[start + (end - start) / 2]);//��׼
	while(l <= r){
		while(l <= r && a[r] > privot) r--;//����Ҳ�ĵ�ǰֵ���ڻ�׼������������r--
		while(l <= r && a[l] < privot) l++;//������ĵ�ǰֵС�ڻ�׼������������l++
		//��ʱ����r�±����Ҳ��һ��С�ڻ�׼��
		//l�±��������һ�����ڻ�׼��
		if(l <= r) swap(arr[l++],arr[r--]);//��ʱ��������֤������С������������
	}
	quicksortHelper(a, start, r);
	quicksortHelper(a, l, end);
}


void quicksort(vector<int>& a)
{
    quicksortHelper(a, 0, a.size() - 1);
}
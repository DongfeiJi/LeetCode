###�鲢����
ʵ���߼�:

�ѳ���Ϊn���������зֳ���������Ϊn/2�������У�
�������������зֱ���ù鲢����
����������õ������кϲ���һ�����յ��������С�

####��·�鲢����
(��������;ʱ��A:NlogN,B:NlogN,E:N*logN;�ռ�N;�ȶ�)

/*
    �鲢�����ڲ����淨 ���԰ѿռ临�ӶȽ���O(1)��
    �鲢����ԭ�ع鲢�� Ҳ���԰ѿռ临�ӶȽ���O(1)����ʱ�临�ӶȻ���O(N^2)
*/
void merge(int arr[],int L,int M,int R){
    int* cent = new int[R - L + 1];//��������
    int i = 0;//��ʼ���±�
    int pFirst = L;//�󲿷���ʼ�±�
    int pSecond = M+1;//�Ҳ�����ʼ�±�
    while (pFirst <= M && pSecond <= R) {
        cent[i++] = arr[pFirst] < arr[pSecond] ? arr[pFirst++]:arr[pSecond++];//С�ĸ�ֵ���������飬�±�++
    }
    while (pFirst <= M) {
        cent[i++] = arr[pFirst++];//����ʣ��
    }
    while (pSecond <= R) {
        cent[i++] = arr[pSecond++];//����ʣ��
    }
    for (int j = 0; j < (R-L+1); j++) {
        arr[L+j] = cent[j];//������ȥ
    }
    
}
void mergeSort(int arr[],int L,int R){
    if (L == R){
        return;
    }
    int mid = (L+R)/2;
    mergeSort(arr, L, mid);//�ݹ���
    mergeSort(arr, mid+1, R);//�ݹ���
    merge(arr,L,mid,R);//�ϲ������
}
void mergeSort(int array[],int length){
    if (array == nullptr || length<2) {
        return;
    }
    mergeSort(array,0,length - 1);
}
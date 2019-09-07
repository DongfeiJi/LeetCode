###������
�㷨����:��������ʵ�֣��������뽨��heapInsert�Լ���֦�����heapify��������
��������Ƚ��ѣ�Ȼ�󲻶Ͻ����Ѻ���Сֵ����֮���֦���ٵ��ɴ���ѣ���Ϳ��Բ����ҳ����ֵ����˷���


(ѡ������;ʱ��A:NlogN,B:NlogN,E:NlogN;�ռ�1;���ȶ�)

/*
        �ѵĸ�����ڴ���ѣ��������µ����нڵ�,�������Լ����ڵ����ֵΪͷ��㡣
        ʱ�临�Ӷ�Ϊ0+log1+log2+������ѧ�Ͽ���֤��
        ���ֵ������O(N)
*/
//���Ѳ��룬���Ϲ���
void heapInsert(int arr[],int index){
    while (arr[index] > arr[(index-1)/2]) {
        exchangee(arr,index, (index-1)/2);
        index = (index -1)/2;
    }
}
//��֦����������¹���
//sizeΪ���ҵı߽磬size��ȡ������.
void heapify(int arr[],int index ,int size){//�������arr��������飬indexΪ��ǰ����㣬size�ǵ����ľ��룬ȡ����size
    int leftChild = index*2 + 1;//�����±�
    while (leftChild < size) {//��Խ��
        int maxChild = leftChild + 1 < size && arr[leftChild+1] >arr[leftChild] ? leftChild+1 : leftChild;//�Һ��Ӳ�Խ�磬���������Һ���˭��˭��ֵ��maxChild
        int maxAll = arr[maxChild] > arr[index] ? maxChild: index;//�����ڵ��maxChild���жԱȣ����ĸ�ֵ��maxAll
        if (maxAll  == index) {//�����������break
            break;
        }
        exchangee(arr, maxAll, index);//�����ڵ������ĺ��ӽ���
        index = maxAll;//���ڵ�������ӽ��
        leftChild = index*2 +1;//�ӽڵ����µ���
    }
}   
int main(){
    for(int i = 0;i <length;i++){
        heapInsert(arr, i);//����
    }
    int size = length;
    exchangee(arr, 0, --size);//����������ĸ��ڵ�0�±꣬�����Ҳ�Ľ�㽻����ע������ÿ�������һ����sizeҲ���С
    while (size > 0){//��������
        //heapifyʱ�临�Ӷ�ΪO(logN)
        heapify(arr, 0, size);//����һ���͵���
        exchangee(arr, 0, --size);//����������--size����������
    }
    
    return 0;
}    
###��������
ʵ���߼�:

��������ʹ�÷��η�����һ������list����Ϊ�����Ӵ���sub-lists���������㷨�������£�
������������һ��Ԫ�أ���Ϊ ����׼����pivot����
�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ�������������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������
�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������

####�����������

����������;ʱ��A:NlogN,B:NlogN,E:NlogN;�ռ�logN;���ȶ���

/*
    (1)in-placeԭ���㷨����ʵ�� ���Ի���ֵΪ��׼��
       С�ڵ��ڻ���ֵ�ķ���߲����Ŵ��ڻ���ֵ���������ߡ�
       ʱ�临�Ӷ�O(N)�ռ临�Ӷ���O��1��
    (2)�������������⣩��ʵ�ְѵ��ڻ���ֵ�ķ��м䣬С��
        ����ֵ�ķ���ߣ����ڻ���ֵ�ķ��ұ���ʱ�临�Ӷ�O(N)
        �ռ临�Ӷ���δO(1)��ʱ��1.��ǰ��<p������һ��
        �������������������һ����2����ǰ������p�������
        һ����3����ǰ������p��������ǰһ��λ�û�����������
        ������⵱ǰ���������
    (3) ���еĿռ临�Ӷ��ǲ��ò�ʹ�õĿռ䣬������¼ÿ�ε����ұ߽硣
    (4)����������������ȶ������Ƿǳ��ѣ������� 0-1stable sort���ġ�
*/
int* separate(int arr[],int left,int right){//�����partition���̣�left�൱�ڵ�ǰֵ�±꣬right��ʵ���ǻ�׼
    int first  = left -1;//С�����������-1
    int Second = right;//�����������Ҳ࣬����ȡ��ǰ��׼����arr[right]
    while (left < Second) {//����С�����±꣬���ﲻ�õ��ڣ���Ϊ���ڵ�ʱ��Ͳ����ж���
        if(arr[left]<arr[right]){//�����ǰֵС�ڻ�׼
            exchangee(arr, ++first, left++);//��С��������С������һ�����佻��++first�������һ��left++
        }else if(arr[left]>arr[right]){//�����ǰֵ���ڻ�׼
            exchangee(arr, --Second, left);//���������--second������ǰֵleft���佻��������˵��ʱ������ţ�right�±�һֱû����
        }else if(arr[left]==arr[right]){//�����ȣ��ж���һ��left++
            left++;
        }
    }
    exchangee(arr, Second, right);//��Ϊrightǰ�涼�����ǻ�׼��û��������Խ���������һ��second��right����
    int firstAndSecond[2] = {first+1,Second};//��С�����ʹ������߽籣�浽�������淵��

    return firstAndSecond;
}

void quickSort(int arr[],int left, int right){//������Ź��̣�������������
    if (left<right) {//�����С���ң��жϷǷ�����
        int randomC = (int)((rand()%100/(double)100) * (right - left +1));//�������ѡȡһ����׼
        exchangee(arr,left+ randomC, right);//����ֵ���������
        int* curArr  = separate(arr, left, right);//����partition���̷���С�����ʹ������߽�
        quickSort(arr, left,curArr[0] -1 );//�ݹ������
        quickSort(arr, curArr[1]+1, right);//�ݹ������
    }
}
void quickSort(int arr[],int length){//������ţ��������ȣ�ȫ���У���װ��Ҳ����������ĵ��ã�������������
    if (length < 2) {
        return;//�Ƿ�����
    }
    quickSort(arr,0,length-1);//ֱ�ӿ���
}
int main(){
    int arr[9]={99,11,72,62,53,4,44,21,14};
    int length = len(arr);
    quickSort(arr,length);
return 0;
}

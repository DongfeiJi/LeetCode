####���������С�����⣺
����������
��С�����⣺�����Ԫ�أ���������С�������У��ҳ���߱��ұ�Ԫ��С������Ԫ��֮�͡�
���磺����[4,2,5,1,7,3,6] ��һ��Ԫ��4��2�󣬲���С�ͣ�5��4��2�����Ǿ���4+2=6��1��4��2��5��С������С�ͣ�7��ǰ��Ķ����Ǿ����ϴ�С��6+4+2+5+1=18��Ȼ��3ǰ���2��1���Ǿ���18+2+1=21�����6��4��2��5��1��3���󣬽������21+4+2+5+1+3=36����ô���Ľ������36��

//С������
int allSum(int arr[],int L,int mid,int R){//����L-midΪ������mid+1-RΪ��������������Ӧ��������ȫ��С��

    int *help = new int(R-L+1);//�������飬��Ϊֻ��עpartitionһ�߷���
    int i = 0 ;//��ʼ�±�
    int pFirst = L;//���������±�
    int pSecond = mid + 1;//���������±�
    int sum = 0;//������Ӧ��������ȫ��С��

    while (pFirst <=mid && pSecond <=R) {
        /*
        ��������������˭С˭�ƶ���ԭ�򣬿�С����������������ʱ��Ҫץסһ�߷����� 
        С�����⣬��ΪҪͳ������С��������������������ͳ������������С��������Ϊ�������ʱ���������ܻ��ƶ���
        ���������ƶ����޷�����һ���鿴�������ڵ���������Ҫһ���԰����������ǰ�������ȫ����¼����
        ��������⣬����Ҫһ��һ����¼���������������������Ҫ����Ϊ�Ӵ�С����!!��
        */
        sum += arr[pFirst] < arr[pSecond] ? arr[pFirst]*(R-pSecond+1):0;//������Ӧ������ȫ��С��
        help[i++]  = arr[pFirst] < arr[pSecond] ? arr[pFirst++]:arr[pSecond++];//ͨ��ʹhelp�б�����Ǽ����С�͵��������飬��pFirst��pSecond�ֱ�++
    }
    while (pFirst <= mid ) {
        help[i++] = arr[pFirst++];//������ʣ��
    }
    while (pSecond <= R) {
        help[i++] = arr[pSecond++];//������ʣ��
    }
	//��ʱhelpΪ���������Ӧ���Ҳ�ȫ����С��
    for (int k = 0; k < (R-L+1); k++) {
        arr[L+k] = help[k];//��ֵ��ȥ��arr����ʱarrֻ������������Ӧ��������ȫ��С�ͣ������Ҳ���һ������ȫ�����
    }
    return sum;
}


int smallSum(int arr[],int L,int R){//�ݹ����ȫ��С�ͣ�������С��+��С��+������ҵ�С��
    if (L==R) {
        return 0;
    }
    int  mid = L+((R-L)>>1);
    int leftSum = smallSum(arr, L, mid);
    int rightSum = smallSum(arr, mid + 1, R);
    int leftAndRightSum = allSum(arr,L,mid,R);
    return  leftSum + rightSum + leftAndRightSum;
//    return smallSum(arr, L, mid)+smallSum(arr, mid + 1, R)+allSum(arr,L,mid,R);
}
int smallSum (int arr[],int length){
    if(arr == nullptr || length <2){//�Ƿ�����
        return 0;
    }
    return smallSum(arr,0,length -1);//���
}
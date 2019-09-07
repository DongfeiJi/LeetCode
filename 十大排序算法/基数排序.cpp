###10����������ʵ�ʾ����ȱȽϵ�λ����Ͱ���ó�ȥ�ٱȽϸ�λ���ó�ȥ
�㷨����:

���������ǰ��յ�λ������Ȼ���ռ����ٰ��ո�λ����Ȼ�����ռ����������ƣ�ֱ�����λ��
��ʱ����Щ�����������ȼ�˳��ģ��Ȱ������ȼ������ٰ������ȼ�����
���Ĵ�����Ǹ����ȼ��ߵ���ǰ�������ȼ���ͬ�ĵ����ȼ��ߵ���ǰ��

(��������;ʱ��A:N * k , B:N * k , E:N * k ; �ռ�N+k ; �ȶ�)

//�õ���������λ��
int getRadixCount(int count){
    int num = 1;
    if (count /10 >0) {
        num ++;
    }
    return num;
}
//�õ�10�Ĵ���λ���Ĵη�(10^num)����ʵ���ǽ�λ��ת�شη�
int getTenRadixCount(int radixCount){
    int tenRadix = 1;
    while (radixCount > 0 ) {
        tenRadix *= 10;
        radixCount --;
    }
    return tenRadix;
}
void radixSort(int arr[], int length){
    int len = length;
	//������ֵ
    int max = arr[0];
    for (int i =1 ; i< length; i++) {
        max = arr[i]>max? arr[i]:max;
    }
	//ͨ�����ֵ����������ж���λ
    int radixCount = getRadixCount(max);
	//������λת����10�Ĵη�
    int tenRadixCount = getTenRadixCount(radixCount);

    int (*bucket)[10] = new int[10][10];//new10������10���ڴ��������ΪͰ����ΪҪ��֤����������Ͱ�ж����򣨿�����Ҫ��������
    int* flag = new int[10]();//newһ��10���ڴ�����飬��Ϊÿһλֻ��0-9һ��ʮ�������൱�ں����׼10��λ��Ͱ��flag��������
    int multiplier = 1;//�Ӹ�λ��ʼ
    while (multiplier < tenRadixCount) {//��Խ��
        for (int i = 0; i< len; i++) {
            int curCount = arr[i]/multiplier%10;//��ǰλ��ֵ
            int k = flag[curCount];//k��ʵ�Ǽ������������Ͱ�������ڵ�k��λ��
            bucket[curCount][k] = arr[i];//����ǰλ��ֵ��Ͱ�������ǳ��ֵĴ�����ֵ��Ͱ
            flag[curCount]++;//��ǰλ�õ�ֵ����++
        }
        int index = 0;
        for (int j = 0; j < 10; j++) {//ѭ����10��Ͱ׼����ԭ��ȥ
            if (flag[j]!=0) {//��Ͱ��ֵ
                for (int k =0; k<flag[j]; k++) {//���������Ͱ
                    arr[index++]  =  bucket[j][k];//��ֵ��ȥ
                }
            }
            //��Ͱ��գ�׼����һ��ѭ����
            flag[j] = 0;
        }
        multiplier *= 10;//��һ����λ������
    }
}
####Ͱ����˼�룺�������ֵ����
��������

�������ֵ���⡣
����һ���������飬���������֮����������������ֵ��
Ҫ��ʱ�临�Ӷ�O��N������Ҫ�����û��ڱȽϵ�����
�Դ��ⷢ��Ͱ������Ȥ˼��.

/*
     ӳ�亯��getGroupCount�ǵõ��ڵڼ���Ͱ�����ܱ�֤��һ
  ��Ͱ�������������Сֵ�����һ��Ͱ��������������ֵ��
*/
int getGroupCount(long num,long size ,long min ,long max ){//���㵱ǰnum�ڵڼ���Ͱ
    int count = (int)((size-1)*(num - min)/(max - min));
    return count;
}

int maxGroup(int arr[],int length){//ע������û��size
    if (length < 2){
        return 0;//�Ƿ�����
    }
    int len = length;
    //�õ�ϵͳ�����ֵ��ϵͳ����Сֵ
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i= 0; i<len; i++) {
        min = arr[i]<min ? arr[i]:min;
        max = arr[i]>max ? arr[i]:max;
    }
	//���ֵ����Сֵ���˵���������ֵȫ����ͬ��ֱ��return
    if (min == max){
        return 0;
    }
	//
    int bid = 0;
    int* maxValue =new int[len+1];
    int* minValue =new int[len+1];//���������飬ÿһ����Ӧλ�ö��൱��һ��Ͱ�����Դ�ʱ����ÿ��Ͱ��sizeΪ2
    bool* flag = new bool[len+1];//��Ͱ����ֵ�ı������
    for (int j = 0; j<len; j++) {//����ԭ����
        bid = getGroupCount(arr[j], len, min, max);
        minValue[bid] = minValue[bid]? (minValue[bid]<arr[j]?minValue[bid]:arr[j]):arr[j];//minͰ�д��ʼ���ǽ�Сֵ
        maxValue[bid] = maxValue[bid]? (maxValue[bid]>arr[j]?maxValue[bid]:arr[j]):arr[j];//maxͰ�д��ʼ�������ֵ
        flag[bid] = true;//���Ͱ����ֵ�ı��
    }
    int res = 0;
    int lastMax = 0;//����ֵ
    for (int k= 1 ; k<len+1; k++) {//������ЩͰ
        if (flag[k]) {//����ô���ֵ
            res = res > (minValue[k] - maxValue[lastMax]) ? res :(minValue[k] - maxValue[lastMax]);
			//���ڴ�ʱͰ������ģ�resʼ��Ϊ�������ڵ���������ֵ
            lastMax =k;//��֤���ڵ����Ƚ�
        }
    }
    return res;
}
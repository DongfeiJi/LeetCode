###��������
�㷨����:

ʵ���߼�:
һ����˵���������򶼲���in-place��������ʵ�֡������㷨�������£�
�ӵ�һ��Ԫ�ؿ�ʼ����Ԫ�ؿ�����Ϊ�Ѿ�������
ȡ����һ��Ԫ�أ����Ѿ������Ԫ�������дӺ���ǰɨ�裻
�����Ԫ�أ������򣩴�����Ԫ�أ�����Ԫ���Ƶ���һλ�ã�
�ظ�����3��ֱ���ҵ��������Ԫ��С�ڻ��ߵ�����Ԫ�ص�λ�ã�
����Ԫ�ز��뵽��λ�ú�
�ظ�����2~5��

####��������

(��������;ʱ��A:N^2 , B:N^2 , E:N;�ռ�1;�ȶ�)

    //����һ���ڶԱȵ�ʱ�򲻽�����
    for (int i =1; i < length;i++ ) {
        int current = arr[i];
        int preIndex = i-1;
        while (preIndex >= 0&& arr[preIndex]>current) {
            /*
            ����ֱ�ӽ�������Ϊcurrent��¼�����һ��ֵ��
            ��������ʹ������ƶ�˼�롣
            exchangee(arr, preIndex, current);
            */
            arr[preIndex+1] = arr[preIndex];
            preIndex --;
        }
        arr[preIndex+1] = current;
    }
     //���������ڶԱȵ�ʱ����н�����
    for(int i = 1 ; i<length ;i++){
        for (int j = i - 1; j>=0 && arr[j]>arr[j+1]; j--) {
            exchangee(arr, j, j+1);
        }
    }
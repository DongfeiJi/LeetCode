###9��Ͱ����
�㷨����:

Ͱ�����Ǽ�������������档�������˺�����ӳ���ϵ����Ч���Ĺؼ����������ӳ�亯����ȷ����
Ͱ���� (Bucket sort)�Ĺ�����ԭ�������������ݷ��Ӿ��ȷֲ��������ݷֵ�����������Ͱ�ÿ��Ͱ�ٷֱ�����
���п�����ʹ�ñ�������㷨�����Եݹ鷽ʽ����ʹ��Ͱ��������ţ���

ʵ���߼�:
����һ�����������鵱����Ͱ�������������ݣ����Ұ�����һ��һ���ŵ���Ӧ��Ͱ��ȥ��
��ÿ�����ǿյ�Ͱ��������
�Ӳ��ǿյ�Ͱ����ź��������ƴ��������

Ͱ����(ʱ��A:N+k,B:N^2,E:N+k;�ռ�N+k;�ȶ�)
//Ͱ������: Ͱ˼������ + һ����ͨ�����򣨳��ÿ�������


/*
 ӳ�亯��getGroupCount�ǵõ��ڵڼ���Ͱ�����ܱ�֤��һ��Ͱ�������������Сֵ�����һ��Ͱ��������������ֵ��
 sizeΪһ��Ͱ�����������ķ�Χ
*/
int getGroupCount(long num,long size ,long min ,long max ){//���Ǽ���ĳֵӦ���ڵڼ���Ͱ
    int count = (int)((size)*(num - min)/(max - min));//Ͱ��С*��ǰֵ����Сֵ�Ĳ�/���ֵ����Сֵ�Ĳ�
    return count;//���������num�Լ�Ͱ��Сsize�����ֵ����Сֵ�����ɷ���num�ڵڼ���Ͱ��Ҫ��֤ͰҲ�������
}

void bucketSort(int arr[],int length,int size){//Ͱ�ţ�����������飬���鳤�ȣ�Ͱ��С
    if (length < 2 ){
        return;
    }
    int len = length;
    //�õ������Сֵ
    long min = arr[0];
    long max = arr[0];
    for (int i = 1 ; i<len; i++) {
        min = arr[i] < min ? arr[i]: min;
        max = arr[i] > max ? arr[i]: max;
    }
    //�����Сֵ�������ֵ˵�������о�һ����
    if (min == max) {
        return;
    }
    //����Ͱ
    int bucketCount = (int)((max -min)/size +1);//Ͱ�������������ֵ��ȥ��Сֵ�ٳ���size+1
    vector<vector<int>> bucket(bucketCount);//�������飬һ����bucketCount��
    int bid = 0;//����һ��Ͱ���±꣬��ΪҪ��Ͱ����Ŷ����ˣ�Ҫ���㵱ǰ��num���ڵڼ���Ͱ
    //�������е��� �ӽ�Ͱ��
    for (int i =0;  i < len; i++) {
        bid = getGroupCount(arr[i], bucketCount, min, max);
        bucket[bid].push_back(arr[i]);
    }
	/*��δ����Ƕ�ÿ��Ͱ���������򣬺���������
    for (int i=0; i< bucketCount; i++) {
        //��Ͱ�ڽ��в������򡣰��������������Ա�֤�������϶����ȶ���
        for (int j = 1; j<bucket[i].size(); j++) {
            if  (bucket[i][j] < bucket[i][j-1]) {
                swap(bucket[i][j],bucket[i][j-1]);//������������������������������������򲻶԰ɣ�����һ��
            }
        }		 
    }
	*/
    //�޸İ汾���������򣬶�ÿ��Ͱ��������
	for (int i=0; i< bucketCount; i++) {
        //��Ͱ�ڽ��в������򡣰��������������Ա�֤�������϶����ȶ���
        for (int j = 1; j<bucket[i].size(); j++) {
            for (int k = j - 1; k >= 0 && bucket[i][k] > bucket[i][k+1]; k--) {
                swap(bucket[i][k],bucket[i][k+1]);
            }
        }	
        /*��ӡͰ�е���
        for (int t = 0; t< bucket[i].size(); t++) {
            cout<<bucket[i][t]<<' ';
        }
		*/   		
    }

    //    int *newArr = new int[len];
    int index = 0;
    for (int i =0 ;i<bucketCount ;i++){//����ǽ�����Ͱ�е�����������
        for (int j =0; j<bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }    
}
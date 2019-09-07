/*
ʮ�󾭵������㷨���Է�Ϊ�����ࣺ
0��������ʱ������ͨ���Ƚ�������Ԫ�ؼ����Դ���ʱ�临�Ӷ����ΪO(logN)
1������ʱ������ͨ����������Ŀռ䣬��Ԫ�ذ���һ���Ĺ����������ռ䣬������ȡ�����Կռ�����ȡʱ�䣬����ͻ��O(logN)

������ʱ�����򣺱Ƚ�����/ð������/��������/��������/��������/ϣ������/ѡ������/ѡ������/������/�鲢����/��·�鲢����/��·�鲢����
����ʱ�����򣺼�������/������/��������

�ȶ�������
���ȶ�������

*/
-------------------------------------�����ķָ���-------------------------------------
(1)�����鳤�ȣ���Ҫ�����飬��Ҫ������ָ�룩

/*    �����ע��㣺�ڼ��������С��ʱ��
   һ��Ҫע�⴫��������Ƿ�Ϊ����ָ�룬
   ��������������ָ�룬sizeof�������ֵΪ8(64λ��)��Ӧע�⡣
*/
template <class T>
int len(T& arr){   
    int length = (int)sizeof(arr)/sizeof(arr[0]);
    return length;
}
-------------------------------------�����ķָ���-------------------------------------
(2)��������������

void exchangee(int arr[],int a, int b){
/*   ^���� ���������������ص�����0���
  ����ԭֵ���뱾����򣬽��Ϊ0��
     �������ʹ��λ���㣬����ʱ���ÿ��ٶ���ռ䡣
  ������������'λ����ͬ'�����������Ͳ����ڴ˺����н��н�����
  ��Ϊ���Լ����Լ�������һ��Ϊ0,��û��ʲô�����ˡ�
//    arr[a] = arr[a] ^ arr[b];
//    arr[b] = arr[a] ^ arr[b];
//    arr[a] = arr[a] ^ arr[b];
*/    
    int temp = arr[a];
    arr[a] =  arr[b];
    arr[b] = temp;
}
-------------------------------------�����ķָ���-------------------------------------
(3)��������������������㷨�ıȽ�
     /*
     ���������������ʱ�䵥λ����
     ���ݹ�ģ|�������� �鲢���� ϣ������ ������
     1000�� |  0.75  1.22    1.77    3.57
     5000�� |  3.78  6.29    9.48    26.54
     1��    |  7.65  13.06   18.79   61.31
     */ 
-------------------------------------�����ķָ���-------------------------------------
(4)ʱ�临�ӶȵĴ�С�Ƚ�
     /*
     N!> x^N >...>3^N >2^N > N^x>...>N^3 >N^2>NlogN>N>logN>1
     */
-------------------------------------�����ķָ���-------------------------------------
(5)����������С�Ľṹ��
struct arrAndSize{
    int *array;
    int size;
};
-------------------------------------�����ķָ���-------------------------------------
(6)��ʼ������
    //һά ÿ��Ԫ�ض�û�г�ʼ��
    int *p = new int[10];
    //һά ÿ��Ԫ�س�ʼ��Ϊ0
    int *p = new int[10](0);
    //��ά ÿ��Ԫ�ض�û�г�ʼ��
    int (*bucket)[10] = new int[10][10];
    //��ά ÿ��һά�к�N������NΪȷ������ֵ��
    vector<vector<int>> bucket(N);
    //ͨ����̬���������飬Ҫ�����ڴ��ͷţ������ڴ潫й©
    //(�����У�δ�����ڴ��ͷ�)
    delete []p;
-------------------------------------�����ķָ���-------------------------------------
(7)�ۺ������ܽ�

˼��һ������ʱ�򣬿���ʱ�临�Ӷ��е�ָ��ͳ�����ռ临�Ӷȣ��ȶ���.
�����ģ��һ���̶���˵���˳�����Ĵ�С�������ճ�����Ĵ�С�ǿ��������������Ĵ�����
ϵͳ��sort ���������ִ�������ֵΪ��ֵ�ͣ���ʹ�ÿ��ţ�������ִ��Ļ��бȽ�������ʹ�ù鲢����
�鲢�Ϳ������ָ��죿
���űȹ鲢����ĳ�����Ҫ�ͣ�����Ҫ�졣
Ϊʲô���й鲢�Ϳ��������أ�
�ڱȽϵ�ʱ��ʹ�ñȽ�����ʱ��Ҫ׷��һ���ȶ��ԣ�ʹ�ù鲢������Դ��ȶ��Ե�Ч����ʹ�ÿ��Ų��ܹ�ʵ���ȶ��Ե�Ч����
��Դ��ģ��ʱ�򣬵���������С�ڵ���60��ʱ��sort���� �����ڲ�ʹ�ò�������ķ�������һ����60����һ���Ĺ�ģ�����������ܵ͵�ʱ�򣬲�������ĳ�����͡�
��c��������һ�棬�ѹ鲢���򣬸ĳɷǵݹ飬�ǻ��ڹ����������ǡ�
-------------------------------------�����ķָ���-------------------------------------
(8)�Ա����������Ƿ���ͬ

bool isEqual(int firstArr[],int Second[]){
    if ((firstArr == nullptr && Second != nullptr) ||(firstArr != nullptr && Second == nullptr)) {
        return false;
    }
    if (firstArr == nullptr && Second == nullptr) {
        return  true;
    }
    if (len(firstArr) != len(Second)) {
        return false;
    }
    for (int i = 0; i< len(firstArr); i++) {
        if (firstArr[i] != Second[i]) {
            //�����ڴ�λ�ã���ӡ������
            //Ҳ���Դ�ӡ��������鿴������
            return false;
        }
    }
    return true;
}
-------------------------------------�����ķָ���-------------------------------------
(9)��������

int* arrayCopy(int oldArray[],int length){
    if (oldArray == nullptr) {
        return nullptr;
    }
   
    int* newArray = new int[length];
    for (int  i = 0; i<length;i++) {
        newArray[i] = oldArray[i];
    }
    return newArray;
}
-------------------------------------�����ķָ���-------------------------------------
(10)�����������

arrAndSize generateRandomArr(int maxSize,int maxValue){
//    int arrrr =rand()%10;
    arrAndSize aAndS;
    int size = (int)((maxSize+1) * (rand()%10/(double)10));
    cout<<"{"<<size<<"}";
    
    int* array = new int[size];
    for(int i =0 ;i < size;i++){
        // �������[-N,N];
//        array[i] = (int)((maxValue +1) * (rand()%100)/(double)100) - (int)((maxValue + 1) * (rand()%100/(double)100));
        //�������[0,N];
         array[i] = (int)((maxValue +1) * (rand()%10)/(double)10);
        //��ӡ����������ʲô��
//cout<<i<<"===="<<array[i] <<"|";
    }
//    cout<<"+++++"<<endl;
    aAndS.size = size;
    aAndS.array = array;
    return aAndS;
}
-------------------------------------�����ķָ���-------------------------------------
(11)���ݹ� -�ݹ�master��ʽ


/*
     �ݹ�master��ʽ
     T(N)�Ĺ�ʽ�Ӵ��ģ��������ϸ�֡�
     T(N) = a * T(N/b)+O(n^d)
     N/b ���ӹ��������� ��a���ӹ��̵��ö��ٴΣ�O(n^d)�ǳ�ȥ
 ����֮��ʣ�µ��������Ķ���
     if log(b)a > d => O(N^log(b)a)
     if log(b)a = d => O(N^d *logN)
     if log(b)a < d => O(N^d)
     ע�� ����ݹ�Ĺ�ģ����һ��������master��ʽʧЧ��
  ����һ����ģ��1/3;һ����2/3;
     �����㷨��ʱ�临�Ӷȣ�a = 2;b = 2;d = 0;����ʱ�临�Ӷ�ΪO(N)
*/
int process(int arr[] ,int L,int R){
    if (L ==  R) {//base case;
        return arr[L];
    }
    int mid = (L+R)/2;
    int LeftMax = process(arr, L, mid);
    int RightMax = process(arr, mid+1 , R);
    return (LeftMax /RightMax)?LeftMax  : RightMax;
}

int getMaxInArray(int arr[],int length){
    return process(arr , 0 , length-1);
}
-------------------------------------�����ķָ���-------------------------------------
(12)�Ƚ���

/*
�������併��Ƚ���
     �Ƚ���ʹ�õ�ʱ�� ����javaһ����c++�еıȽ���Ҫע�ⷵ��ֵҪΪbool���ͣ�
  ��java�еķ���ֵ����Ϊint���ͣ�����������������ж���һ��������
     �Ƚ�����һ�αȽ���ɺ���һ���ڱȽϵ�ʱ���ǻẬ�е�һ�ε��źŵ�˳��
  ��������c++��sort�����������ȶ���.
*/
//�Ƚ����Ľṹ��
struct student{
    char name[10];
    int age;
    int classId;
};
//������������Ƚ���
bool compareSmallAge(student s1,student s2){
    //���ﷵ��false��ʱ���൱�ڽ�����һ����������
    return s2.age > s1.age;
}
//���հ༶����Ƚ���
bool compareSmallClassId(student s1, student s2){
    return s2.classId > s1.classId;
}
void testComparator(){
    
    student s1 =  {"opooc",21,100};
    student s2 =  {"cat",30,105};
    student s3 =  {"dog",1,107};
    student s4 =  {"daolao",2,107};
    student s5 =  {"dst",20,103};
    student allStudent[] ={s1,s2,s3,s4,s5};
    sort(allStudent, allStudent+5, compareSmallAge);
    //���水�����������Ľ���������������İ༶���������ֳ���
    sort(allStudent, allStudent+5, compareSmallClassId);    
}
-------------------------------------�����ķָ���-------------------------------------
(13)vector����

        //����һ��һά����
        vector<int> v;
        //����һ����ά���飬����ÿ��һά�����СΪ10(����)
        vector<vector<int>> v1[10];
        //���Ԫ��
        v.push_back(1);
        //ɾ�������ӵ�Ԫ��
        v.pop_back();
        //ɾ�������е�����ָ��Ԫ��
        v.erase(v.begin()+1);
        //ɾ��������[first,last)��Ԫ�� ����ɾ��1234λ��
        v.erase(v.begin()+1,v.begin()+5);
        //�ڵ����Ԫ��ǰ���1
        v.insert(v.begin(),1);
        //�ڵڶ���Ԫ��ǰ��2
        v.insert(v.begin()+2,2);
        //�����һ��Ԫ�غ�����10
        v.insert(v.end(),10);
        //Ԫ�صĸ���
        v.size();
        //�������Ԫ��
        v.clear();
        //������������
        vector<int>:: iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout<< *it;
        }
-------------------------------------�����ķָ���-------------------------------------
###ð������
1���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2����ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԣ�����������Ԫ��Ӧ�û�����������
3��������е�Ԫ���ظ����ϵĲ��裬�������һ����
4���ظ�����1~3��ֱ��������ɡ�
* A����ƽ��ʱ�临�Ӷ�
* B�����ʱ�临�Ӷ�
* E�������ʱ�临�Ӷ�
* ʡ����O()
###��ð������
for (int i = 1 ; i<length; i++) {//n������ֻ��Ҫð��n-1�������Դ�1��ʼ
        for (int j = 0 ; j<length - i; j++) {//j<length-1����Ϊð�ݹ���Ҫȥ��������ð�ݵ�һ����ֻ�ñȽ�length-1��������
            if(arr[j]>arr[j+1]){//ǰһ���Ⱥ�һ���󣬽���
                exchangee(arr, j, j+1);
            }
        }
    }


####���ѭ���Ż�ð������
(��������; ʱ��A:N^2 , B:N^2 , E:N; �ռ�1; �ȶ�)
/*
�����һ��flag���ж�һ�£���ǰ�����Ƿ��Ѿ�����,������˳�ѭ�����������ð����������ܡ�
*/
    for (int i = 1; i<length; i++) {//n������ֻ��Ҫð��n-1�������Դ�1��ʼ
        bool flag = true;//��ʼ��ǵ�ǰ�����Ѿ����򣬷����ʼ��
        for (int j = 0; j < length -i; j++) {
            if (arr[j]>arr[j+1]) {
                exchangee(arr, j, j+1);
                flag  =false;//��ǰ�ֽ����˾��趨flagΪ����
            }
        }
        if (flag) {//ֱ��ĳһ�֣�ȫ��������ôflag�Ͳ��ᱻ����Ϊfalse����ʱ�Ϳ�������
            break;
        }
    }

####�ڲ�ѭ���Ż�ð������
(��������; ʱ��A:N^2 , B:N^2 , E:N ; �ռ�1 ; �ȶ���
/*
    (1)����ð��
    (2)����last���һ�����һ����������������
       �´ο��Լ���ѭ�����������е�һ���ڲ�ѭ���Ŀ��������������ó�����
*/
-------------------------------------�����ķָ���-------------------------------------
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

-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
###ϣ������

ʵ���߼�:��һ��ͻ��O(n2)�������㷨���Ǽ򵥲�������ĸĽ��档�����������Ĳ�֮ͬ�����ڣ��������ȱȽϾ����Զ��Ԫ�ء�ϣ�������ֽ���С��������

�Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ������򣬾����㷨���̣�
ѡ��һ���ݼ�����������t1��t2������tk������ti>tj��tk=1��
���������и���k�������н���k ������
ÿ�����򣬸��ݶ�Ӧ������ti�����������зָ�����ɳ���Ϊm �������У��ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ1 ʱ������������Ϊһ�������������ȼ�Ϊ�������еĳ��ȡ�
/*
    (�ֳ���С��������)
    ͨ��ʵ�飬���������ֳ���ƽ��ʱ�临�Ӷ�ΪN^1.3
*/
    int gap = length;//��ʼ����ֵΪlength
    while (gap>1){
        gap = gap/3 +1;//�ݼ����������У�ÿ�ζԱȶ������������ľ�����бȽ�
        for (int i = gap; i<length; i+=gap) {//��ͷ��β���Ե�ǰ�����ļ��ȥ����
            int current = arr[i];//��ǰֵ
            int preIndex = i - gap;//ǰ���ֵ
            while (preIndex >= 0 && arr[preIndex]>current) {//�Ӻ���ǰ��
                arr[i]  = arr[preIndex];//�����ǰֵcurrent��ǰ���ֵarr[preIndexС
                preIndex -= gap;//�±�����Ǹ��������Ĵ�С����ôÿһλ���ƶ���ֵ
            }
            arr[preIndex+gap] = current;//���ѵ�ǰֵ��ֵ���ƶ�����±����һ��
        }
    }
-------------------------------------�����ķָ���-------------------------------------
###ѡ������
�㷨����:

������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�ã�
Ȼ���ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
�Դ����ƣ�ֱ������Ԫ�ؾ�������ϡ�

(ѡ������;ʱ��A:N^2 , B:N^2 , E:N^2 ; �ռ�1;�ȶ�)

    for(int i =0 ;i<length-1;i++)//ѡ������ֻ��n-1�֣���������n������
    {   int minIndex =i;//�趨��ʼ����Сֵ���±�minIndex
        for(int j= i+1;j<length;j++){//��i+1��ʼ�������ҳ���С���±꣬��ֵ����־λminIndex
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        exchangee(arr, minIndex, i);
    }
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
###8����������
�㷨����:

���������ǻ��ڱȽϵ������㷨����������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ��С�
��Ϊһ������ʱ�临�Ӷȵ����򣬼�������Ҫ����������ݱ�������ȷ����Χ��������

ʵ���߼�:
�ҳ��������������������С��Ԫ�أ�
ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i�
�����еļ����ۼ�(��Ͱ�еĵ�0��Ԫ�ؿ�ʼ��ÿһ���ǰһ�����);
�������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)��,
ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1����Ϊ�˱�֤�㷨���ȶ��ԡ�


(��������;ʱ��A:N+k,B:N+k,E:N+k;�ռ�N+k;�ȶ�)

/*    
�����Ԫ���� n �� 0�� k ֮�������
��k���Ǻܴ������бȽϼ���ʱ������������һ������Ч�������㷨��
�����㷨������������е���Сֵ���ڵ���0����������Ը���������ġ�    
  */

void countSort(int arr[] ,int length){
    int max = arr[0];//�ȳ�ʼ��һ��max���Ϊ����������ΪҪ��Χ
    int lastIndex=  0;
    for (int i = 1; i<length; i++) {
        max = arr[i]>max ? arr[i]:max;//��ʼ��max��0�±꣬��˴�1��ʼ���������ĸ�ֵ��max
    }
    int* sortArr  = new int[max+1]();//����һ���������飬��������
    for (int j = 0; j< length; j++) {
        sortArr[arr[j]]++;//����ԭ���飬������ֵ��ϣ��keyΪԭ�������ֵ��valueΪ��ֵ���ֵĴ���
    }
    for (int k = 0; k<max+1; k++) {//����������������
        while (sortArr[k]>0) {//������ֵ�ĵط�����ʱ�±����ԭ�����ֵ
            arr[lastIndex++] = k;//��ԭ�����±�++��ֵ��ȥ���ж���Ͷ�θ�ֵ��������while
            sortArr[k]--;//��ֵһ����������--
        }
    }
}
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------
�鲢����汾2��
#include<iostream>
using namespace std;

vector<int> mergeHelper(vector<int> &a, int left , int right){
	if(left == right){
		return vector<int> (1, a[left]);
	}
	int mid = left + (left + right) / 2;
	vector<int> l = mergeHelper(a, left, mid);
	vector<int> r = mergeHelper(a, mid + 1, right);
	//merge
	vector<int> tmp;
	int ll = 0, rr = 0;
	while(ll < l.size() && rr < r.size()){
		if(l[ll] < r[rr]){
			tmp.push_back(l[ll++]);
		}
		else{
			tmp.push_back(r[rr++]);
		}
	}
	while(ll < l.size()){
		tmp.push_back(l[ll++]);
	}
	while(rr < r.size()){
		tmp.push_back(r[rr++]);
	}
	return tmp;
}

void mergeSort(vector<int> &a){
	a = mergeHelper(a, 0,a.size() - 1);
}

int main(){
    int arr[9]={99,11,72,62,53,4,44,21,14};
    int length = len(arr);
    quickSort(arr,length);
return 0;
}
-------------------------------------�����ķָ���-------------------------------------
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
-------------------------------------�����ķָ���-------------------------------------

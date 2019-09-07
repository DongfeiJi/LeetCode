/*
十大经典排序算法可以分为两大类：
0、非线性时间排序：通过比较来决定元素间的相对次序。时间复杂度最快为O(logN)
1、线性时间排序：通过创建有序的空间，将元素按照一定的规则放入有序空间，再依次取出。以空间来换取时间，可以突破O(logN)

非线性时间排序：比较排序/冒泡排序/快速排序/插入排序/插入排序/希尔排序/选择排序/选择排序/堆排序/归并排序/二路归并排序/多路归并排序
线性时间排序：计数排序/堆排序/基数排序

稳定的排序：
不稳定的排序：

*/
-------------------------------------华丽的分割线-------------------------------------
(1)求数组长度（需要传数组，不要传数组指针）

/*    这里的注意点：在计算数组大小的时候，
   一定要注意传入的数组是否为数组指针，
   如果传入的是数组指针，sizeof后出来的值为8(64位下)，应注意。
*/
template <class T>
int len(T& arr){   
    int length = (int)sizeof(arr)/sizeof(arr[0]);
    return length;
}
-------------------------------------华丽的分割线-------------------------------------
(2)交换数组两个数

void exchangee(int arr[],int a, int b){
/*   ^符号 即”异或“运算符，特点是与0异或，
  保持原值；与本身异或，结果为0。
     这里可以使用位运算，交换时不用开辟额外空间。
  但是如果传入的'位置相同'的两个数，就不能在此函数中进行交换。
  因为，自己跟自己异或后结果一定为0,就没有什么意义了。
//    arr[a] = arr[a] ^ arr[b];
//    arr[b] = arr[a] ^ arr[b];
//    arr[a] = arr[a] ^ arr[b];
*/    
    int temp = arr[a];
    arr[a] =  arr[b];
    arr[b] = temp;
}
-------------------------------------华丽的分割线-------------------------------------
(3)大数据样本下四种最快算法的比较
     /*
     数据是随机整数，时间单位是秒
     数据规模|快速排序 归并排序 希尔排序 堆排序
     1000万 |  0.75  1.22    1.77    3.57
     5000万 |  3.78  6.29    9.48    26.54
     1亿    |  7.65  13.06   18.79   61.31
     */ 
-------------------------------------华丽的分割线-------------------------------------
(4)时间复杂度的大小比较
     /*
     N!> x^N >...>3^N >2^N > N^x>...>N^3 >N^2>NlogN>N>logN>1
     */
-------------------------------------华丽的分割线-------------------------------------
(5)数组和数组大小的结构体
struct arrAndSize{
    int *array;
    int size;
};
-------------------------------------华丽的分割线-------------------------------------
(6)初始化数组
    //一维 每个元素都没有初始化
    int *p = new int[10];
    //一维 每个元素初始化为0
    int *p = new int[10](0);
    //二维 每个元素都没有初始化
    int (*bucket)[10] = new int[10][10];
    //二维 每个一维中含N个数，N为确定的数值。
    vector<vector<int>> bucket(N);
    //通过动态创建的数组，要进行内存释放，否则内存将泄漏
    //(本文中，未进行内存释放)
    delete []p;
-------------------------------------华丽的分割线-------------------------------------
(7)综合排序总结

思考一个排序时候，考虑时间复杂度中的指标和常数项，空间复杂度，稳定性.
代码规模，一定程度上说明了常数项的大小。（最终常数项的大小是看发生常数操作的次数）
系统的sort 方法，发现传进来的值为数值型，会使用快排，如果发现传的还有比较器，会使用归并排序
归并和快排哪种更快？
快排比归并排序的常数项要低，所以要快。
为什么会有归并和快排两种呢？
在比较的时候，使用比较器的时候，要追求一个稳定性，使用归并排序可以达稳定性的效果；使用快排不能够实现稳定性的效果。
面对大规模的时候，当排序量是小于等于60的时候，sort方法 会在内部使用插入排序的方法（不一定是60，是一定的规模）当数据量很低的时候，插入排序的常数项低。
在c语言中有一版，把归并排序，改成非递归，是基于工程其他考虑。
-------------------------------------华丽的分割线-------------------------------------
(8)对比两个数组是否相同

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
            //可以在此位置，打印错误项
            //也可以打印整个数组查看错误项
            return false;
        }
    }
    return true;
}
-------------------------------------华丽的分割线-------------------------------------
(9)复制数组

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
-------------------------------------华丽的分割线-------------------------------------
(10)产生随机数组

arrAndSize generateRandomArr(int maxSize,int maxValue){
//    int arrrr =rand()%10;
    arrAndSize aAndS;
    int size = (int)((maxSize+1) * (rand()%10/(double)10));
    cout<<"{"<<size<<"}";
    
    int* array = new int[size];
    for(int i =0 ;i < size;i++){
        // 随机生成[-N,N];
//        array[i] = (int)((maxValue +1) * (rand()%100)/(double)100) - (int)((maxValue + 1) * (rand()%100/(double)100));
        //随机生成[0,N];
         array[i] = (int)((maxValue +1) * (rand()%10)/(double)10);
        //打印到底生成了什么。
//cout<<i<<"===="<<array[i] <<"|";
    }
//    cout<<"+++++"<<endl;
    aAndS.size = size;
    aAndS.array = array;
    return aAndS;
}
-------------------------------------华丽的分割线-------------------------------------
(11)疯狂递归 -递归master公式


/*
     递归master公式
     T(N)的公式从大规模来看，不细分。
     T(N) = a * T(N/b)+O(n^d)
     N/b 是子过程数据量 ；a是子过程调用多少次；O(n^d)是出去
 过程之外剩下的数据量的多少
     if log(b)a > d => O(N^log(b)a)
     if log(b)a = d => O(N^d *logN)
     if log(b)a < d => O(N^d)
     注意 多个递归的规模必须一样，否则master公式失效。
  例如一个规模是1/3;一个是2/3;
     以下算法的时间复杂度：a = 2;b = 2;d = 0;所以时间复杂度为O(N)
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
-------------------------------------华丽的分割线-------------------------------------
(12)比较器

/*
按照年龄降序比较器
     比较器使用的时候 不和java一样，c++中的比较器要注意返回值要为bool类型，
  而java中的返回值可以为int类型，根据两数相减进行判断下一步的排序。
     比较器第一次比较完成后，下一次在比较的时候还是会含有第一次的排号的顺序，
  是利用了c++中sort函数的排序稳定性.
*/
//比较器的结构体
struct student{
    char name[10];
    int age;
    int classId;
};
//按照年龄升序比较器
bool compareSmallAge(student s1,student s2){
    //这里返回false的时候，相当于进行了一个交换操作
    return s2.age > s1.age;
}
//按照班级升序比较器
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
    //上面按照年龄升序后的结果，会继续在下面的班级降序中体现出来
    sort(allStudent, allStudent+5, compareSmallClassId);    
}
-------------------------------------华丽的分割线-------------------------------------
(13)vector容器

        //声明一个一维容器
        vector<int> v;
        //声明一个二维数组，里面每个一维数组大小为10(必填)
        vector<vector<int>> v1[10];
        //添加元素
        v.push_back(1);
        //删除最后添加的元素
        v.pop_back();
        //删除向量中迭代器指向元素
        v.erase(v.begin()+1);
        //删除向量中[first,last)中元素 如下删除1234位置
        v.erase(v.begin()+1,v.begin()+5);
        //在第零个元素前面插1
        v.insert(v.begin(),1);
        //在第二个元素前插2
        v.insert(v.begin()+2,2);
        //在最后一个元素后面插的10
        v.insert(v.end(),10);
        //元素的个数
        v.size();
        //清除所有元素
        v.clear();
        //遍历整个数组
        vector<int>:: iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout<< *it;
        }
-------------------------------------华丽的分割线-------------------------------------
###冒泡排序：
1，比较相邻的元素。如果第一个比第二个大，就交换它们两个；
2，对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
3，针对所有的元素重复以上的步骤，除了最后一个；
4，重复步骤1~3，直到排序完成。
* A代表平均时间复杂度
* B代表最坏时间复杂度
* E代表最好时间复杂度
* 省略了O()
###简单冒泡排序
for (int i = 1 ; i<length; i++) {//n个数，只需要冒泡n-1个，所以从1开始
        for (int j = 0 ; j<length - i; j++) {//j<length-1是因为冒泡过的要去掉，比如冒泡第一个，只用比较length-1个数即可
            if(arr[j]>arr[j+1]){//前一个比后一个大，交换
                exchangee(arr, j, j+1);
            }
        }
    }


####外层循环优化冒泡排序
(交换排序; 时间A:N^2 , B:N^2 , E:N; 空间1; 稳定)
/*
如果用一个flag来判断一下，当前数组是否已经有序,有序就退出循环，可以提高冒泡排序的性能。
*/
    for (int i = 1; i<length; i++) {//n个数，只需要冒泡n-1个，所以从1开始
        bool flag = true;//初始标记当前数组已经有序，反向初始化
        for (int j = 0; j < length -i; j++) {
            if (arr[j]>arr[j+1]) {
                exchangee(arr, j, j+1);
                flag  =false;//当前轮交换了就设定flag为无序
            }
        }
        if (flag) {//直到某一轮，全部有序，那么flag就不会被设置为false，此时就可以跳出
            break;
        }
    }

####内层循环优化冒泡排序
(交换排序; 时间A:N^2 , B:N^2 , E:N ; 空间1 ; 稳定）
/*
    (1)完美冒泡
    (2)再用last标记一下最后一个发生交换的数，
       下次可以减少循环次数。其中第一次内部循环的控制条件，单独拿出来。
*/
-------------------------------------华丽的分割线-------------------------------------
###快速排序：
实现逻辑:

快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法流程如下：
从数列中挑出一个元素，称为 “基准”（pivot）；
重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

####随机快速排序

（交换排序;时间A:NlogN,B:NlogN,E:NlogN;空间logN;不稳定）

/*
    (1)in-place原地算法可以实现 把以划分值为标准，
       小于等于划分值的放左边并推着大于划分值的数向右走。
       时间复杂度O(N)空间复杂度是O（1）
    (2)（荷兰国旗问题）在实现把等于划分值的放中间，小于
        划分值的放左边，大于划分值的放右边且时间复杂度O(N)
        空间复杂度仍未O(1)的时候。1.当前数<p左区下一个
        交换，左区扩，检测下一个。2、当前数等于p，检测下
        一个。3、当前数大于p，和右区前一个位置换，右区扩。
        继续检测当前换完的数。
    (3) 其中的空间复杂度是不得不使用的空间，用来记录每次的左右边界。
    (4)快速排序可以做到稳定，但是非常难，可以搜 0-1stable sort论文。
*/
int* separate(int arr[],int left,int right){//这就是partition过程，left相当于当前值下标，right其实就是基准
    int first  = left -1;//小于区在最左边-1
    int Second = right;//大于区在最右侧，并且取当前基准就是arr[right]
    while (left < Second) {//当左小于右下标，这里不用等于，因为等于的时候就不用判断了
        if(arr[left]<arr[right]){//如果当前值小于基准
            exchangee(arr, ++first, left++);//扩小于区，将小于区下一个与其交换++first，检测下一个left++
        }else if(arr[left]>arr[right]){//如果当前值大于基准
            exchangee(arr, --Second, left);//扩大大于区--second，将当前值left与其交换，所以说此时这个快排，right下标一直没动过
        }else if(arr[left]==arr[right]){//如果相等，判断下一个left++
            left++;
        }
    }
    exchangee(arr, Second, right);//因为right前面都当的是基准，没变过，所以将大于区第一个second与right交换
    int firstAndSecond[2] = {first+1,Second};//将小于区和大于区边界保存到数组里面返回

    return firstAndSecond;
}

void quickSort(int arr[],int left, int right){//随机快排过程，给定左右区间
    if (left<right) {//如果左小于右，判断非法输入
        int randomC = (int)((rand()%100/(double)100) * (right - left +1));//这是随机选取一个基准
        exchangee(arr,left+ randomC, right);//将给值换到最后面
        int* curArr  = separate(arr, left, right);//调用partition过程返回小于区和大于区边界
        quickSort(arr, left,curArr[0] -1 );//递归快排左
        quickSort(arr, curArr[1]+1, right);//递归快排右
    }
}
void quickSort(int arr[],int length){//随机快排，给定长度，全排列，封装，也可以用上面的调用，最好是下面这个
    if (length < 2) {
        return;//非法输入
    }
    quickSort(arr,0,length-1);//直接快排
}
int main(){
    int arr[9]={99,11,72,62,53,4,44,21,14};
    int length = len(arr);
    quickSort(arr,length);
return 0;
}

-------------------------------------华丽的分割线-------------------------------------
####快排里面的小和问题：
问题描述：
求小和问题：在随机元素，随机数组大小的数组中，找出左边比右边元素小的所有元素之和。
例如：数组[4,2,5,1,7,3,6] 第一个元素4比2大，不算小和，5比4和2都大，那就是4+2=6；1比4和2和5都小，不算小和；7比前面的都大，那就是上次小和6+4+2+5+1=18；然后3前面比2和1大，那就是18+2+1=21；最后6比4、2、5、1、3都大，结果就是21+4+2+5+1+3=36。那么最后的结果就是36。

//小和问题
int allSum(int arr[],int L,int mid,int R){//这是L-mid为左区，mid+1-R为右区，求左区对应于右区的全部小和

    int *help = new int(R-L+1);//辅助数组，因为只关注partition一边分析
    int i = 0 ;//初始下标
    int pFirst = L;//左区遍历下标
    int pSecond = mid + 1;//右区遍历下标
    int sum = 0;//左区对应于右区的全部小和

    while (pFirst <=mid && pSecond <=R) {
        /*
        在左右两个区有谁小谁移动的原则，看小和问题和逆序对问题时，要抓住一边分析。 
        小和问题，因为要统计左区小于右区的数的数量，既统计左区比右区小的数，因为在排序的时候，左区可能会移动，
        故左区在移动后，无法在下一步查看右区大于的数，所以要一次性把针对左区当前数大的数全部记录下来
        逆序对问题，则需要一个一个记录左区比右区大的数，并且要调整为从大到小排序!!）
        */
        sum += arr[pFirst] < arr[pSecond] ? arr[pFirst]*(R-pSecond+1):0;//左区对应右区的全部小和
        help[i++]  = arr[pFirst] < arr[pSecond] ? arr[pFirst++]:arr[pSecond++];//通过使help中保存的是计算过小和的有序数组，让pFirst和pSecond分别++
    }
    while (pFirst <= mid ) {
        help[i++] = arr[pFirst++];//左区有剩余
    }
    while (pSecond <= R) {
        help[i++] = arr[pSecond++];//右区有剩余
    }
	//此时help为计算过左侧对应于右侧全部的小和
    for (int k = 0; k < (R-L+1); k++) {
        arr[L+k] = help[k];//赋值回去给arr，此时arr只计算了左区对应于右区的全部小和，但左右并不一定是完全有序的
    }
    return sum;
}


int smallSum(int arr[],int L,int R){//递归计算全部小和，等于左小和+右小和+左对于右的小和
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
    if(arr == nullptr || length <2){//非法输入
        return 0;
    }
    return smallSum(arr,0,length -1);//求解
}
-------------------------------------华丽的分割线-------------------------------------
###插入排序
算法描述:

实现逻辑:
一般来说，插入排序都采用in-place在数组上实现。具体算法流程如下：
从第一个元素开始，该元素可以认为已经被排序；
取出下一个元素，在已经排序的元素序列中从后向前扫描；
如果该元素（已排序）大于新元素，将该元素移到下一位置；
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
将新元素插入到该位置后；
重复步骤2~5。

####插入排序

(插入排序;时间A:N^2 , B:N^2 , E:N;空间1;稳定)

    //方法一、在对比的时候不交换；
    for (int i =1; i < length;i++ ) {
        int current = arr[i];
        int preIndex = i-1;
        while (preIndex >= 0&& arr[preIndex]>current) {
            /*
            可以直接交换。因为current记录了最后一个值，
            所以这里使用向后移动思想。
            exchangee(arr, preIndex, current);
            */
            arr[preIndex+1] = arr[preIndex];
            preIndex --;
        }
        arr[preIndex+1] = current;
    }
     //方法二、在对比的时候进行交换；
    for(int i = 1 ; i<length ;i++){
        for (int j = i - 1; j>=0 && arr[j]>arr[j+1]; j--) {
            exchangee(arr, j, j+1);
        }
    }
-------------------------------------华丽的分割线-------------------------------------
###希尔排序

实现逻辑:第一个突破O(n2)的排序算法，是简单插入排序的改进版。它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。

先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法流程：
选择一个递减的增量序列t1，t2，…，tk，其中ti>tj，tk=1；
按增量序列个数k，对序列进行k 趟排序；
每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
/*
    (又称缩小增量排序)
    通过实验，大量本表现出，平均时间复杂度为N^1.3
*/
    int gap = length;//初始增量值为length
    while (gap>1){
        gap = gap/3 +1;//递减的增量序列，每次对比都是跳过增量的距离进行比较
        for (int i = gap; i<length; i+=gap) {//从头到尾，以当前增量的间隔去遍历
            int current = arr[i];//当前值
            int preIndex = i - gap;//前面的值
            while (preIndex >= 0 && arr[preIndex]>current) {//从后向前比
                arr[i]  = arr[preIndex];//如果当前值current比前面的值arr[preIndex小
                preIndex -= gap;//下标迭代是根据增量的大小，那么每一位都移动赋值
            }
            arr[preIndex+gap] = current;//最后把当前值赋值给移动后的下标的下一个
        }
    }
-------------------------------------华丽的分割线-------------------------------------
###选择排序
算法描述:

首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。

(选择排序;时间A:N^2 , B:N^2 , E:N^2 ; 空间1;稳定)

    for(int i =0 ;i<length-1;i++)//选择排序只需n-1轮，即可排序n个数字
    {   int minIndex =i;//设定初始化最小值的下标minIndex
        for(int j= i+1;j<length;j++){//从i+1开始遍历，找出最小的下标，赋值给标志位minIndex
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        exchangee(arr, minIndex, i);
    }
-------------------------------------华丽的分割线-------------------------------------
###堆排序
算法描述:利用最大堆实现，包括插入建堆heapInsert以及剪枝后调整heapify两个操作
排序就是先建堆，然后不断将最大堆和最小值交换之后剪枝，再调成大根堆，这就可以不断找出最大值，如此反复


(选择排序;时间A:NlogN,B:NlogN,E:NlogN;空间1;不稳定)

/*
        堆的概念：对于大根堆，其子树下的所有节点,包括它自己在内的最大值为头结点。
        时间复杂度为0+log1+log2+……数学上可以证明
        这个值收敛于O(N)
*/
//建堆插入，向上过程
void heapInsert(int arr[],int index){
    while (arr[index] > arr[(index-1)/2]) {
        exchangee(arr,index, (index-1)/2);
        index = (index -1)/2;
    }
}
//剪枝后调整，向下过程
//size为最右的边界，size是取不到的.
void heapify(int arr[],int index ,int size){//传入的是arr大根堆数组，index为当前父结点，size是调整的距离，取不到size
    int leftChild = index*2 + 1;//左孩子下标
    while (leftChild < size) {//不越界
        int maxChild = leftChild + 1 < size && arr[leftChild+1] >arr[leftChild] ? leftChild+1 : leftChild;//右孩子不越界，将左孩子与右孩子谁大将谁赋值给maxChild
        int maxAll = arr[maxChild] > arr[index] ? maxChild: index;//将父节点和maxChild进行对比，最大的赋值给maxAll
        if (maxAll  == index) {//如果就是自身，break
            break;
        }
        exchangee(arr, maxAll, index);//将父节点与最大的孩子交换
        index = maxAll;//父节点迭代到子结点
        leftChild = index*2 +1;//子节点重新迭代
    }
}   
int main(){
    for(int i = 0;i <length;i++){
        heapInsert(arr, i);//建堆
    }
    int size = length;
    exchangee(arr, 0, --size);//将大根堆最大的父节点0下标，与最右侧的结点交换，注意大根堆每次排序好一个，size也会变小
    while (size > 0){//满足限制
        //heapify时间复杂度为O(logN)
        heapify(arr, 0, size);//交换一个就调整
        exchangee(arr, 0, --size);//迭代交换，--size。反复迭代
    }
    
    return 0;
}    
-------------------------------------华丽的分割线-------------------------------------
###归并排序
实现逻辑:

把长度为n的输入序列分成两个长度为n/2的子序列；
对这两个子序列分别采用归并排序；
将两个排序好的子序列合并成一个最终的排序序列。

####二路归并排序
(插入排序;时间A:NlogN,B:NlogN,E:N*logN;空间N;稳定)

/*
    归并排序内部缓存法 可以把空间复杂度降到O(1)；
    归并排序原地归并法 也可以把空间复杂度降到O(1)但是时间复杂度会变成O(N^2)
*/
void merge(int arr[],int L,int M,int R){
    int* cent = new int[R - L + 1];//辅助数组
    int i = 0;//初始化下标
    int pFirst = L;//左部分起始下标
    int pSecond = M+1;//右部分起始下标
    while (pFirst <= M && pSecond <= R) {
        cent[i++] = arr[pFirst] < arr[pSecond] ? arr[pFirst++]:arr[pSecond++];//小的赋值给辅助数组，下标++
    }
    while (pFirst <= M) {
        cent[i++] = arr[pFirst++];//左有剩余
    }
    while (pSecond <= R) {
        cent[i++] = arr[pSecond++];//右有剩余
    }
    for (int j = 0; j < (R-L+1); j++) {
        arr[L+j] = cent[j];//拷贝回去
    }
    
}
void mergeSort(int arr[],int L,int R){
    if (L == R){
        return;
    }
    int mid = (L+R)/2;
    mergeSort(arr, L, mid);//递归左
    mergeSort(arr, mid+1, R);//递归右
    merge(arr,L,mid,R);//合并左和右
}
void mergeSort(int array[],int length){
    if (array == nullptr || length<2) {
        return;
    }
    mergeSort(array,0,length - 1);
}
-------------------------------------华丽的分割线-------------------------------------
###8、计数排序
算法描述:

计数排序不是基于比较的排序算法，其核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。

实现逻辑:
找出待排序的数组中最大和最小的元素；
统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
对所有的计数累加(从桶中的第0个元素开始，每一项和前一项相加);
反向填充目标数组：将每个元素i放在新数组的第C(i)项,
每放一个元素就将C(i)减去1，是为了保证算法的稳定性。


(计数排序;时间A:N+k,B:N+k,E:N+k;空间N+k;稳定)

/*    
输入的元素是 n 个 0到 k 之间的整数
当k不是很大并且序列比较集中时，计数排序是一个很有效的排序算法。
下面算法是输入的数组中的最小值大于等于0的情况，可以根据需求更改。    
  */

void countSort(int arr[] ,int length){
    int max = arr[0];//先初始化一个max标记为最大的数，因为要求范围
    int lastIndex=  0;
    for (int i = 1; i<length; i++) {
        max = arr[i]>max ? arr[i]:max;//初始化max是0下标，因此从1开始遍历，最大的赋值给max
    }
    int* sortArr  = new int[max+1]();//声明一个辅助数组，用来计数
    for (int j = 0; j< length; j++) {
        sortArr[arr[j]]++;//遍历原数组，构成数值哈希，key为原数组的数值，value为该值出现的次数
    }
    for (int k = 0; k<max+1; k++) {//遍历计数辅助数组
        while (sortArr[k]>0) {//凡是有值的地方，此时下标就是原数组的值
            arr[lastIndex++] = k;//将原数组下标++赋值回去，有多个就多次赋值，所以用while
            sortArr[k]--;//赋值一个，次数就--
        }
    }
}
-------------------------------------华丽的分割线-------------------------------------
###9、桶排序
算法描述:

桶排序是计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。
桶排序 (Bucket sort)的工作的原理：假设输入数据服从均匀分布，将数据分到有限数量的桶里，每个桶再分别排序
（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排）。

实现逻辑:
设置一个定量的数组当作空桶；遍历输入数据，并且把数据一个一个放到对应的桶里去；
对每个不是空的桶进行排序；
从不是空的桶里把排好序的数据拼接起来。

桶排序(时间A:N+k,B:N^2,E:N+k;空间N+k;稳定)
//桶排序是: 桶思想排序 + 一个普通的排序（常用快速排序）


/*
 映射函数getGroupCount是得到在第几个桶，其能保证第一个桶有整个数组的最小值和最后一个桶有整个数组的最大值。
 size为一个桶的囊括的数的范围
*/
int getGroupCount(long num,long size ,long min ,long max ){//这是计算某值应该在第几个桶
    int count = (int)((size)*(num - min)/(max - min));//桶大小*当前值与最小值的差/最大值与最小值的差
    return count;//这就是输入num以及桶大小size，最大值与最小值，即可返回num在第几个桶，要保证桶也是有序的
}

void bucketSort(int arr[],int length,int size){//桶排，输入包括数组，数组长度，桶大小
    if (length < 2 ){
        return;
    }
    int len = length;
    //拿到最大最小值
    long min = arr[0];
    long max = arr[0];
    for (int i = 1 ; i<len; i++) {
        min = arr[i] < min ? arr[i]: min;
        max = arr[i] > max ? arr[i]: max;
    }
    //如果最小值等于最大值说明数组中就一种数
    if (min == max) {
        return;
    }
    //创建桶
    int bucketCount = (int)((max -min)/size +1);//桶的数量根据最大值减去最小值再除以size+1
    vector<vector<int>> bucket(bucketCount);//创建数组，一共有bucketCount个
    int bid = 0;//定义一个桶的下标，因为要往桶里面放东西了，要计算当前数num放在第几个桶
    //把数组中的数 扔进桶里
    for (int i =0;  i < len; i++) {
        bid = getGroupCount(arr[i], bucketCount, min, max);
        bucket[bid].push_back(arr[i]);
    }
	/*这段代码是对每个桶都进行排序，好像有问题
    for (int i=0; i< bucketCount; i++) {
        //对桶内进行插入排序。按照升序，这样可以保证从下往上读的稳定性
        for (int j = 1; j<bucket[i].size(); j++) {
            if  (bucket[i][j] < bucket[i][j-1]) {
                swap(bucket[i][j],bucket[i][j-1]);//？？？？？？？？？？？？？这个插入排序不对吧，少了一层
            }
        }		 
    }
	*/
    //修改版本，插入排序，对每个桶进行排序
	for (int i=0; i< bucketCount; i++) {
        //对桶内进行插入排序。按照升序，这样可以保证从下往上读的稳定性
        for (int j = 1; j<bucket[i].size(); j++) {
            for (int k = j - 1; k >= 0 && bucket[i][k] > bucket[i][k+1]; k--) {
                swap(bucket[i][k],bucket[i][k+1]);
            }
        }	
        /*打印桶中的数
        for (int t = 0; t< bucket[i].size(); t++) {
            cout<<bucket[i][t]<<' ';
        }
		*/   		
    }

    //    int *newArr = new int[len];
    int index = 0;
    for (int i =0 ;i<bucketCount ;i++){//这就是将所有桶中的数倒回数组
        for (int j =0; j<bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }    
}
-------------------------------------华丽的分割线-------------------------------------
####桶排序思想：数组最大值问题
问题描述

数组最大值问题。
给定一个无序数组，求如果排序之后，相邻两数的最大差值，
要求时间复杂度O（N），且要求不能用基于比较的排序。
以此题发现桶排序妙趣思想.

/*
     映射函数getGroupCount是得到在第几个桶，其能保证第一
  个桶有整个数组的最小值和最后一个桶有整个数组的最大值。
*/
int getGroupCount(long num,long size ,long min ,long max ){//计算当前num在第几个桶
    int count = (int)((size-1)*(num - min)/(max - min));
    return count;
}

int maxGroup(int arr[],int length){//注意这里没传size
    if (length < 2){
        return 0;//非法输入
    }
    int len = length;
    //拿到系统的最大值和系统的最小值
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i= 0; i<len; i++) {
        min = arr[i]<min ? arr[i]:min;
        max = arr[i]>max ? arr[i]:max;
    }
	//最大值和最小值相等说明该数组的值全部相同，直接return
    if (min == max){
        return 0;
    }
	//
    int bid = 0;
    int* maxValue =new int[len+1];
    int* minValue =new int[len+1];//这两个数组，每一个对应位置都相当于一个桶，所以此时就是每个桶的size为2
    bool* flag = new bool[len+1];//该桶处有值的标记数组
    for (int j = 0; j<len; j++) {//遍历原数组
        bid = getGroupCount(arr[j], len, min, max);
        minValue[bid] = minValue[bid]? (minValue[bid]<arr[j]?minValue[bid]:arr[j]):arr[j];//min桶中存的始终是较小值
        maxValue[bid] = maxValue[bid]? (maxValue[bid]>arr[j]?maxValue[bid]:arr[j]):arr[j];//max桶中存的始终是最大值
        flag[bid] = true;//这个桶存了值的标记
    }
    int res = 0;
    int lastMax = 0;//最大的值
    for (int k= 1 ; k<len+1; k++) {//遍历这些桶
        if (flag[k]) {//如果该处有值
            res = res > (minValue[k] - maxValue[lastMax]) ? res :(minValue[k] - maxValue[lastMax]);
			//由于此时桶是有序的，res始终为有序相邻的数的最大差值
            lastMax =k;//保证相邻迭代比较
        }
    }
    return res;
}
-------------------------------------华丽的分割线-------------------------------------
###10、基数排序：实质就是先比较低位放入桶，拿出去再比较高位，拿出去
算法描述:

基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集；依次类推，直到最高位。
有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。
最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。

(基数排序;时间A:N * k , B:N * k , E:N * k ; 空间N+k ; 稳定)

//拿到传入数的位数
int getRadixCount(int count){
    int num = 1;
    if (count /10 >0) {
        num ++;
    }
    return num;
}
//拿到10的传入位数的次方(10^num)，其实就是将位数转回次方
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
	//求出最大值
    int max = arr[0];
    for (int i =1 ; i< length; i++) {
        max = arr[i]>max? arr[i]:max;
    }
	//通过最大值，计算最多有多少位
    int radixCount = getRadixCount(max);
	//将多少位转换成10的次方
    int tenRadixCount = getTenRadixCount(radixCount);

    int (*bucket)[10] = new int[10][10];//new10个包含10个内存的数组作为桶，因为要保证横向和纵向的桶中都有序（可能需要调大纵向）
    int* flag = new int[10]();//new一个10个内存的数组，因为每一位只有0-9一共十个数，相当于横向基准10个位置桶的flag（次数）
    int multiplier = 1;//从个位开始
    while (multiplier < tenRadixCount) {//不越界
        for (int i = 0; i< len; i++) {
            int curCount = arr[i]/multiplier%10;//当前位的值
            int k = flag[curCount];//k其实是计算纵向排序的桶，即存在第k个位置
            bucket[curCount][k] = arr[i];//横向当前位的值的桶，纵向是出现的次数的值的桶
            flag[curCount]++;//当前位置的值数量++
        }
        int index = 0;
        for (int j = 0; j < 10; j++) {//循环这10个桶准备还原回去
            if (flag[j]!=0) {//该桶有值
                for (int k =0; k<flag[j]; k++) {//遍历纵向的桶
                    arr[index++]  =  bucket[j][k];//赋值回去
                }
            }
            //把桶清空，准备下一次循环。
            flag[j] = 0;
        }
        multiplier *= 10;//下一个高位，迭代
    }
}
-------------------------------------华丽的分割线-------------------------------------
归并排序版本2：
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
-------------------------------------华丽的分割线-------------------------------------
快排版本2;
//快排核心就是选定一个数，大于它的放在右侧。小于他的放在左侧
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
	int l = start, r = end;//大于区和小于区
	int privot = findmiddle(a[start], a[end], a[start + (end - start) / 2]);//基准
	while(l <= r){
		while(l <= r && a[r] > privot) r--;//如果右侧的当前值大于基准，不处理，就是r--
		while(l <= r && a[l] < privot) l++;//如果左侧的当前值小于基准，不处理，就是l++
		//此时就是r下标是右侧第一个小于基准的
		//l下标就是左侧第一个大于基准的
		if(l <= r) swap(arr[l++],arr[r--]);//此时交换，保证大于区小于区符合条件
	}
	quicksortHelper(a, start, r);
	quicksortHelper(a, l, end);
}


void quicksort(vector<int>& a)
{
    quicksortHelper(a, 0, a.size() - 1);
}
-------------------------------------华丽的分割线-------------------------------------

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
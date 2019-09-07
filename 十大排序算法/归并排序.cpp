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
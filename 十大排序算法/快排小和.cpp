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
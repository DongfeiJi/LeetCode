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

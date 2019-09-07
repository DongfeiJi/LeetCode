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
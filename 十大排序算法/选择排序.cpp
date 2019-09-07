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
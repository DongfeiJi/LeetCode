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
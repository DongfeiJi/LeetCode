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
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
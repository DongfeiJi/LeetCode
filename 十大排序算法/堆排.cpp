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
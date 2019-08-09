/*
利用二叉排序树解决
分析此题，由于是计算右侧小于当前元素的个数，对于树结构不好理解，因此可以反着计算，然后再求反
比如5 2 6 1，那就先把他看成1 6 2 5，对于num[i],求num[0]~num[i-1]有多少个比他小即可
由于计算的是一共有多少个比他小的，因此可以设计一个cont变量，所以构建二叉排序树数据结构，加一个count
本题算法：
设置变量count_small=0，记录插入时候，有多少元素比插入节点值小
若待插入节点值小于等于node，node->count++，递归插入左子树
若插入节点大于node，count_small+=node->count+1(插入位置左侧所有节点，其实就是node+1)，递归插入右子树
count_small其实是在插入的时候实时更新，即使小于node，但总会大于左子树的node
*/
#include <stdio.h>

#include <vector>
struct BSTNode {//构建二叉排序树数据结构，加一个count
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};//在二叉排序树基础上，插入新节点时：对于node，在待插入节点insert_node小于等于当前node时候，count++

//插入新元素的代码
void BST_insert(BSTNode *node, BSTNode *insert_node, int &count_small){
	if (insert_node->val <= node->val){//插入在左边只是更新node的count，此时一定包含=，因为求小于它
		node->count++;
		if (node->left){
			BST_insert(node->left, insert_node, count_small);
		}
		else{
			node->left = insert_node;
		}
	}
	else{//插入在右边count_small是左边所有比他小的数
		count_small += node->count + 1;
		if (node->right){
			BST_insert(node->right, insert_node, count_small);
		}
		else{
			node->right = insert_node;
		}
	}
}

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
    	std::vector<int> result;//最终逆序的结果
    	std::vector<BSTNode *> node_vec;//创建二叉树查找树节点池
    	std::vector<int> count;//从后向前插入，比当前节点小的count_small数组
    	for (int i = nums.size() - 1; i >= 0; i--){
    		node_vec.push_back(new BSTNode(nums[i]));
	    }//逆序后的二叉查找树节点
	    count.push_back(0);//初始化第一个节点的count_small=0
	    for (int i = 1; i < node_vec.size(); i++){
	    	int count_small = 0;//初始化count_small=0
    		BST_insert(node_vec[0], node_vec[i], count_small);//维护二叉排序树
    		count.push_back(count_small);//插入一个求一个count_small，并储存到count
    	}
        for (int i = node_vec.size() - 1; i >= 0; i--){
        	delete node_vec[i];
        	result.push_back(count[i]);//删除new的树节点，并且输出正确顺序结果
        }
        return result;
    }
};

int main(){
	int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
}

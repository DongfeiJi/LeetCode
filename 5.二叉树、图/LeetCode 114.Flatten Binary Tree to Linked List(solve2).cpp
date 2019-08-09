/*
 正当方法：递归
 递归的魅力在于无需考虑每一步怎么实现的，只需要考虑全局。
 设计时候，要设计一下递归函数输入，输出，对于输出要想每次递归需要传递给下一次递归什么信息，输出即输入
 对于本题目，递归函数传入就是当前节点node，和处理后的结尾last。前序处理要处理叶节点（这就是递归最小子问题，分治法最好求解的问题，last=node）
 还有访问node处理（因为要操作左子树右子树，这里就是备份），左子树递归处理要将左子树置空，同时连接到node，
 最后更新last，右子树递归处理就是连接到左子树尾部，最后更新last
 因此，递归的输入输出就是递归子过程的尾部
 
 概括思路：递归法+分治思想，函数传入node与last用于递归反复调用 
 递归结构体只有，node，left---left_last,right---right_last
 处理就是前序处理最小子问题叶节点并且备份左右指针，
 1，左子树拉平：左子树处理node左指针置空，右指针连接到left，最后更新last
 2，右子树连接：右子树处理，判断左子树last存在，左子树last指向right，更新last
 核心思想：递归的进行，左子树撸平，右子树如果存在左子树，就利用last连接起来
 */
#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preorder(root, last);
    }
private://node是当前节点，last是最后一个节点，传引用可以传出以供递归反复调用
	void preorder(TreeNode *node, TreeNode *&last){
		if (!node){
			return;
		}
		if (!node->left && !node->right){
			last = node;
			return;//这是在前序处理，递归最小子问题，就是叶子节点，他自己就是last
		}
		TreeNode *left = node->left;
		TreeNode *right = node->right;//因为左指针要置空，所以备份一下
		TreeNode *left_last = NULL;
		TreeNode *right_last = NULL;//初始化
		if (left){
			preorder(left, left_last);//若有左子树，将左子树递归转换成单链表
			node->left = NULL;
			node->right = left;
			last = left_last;//转换后序处理是左指针置空，node的右指针指向left，最后更新last
		}
		if (right){
			preorder(right, right_last);//若有右子树，将右子树递归转换成单链表
			if (left_last){
				left_last->right = right;//右子树开头right接到左子树结尾left_last
			}
			last = right_last;//最后更新last
		}
	}
};

int main(){
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Solution solve;
	solve.flatten(&a);
	TreeNode *head = &a;
	while(head){
		if (head->left){
			printf("ERROR\n");
		}
		printf("[%d]", head->val);
		head = head->right;
	}
	printf("\n");
	return 0;
}


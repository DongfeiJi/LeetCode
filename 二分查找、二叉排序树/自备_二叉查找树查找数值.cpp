#include <stdio.h>
#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归实现二叉排序树查找某值，1，如果相等，返回真 2，value小于节点，递归查找左子树，如果有左子树，递归查找，如果没有，返回假
//2，value大于节点，递归查找右子树，如果有右子树，递归查找，如果没有，返回假
bool BST_search(TreeNode *node, int value){
	if (node->val == value){
		return true;
	}
	if (value < node->val){
		if (node->left){
			return BST_search(node->left, value);
		}
		else{
			return false;
		}
	}
	else{
		if (node->right){
			return BST_search(node->right, value);
		}
		else{
			return false;
		}
	}
}

int main(){
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	for (int i = 0; i < 20; i++){
		if (BST_search(&a, i)){
			printf("%d is in the BST.\n", i);
		}
		else{
			printf("%d is not in the BST.\n", i);
		}
	}
	return 0;
}

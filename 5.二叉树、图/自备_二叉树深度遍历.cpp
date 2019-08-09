#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode *node){
	if (!node){
		return;
	}
	
	traversal(node->left);
	
	traversal(node->right);
	
}

void traversal_print1(TreeNode *node,int layer){//左中右，中序遍历
	if (!node){
		return;
	}
	traversal_print1(node->left, layer + 1);
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	traversal_print1(node->right, layer + 1);
}

void traversal_print2(TreeNode *node,int layer){//左右中，后序遍历
	if (!node){
		return;
	}
	traversal_print2(node->left, layer + 1);
	traversal_print2(node->right, layer + 1);
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
}

void traversal_print3(TreeNode *node,int layer){//中左右，先序遍历
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	traversal_print3(node->left, layer + 1);
	traversal_print3(node->right, layer + 1);
}

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
	traversal_print1(&a, 0);
	printf("\n");
	traversal_print2(&a, 0);
	printf("\n");
	traversal_print3(&a, 0);
	printf("\n");
	return 0;
}

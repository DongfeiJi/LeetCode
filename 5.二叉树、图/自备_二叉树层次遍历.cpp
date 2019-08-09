//层次遍历就是队列实现，将root push，然后打印后pop，再将左子树右子树节点分别push，循环是根据队列不为空
#include <stdio.h>
#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BFS_print(TreeNode* root){
	std::queue<TreeNode *> Q;
	Q.push(root);
  	while(!Q.empty()){
  		TreeNode *node = Q.front();
   		Q.pop();
	   	printf("[%d]\n", node->val);
	   	if (node->left){
	   		Q.push(node->left);
	   	}
	   	if (node->right){
	   		Q.push(node->right);
	   	}
   	}
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
	BFS_print(&a);
	return 0;
}

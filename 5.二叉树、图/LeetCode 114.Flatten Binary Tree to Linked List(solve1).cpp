/*
 单链表中节点顺序为二叉树前序遍历顺序，本题要求就原地的意思是数据结构还是树，left=null，right=next
 投机取巧法：前序遍历二叉树，将节点push到vector，顺序遍历vector，
 将前面节点左指针置空，右指针与后面节 点相连，下面是代码。
*/
#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
class Solution {
public:
    void flatten(TreeNode *root) {
    	std::vector<TreeNode *> node_vec;
    	preorder(root, node_vec);
    	for (int i = 1; i < node_vec.size(); i++){//这里是从1开始，防止下标越界
	    	node_vec[i-1]->left = NULL;
	    	node_vec[i-1]->right = node_vec[i];
	    }
    }
private://这是前序遍历保存节点的代码，输入是root，输出是vector
	void preorder(TreeNode *node, std::vector<TreeNode *> &node_vec){
		if (!node){
			return;
		}
		node_vec.push_back(node);
		preorder(node->left, node_vec);
		preorder(node->right, node_vec);
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

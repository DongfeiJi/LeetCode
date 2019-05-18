#include <stdio.h>

#include <vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void BST_insert(TreeNode *node, TreeNode *insert_node){
	if (insert_node->val < node->val){
		if (node->left){
			BST_insert(node->left, insert_node);
		}
		else{
			node->left = insert_node;
		}
	}
	else{
		if (node->right){
			BST_insert(node->right, insert_node);
		}
		else{
			node->right = insert_node;
		}
	}
}

void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}


void collect_nodes(TreeNode *node, std::vector<TreeNode *> &node_vec){
	if (!node){
		return;
	}
	node_vec.push_back(node);
	collect_nodes(node->left, node_vec);
	collect_nodes(node->right, node_vec);
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
	std::vector<TreeNode *> node_vec;
	collect_nodes(&a, node_vec);
	for (int i = 0; i < node_vec.size(); i++){
		node_vec[i]->left = NULL;
		node_vec[i]->right = NULL;
	}
	for (int i = 1; i < node_vec.size(); i++){
		BST_insert(node_vec[0], node_vec[i]);		
	}
	preorder_print(node_vec[0], 0);
	return 0;
}

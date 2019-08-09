/**
 思考：先举例子画图，理解题意，大概情况讨论下？其次看给定函数是如何定义，输入输出。
 对于刚才113题，求路径之和。此题就是找公共祖先，那么是否可以找出给定的两个节点的各个父节点，
 其实找父节点，就是找路径，因此本题采用路径解决问题。
 先序遍历的算法：求p节点路径，求q节点路径，画出来，遍历两个路径，相同的节点都是公共祖先，离根最远的就是最后一个相同的节点，就是答案最近公共祖先
 最后主要函数算法：先求出较短路径长度n，然后同时遍历两个路径，最后一个发现相同的节点就是最近公共祖先
 
 */
#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <vector>
#include <set>
//本题与113不同之处在于本题只需要求到给定节点路径即可,node是正在遍历的节点
void preorder(TreeNode* node,
			  TreeNode *search,//search就是给定的条件，搜索到这个节点
		   	  std::vector<TreeNode*> &path,//遍历时节点路径栈
		   	  std::vector<TreeNode*> &result,//最终搜索到search的路径结果
			  int &finish){
	if (!node || finish){//当node为空或者找到了search节点返回
		return;
	}
	path.push_back(node);
	if (node == search){
		finish = 1;
		result = path;//注意这里的result与path都是一维数组
	}//先序遍历操作：节点push栈，找到了finish为1，同时path送给result
	preorder(node->left, search, path, result, finish);
	preorder(node->right, search, path, result, finish);
	path.pop_back();//相当于遍历到底再返回便于继续遍历，脑中有图即可理解，回溯
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;//声明遍历用的临时栈
        std::vector<TreeNode*> node_p_path;
        std::vector<TreeNode*> node_q_path;//声明存储p和q的路径
        int finish = 0;
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;//由于求p，q的path，这两个参数实现了复用，因此要清0
        preorder(root, q, path, node_q_path, finish);        
        int path_len = 0;//这里要求较短路径长度，防止下标越界
        if (node_p_path.size() < node_q_path.size()){
        	path_len = node_p_path.size();
        }
        else{
        	path_len = node_q_path.size();
        }
        TreeNode *result = 0;
        for (int i = 0; i < path_len; i++){
        	if (node_p_path[i] == node_q_path[i]){
	        	result = node_p_path[i];
	        }//这里实现返回离根最远的公共点，使用相等就覆盖实现的
        }
        return result;
    }
};

int main(){
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;
	
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &c);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	result = solve.lowestCommonAncestor(&a, &b, &c);
	printf("lowestCommonAncestor = %d\n", result->val);
	
	return 0;
}



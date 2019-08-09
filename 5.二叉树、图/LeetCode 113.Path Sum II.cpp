/**
 补充：
 -------在这里处理相当于先序
 preorder(node->left, path_value, sum, path, result);
 -------这里处理相当于中序
 preorder(node->right, path_value, sum, path, result);
 -------这里处理相当于后序
 
 考虑：1，使用何种数据结构存储遍历路径上的节点
 2，若前序遍历处做什么？后续遍历处做什么？
 3，如何判断节点为叶节点，此时应该做些什么？
 前序遍历，后序，中序这种属于深度优先遍历。
 思考：因为返回的是二维数组，即各个符合条件的路径的情况，因此需要有一个path栈（vector），来保存每次搜索的值，又由于要访问每一个path栈中元素，并且push到result中，因此用vector来实现这个栈。
 算法如下：
 1，先序遍历，节点存储到path栈，同时使用path_value累加节点值。
 2，遍历到叶子，比较sum是否满足，如果满足，将path数组push到result。
 3，完成搜索的，将该节点从path弹出，同时path_value减去该节点，再继续遍历。（这里有种回溯思想）
 */
#include <stdio.h>

#include <vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode* root, int sum) {
    	std::vector<std::vector<int> > result;
    	std::vector<int> path;
    	int path_value = 0;//别忘了初始化，这就是sum
    	preorder(root, path_value, sum, path, result);//写调用子函数其实就是想，输入+条件+输出即可
    	return result;
    }
private://这里面传引用的都是在主要函数部分想要动态修改的
	void preorder(TreeNode *node, int &path_value, int sum,
				std::vector<int> &path,
				std::vector<std::vector<int> > &result){
		if (!node){//先序/中序/后序遍历都属属于深度优先遍历，采用递归实现
			return;
		}
		path_value += node->val;
		path.push_back(node->val);//这里先序处理计算sum并且存储节点，其实就是改变了print
		if (!node->left && !node->right && path_value == sum){
			result.push_back(path);//到了叶节点并且满足sum=target
		}
		preorder(node->left, path_value, sum, path, result);
		preorder(node->right, path_value, sum, path, result);
		path_value -= node->val;
		path.pop_back();//遍历完成后将该节点从路径栈弹出，回溯继续遍历
	}
};

int main(){
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &x;
	f.right = &y;
	Solution solve;
	std::vector<std::vector<int> > result = solve.pathSum(&a, 22);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

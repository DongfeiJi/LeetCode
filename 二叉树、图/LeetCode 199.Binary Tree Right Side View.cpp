/**
 二叉树的层次遍历，宽度优先搜索，算法如下：
 设置队列Q
 push根节点
 while（Q不空）{
 取出队列front
 访问node，就是打印啊之类的操作,用完pop
 将node左孩子右孩子都push到队列
 }
 代码：
 void BFS_print(TreeNode* root){
    std::queue<TreeNode*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode *node = Q.front();
        Q.pop();
        printf("[%d]\n",node->val);
        if(node->left) Q.push(node->left);
        if(node->right) Q.push(node->right);       
    }
}
回归本题，右视图，就是对于二叉树，层序遍历，宽度优先遍历的每一层的最后一个节点
那么如何记录每一层那个最后一个节点呢？
解决办法：将节点与层数绑定为pair，一起push到队列，然后用一个view数组，记录每一层最后一个节点
 */
#include <stdio.h>

#include <vector>
#include <queue>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> view;//结果数组，就是按层遍历的最后一个节点
    	std::queue<std::pair<TreeNode *, int> > Q;
    	if (root){
	    	Q.push(std::make_pair(root, 0));
	    }////首先根不为空，先把根push进队列，就是二叉树层次遍历
    	while(!Q.empty()){
	    	TreeNode *node = Q.front().first;
	    	int depth = Q.front().second;
	    	Q.pop();
	    	if (view.size() == depth){//如果还没遇到过这一层，先push进来
	    		view.push_back(node->val);
	    	}
	    	else{//否则就是还在这一层，将view[depth]覆盖更新
	    		view[depth] = node->val;
	    	}
	    	if (node->left){
	    		Q.push(std::make_pair(node->left, depth + 1));
	    	}
	    	if (node->right){
	    		Q.push(std::make_pair(node->right, depth + 1));//这里面depth不要忘记+1
	    	}
	    }
    	return view;
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
	std::vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]\n", result[i]);	
	}
	return 0;
}

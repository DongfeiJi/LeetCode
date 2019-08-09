/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
    DFS方法递归左右子树，谁大返回谁+1，注意递归返回类型就是所求类型
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot){
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left > right)?(left+1):(right+1);
    }
};
    BFS方法用队列实现,这里注意，因为求深度，所以要加一个for循环当前层
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot){
            return 0;
        }
        int depth = 0;
        queue<TreeNode*> Q;
        Q.push(pRoot);
        while(!Q.empty()){
            depth++;
            for(int i = 0; i < Q.size(); i++){
                TreeNode* node = Q.front();
                Q.pop();
                if(node->left){
                    Q.push(node->left);
                }
                if(node->right){
                    Q.push(node->right);
                }
            }
        }
        return depth;
    }
};
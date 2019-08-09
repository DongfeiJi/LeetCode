/*
操作给定的二叉树，将其变换为源二叉树的镜像。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
先交换根节点的两个子结点之后，我们注意到值为10、6的结点的子结点仍然保持不变，
因此我们还需要交换这两个结点的左右子结点。做完这两次交换之后，
我们已经遍历完所有的非叶结点。此时变换之后的树刚好就是原始树的镜像。
*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot){//特殊处理
            return; 
        }
        if(!pRoot->left && !pRoot->right){
            return;//递归返回
        }
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        if(pRoot->left){
            Mirror(pRoot->left);
        }
        if(pRoot->right){
            Mirror(pRoot->right);
        }
    }
};
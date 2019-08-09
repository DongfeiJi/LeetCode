/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
    判断二叉树AB，B是不是A的子结构，首先第一步，就是当AB某点值相等再进行深入判断，此时应固定B，不断遍历A的左子树和右子树
    第二步，细节判断，B是不是A的子结构，此时应该AB递归左右都要判断，A还有，B没了的时候，递归返回真
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        bool result = false;
        if(pRoot1 && pRoot2){
            if(pRoot1->val == pRoot2->val){//两值相等，精细判断
                result = DoesTree1HasTree2(pRoot1, pRoot2);
            }
            if(!result){//无值相等，保持B不动，遍历左
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if(!result){
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
private:
    bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot2){
            return true;
        }
        if(!pRoot1){
            return false;
        }
        if(pRoot1->val != pRoot2->val){
            return false;
        }//递归跳出条件1，递归到B没有了返回真，递归到A没有了和val不同返回假
        return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
    }//千万注意左右要同时递归
};
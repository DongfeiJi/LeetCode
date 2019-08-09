/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
我们通常有三种不同的二叉树遍历算法，即前序遍历、中序遍历和后序遍历。在这三种遍历算法中，都是先遍历左子结点再遍历右子结点。
以前序遍历为例，我们可以定义一个遍历算法，先遍历右子结点再遍历左子结点，暂且称其为前序遍历的对称遍历。
其中带有NULL的，也要包含进去
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
        
    }
    
    bool ismirror(TreeNode *p ,TreeNode *q){
        if(!p&&!q)//均为NULL
            return true;
        if(!p||!q)//只有一个为NULL，6666这里虽然包含均为NULL，但是前面语句先执行先输出，先递归结束
            return false;
        if(p->val==q->val)
            return ismirror(p->left,q->right)&&ismirror(p->right,q->left);
        //如果p的左等于q的右 p的右等于q的左 那么是对称 否则返回下面的false
        return false;
    }
};
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot){
        //if(!pRoot){
            //return true;//这里无需判断了，因为下面判断了
        //}
        return isSymmetric(pRoot, pRoot);//因为要对称对比，所以需要设计一个函数有两个输入
    }
private:
    bool isSymmetric(TreeNode* pRoot1, TreeNode* pRoot2){
        if(!pRoot1 && !pRoot2){
            return true;
        }
        if(!pRoot1 || !pRoot2){
            return false;
        }
        if(pRoot1->val != pRoot2->val){
            return false;//这是先序对称遍历的递归跳出条件
        }
        return isSymmetric(pRoot1->left, pRoot2->right) && isSymmetric(pRoot1->right, pRoot2->left);
    }

};
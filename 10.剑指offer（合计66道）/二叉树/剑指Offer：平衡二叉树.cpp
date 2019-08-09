/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

重复遍历多次：
在遍历树的每个结点的时候，调用函数TreeDepth得到它的左右子树的深度。如果每个结点的左右子树的深度相差都不超过1，
则这是一颗平衡的二叉树。这种方法的缺点是，首先判断根结点是不是平衡的，需要使用TreeDepth获得左右子树的深度，
然后还需要继续判断子树是不是平衡的，还是需要使用TreeDepth获得子树的左右子树的深度，这样就导致了大量的重复遍历。

只遍历一次：
重复遍历会影响算法的性能，所以很有必要掌握不需要重复遍历的方法。
如果我们用后序遍历的方式遍历二叉树的每一个结点，在遍历到一个结点之前我们就已经遍历了它的左右子树。
只要在遍历每个结点的时候记录它的深度（某一结点的深度等于它到叶结点的路径的长度），
我们就可以一边遍历一边判断每个结点是不是平衡的。
class Solution {//重复遍历多次
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot){
            return true;//递归跳出条件，没有diff绝对值大于1，没有返回false，就返回true
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left - right;
        if(diff > 1 || diff < -1){
            return false;//递归过程中，一旦差值大于1，就返回false，这里注意时绝对值，因为不知道大小
        }
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);//递归传出的一定是左和右
    }
private:
    int TreeDepth(TreeNode* pRoot){//求树深度
        if(!pRoot){
            return 0;
        }
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        return (left > right)?(left+1):(right+1);//左右子树，谁深返回谁，max(left, right)+1
    }
};
*/

class Solution {//只遍历一次,后续遍历
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
private:
    int IsBalanced(TreeNode* pRoot, int* depth){
        if(!pRoot){
            *depth = 0;
            return true;//递归结束，只有全部符合题意，才会返回true
        }
        int left, right;
        if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)){//后序遍历，先看左右子树
            int diff = left - right;
            if(abs(diff) <= 1){
                *depth = max(left,right) + 1;//这里记录depth，用于判断不符合题意就返回false
                return true;
            }
        }
        return false;
    }
};
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes，否则输出No。假设输入的数组的任意两个数字都互不相同。

二叉搜索树就是二叉排序树，中序遍历就是按照顺序排序好的
以{5,7,6,9,11,10,8}为例，后序遍历结果的最后一个数字8就是根结点的值。
在这个数组中，前3个数字5、7和6都比8小，是值为8的结点的左子树结点；
后3个数字9、11和10都比8大，是值为8的结点的右子树结点。
接下来用同样的方法确定与数组每一部分对应的子树的结构。这其实就是一个递归的过程。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);//size-1的下标正好是最后一个值
    }
private:
    bool bst(vector<int> seq, int begin, int end){
        if(seq.empty() || begin > end){
            return false;//特殊情况+递归结束条件
        }
         
        //根结点
        int root = seq[end];//此为root，递归入口
         
        //在二叉搜索树中左子树的结点小于根结点
        int i = begin;//这里注意，因为后面要用到i
        for(; i < end; ++i){
            if(seq[i] > root){
                break;
            }
        }//break后，此时的i，由于是++i，此时i之前都是左子树（不包括i），i之后是右子树
         
        //在二叉搜索书中右子树的结点大于根结点
        for(int j = i; j < end; ++j){
            if(seq[j] < root){
                return false;//右子树中一旦有比root小的就反悔false
            }
        }
         
        //判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin){
            left = bst(seq, begin, i - 1);//begin～i-1是左子树
        }
         
        //判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end - 1){
            right = bst(seq, i , end - 1);//i～end-1是右子树，这里都是下标，所以是end-1
        }
         
        return left && right;
    }
};
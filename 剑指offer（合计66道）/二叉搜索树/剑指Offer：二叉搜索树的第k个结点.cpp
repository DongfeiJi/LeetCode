/*
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
只需要用中序遍历一棵二叉搜索树，就很容易找出它的第k大结点。
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k){
        if(!pRoot || k == 0){//特殊情况处理
            return NULL;
        }
        return KthNodeCore(pRoot, k);//调用子函数求解
    }
private:
    TreeNode* KthNodeCore(TreeNode* root, int &k){//这里要取地址，不改变主函数中k
        TreeNode* target = NULL;//定义结果
        if(root->left){
            target = KthNodeCore(root->left, k);//递归左子树，找出target
        }
        // 如果没有找到target，则继续减小k，如果k等于1，说明到了第k大的数
        if(!target){
            if(k == 1){//这里这样理解，递归压栈到最小子问题，也就是左子树最小值
                target = root;//（上接）给定k假如为3，那么k--到1时，正好处于倒数第三次递归，也就是第k小
            }
            k--;
        }
        if(root->right && !target){// 如果没有找到target，继续找右结点
            target = KthNodeCore(root->right, k);
        }
        return target;
    }

    
};
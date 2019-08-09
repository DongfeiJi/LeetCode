/**
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 重建二叉树输入前序和中序，前序用来找root，中序用来区分左子树与右子树的值，因此递归就是划分左子树和右子树
 通常树有如下几种遍历方式：

前序遍历：先访问根结点，再访问左子结点，最后访问右子结点。
中序遍历：先访问左子结点，再访问根结点，最后访问右子结点。
后序遍历：先访问左子结点，再访问右子结点，最后访问根结点。
本题为前序遍历和中序遍历，最少需要两种遍历方式，才能重建二叉树。

前序遍历序列中，第一个数字总是树的根结点的值。在中序遍历序列中，根结点的值在序列的中间，
左子树的结点的值位于根结点的值的左边，而右子树的结点的值位于根结点的值的右边。剩下的我们可以递归来实现
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0){
            return NULL;
        }
        vector<int> left_pre, left_vin, right_pre, right_vin;
        TreeNode* head = new TreeNode(pre[0]);
        int root = 0;
        for(int i = 0; i < pre.size(); i++){
            if(pre[0] == vin[i]){
                root = i;
                break;
            }
        }
        for(int i = 0; i < root; i++){
            left_pre.push_back(pre[i+1]);
            left_vin.push_back(vin[i]);
        }
        for(int i = root+1; i < pre.size(); i++){
            right_pre.push_back(pre[i]);
            right_vin.push_back(vin[i]);
        }
        head->left = reConstructBinaryTree(left_pre, left_vin);
        head->right = reConstructBinaryTree(right_pre, right_vin);
        return head;
    }
};
/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
首先这道题给出的是中序遍历这个二叉树，那么就是左根右。我们在求一个结点的下一个结点，那么这个时候我们需要分情况讨论：
1、如果该结点有右子树，则该结点的下一个结点为该结点的右子树的最左结点。
2、如果该结点没有右子树，则又分两种情况讨论：
情况一：如果该结点为该结点的父结点的左孩子，则该结点的父结点pNode.next则为下一个结点。
情况二：如果该结点为该结点的父结点的右孩子，则该结点的父结点的父结点的父结点，
直到其中的一个父结点是这个父结点的左孩子，则该父结点的父结点为下一个结点。
注意注意注意：该两种情况编程之需判断找父节点，如果该父节点左孩子就是你，那么此父节点就是返回值。
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
        if(!pNode){
            return NULL;
        }
        if(pNode->right){//这是有右子树情况，往下找最左边的节点
            pNode = pNode->right;
            while(pNode->left){
                pNode = pNode->left;
            }
            return pNode;
        }
        while(pNode->next){//当父节点存在，由于要一直向上找，这里一定是用while
            if(pNode->next->left == pNode){
                return pNode->next;
            }
            pNode = pNode->next;//不要忘记一直向上查找
        }
        return NULL;
    }
};
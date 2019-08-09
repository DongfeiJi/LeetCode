/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
根据二叉搜索树的特点：左结点的值<根结点的值<右结点的值，，使用二叉树的中序遍历出来的数据的数序，因此确定了二叉搜索树的遍历方法。
按照中序遍历的顺序，遍历到根结点时，左子树已经转换成一个排序的好的双向链表了，并且处在链表中最后一个的结点是当前值最大的结点。
接着我们就去遍历右子树，并把根结点和右子树中最小的结点链接起来。
递归思想：中序处理
只考虑某一节点的双向指针链接即可，并且更新pLastNodeInList
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        TreeNode* pLastNodeInList = NULL;//用于记录双向链表尾结点
        convertNode(pRootOfTree, &pLastNodeInList);//开始转换结点
        //pLastNodeInList指向双向链表的尾结点，但是需要返回的是头结点
        TreeNode* pHeadOfList = pLastNodeInList;
        while(pHeadOfList && pHeadOfList->left){
            pHeadOfList = pHeadOfList->left;
        }
        return pHeadOfList;
    }
    //这里**，因为传入的是指针形参，指针的指针
    void convertNode(TreeNode* pNode, TreeNode** pLastNodeInList){//为了方便处理最后一个节点
        if(!pNode){
            return;//递归返回
        }
        TreeNode* pCurrent = pNode;//保存pNode，防止递归改变了pNode
        if(pCurrent->left){//递归左子树
            convertNode(pCurrent->left, pLastNodeInList);
        }
        //中序遍历操作，先链接左指针，再链接右指针
        pCurrent->left = *pLastNodeInList;//链接左指针
        if(*pLastNodeInList){//链接右指针，因为最后一个NULL存在，这里需要判断一下
            (*pLastNodeInList)->right = pCurrent;
        }
        *pLastNodeInList = pCurrent;//更新双向链表尾结点，因为中序递归，只考虑左子树情况，pCurrent就是root，就是当前的尾结点
        if(pCurrent->right){//递归右子树
            convertNode(pCurrent->right, pLastNodeInList);
        }
    }
};
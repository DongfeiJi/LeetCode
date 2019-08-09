/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
从上向下打印二叉树，可以想到，如何保存打印左子树和右子树的顺序呢？当然是队列，先进先出，打印一个root，将左右压入队列即可
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;//套路都是先定义一个result
        queue<TreeNode*> Q;
        if(!root){
            return result;
        }
        Q.push(root);//用队列实现，先放root，队列用push
        while(!Q.empty()){
            result.push_back(Q.front()->val);
            if(Q.front()->left){//不要忘记判断下是否存在再push
                Q.push(Q.front()->left);
            }
            if(Q.front()->right){
                Q.push(Q.front()->right);
            }
            Q.pop();//不要忘记pop
        }
        return result;
    }
};
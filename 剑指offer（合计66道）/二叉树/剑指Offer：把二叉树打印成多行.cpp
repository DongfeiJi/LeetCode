/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
这道题比上一道题《剑指Offer（五十九）：按之字顺序打印二叉树》简单一些
思路和上一道题一样，区别在于，这把是先入先出，使用队列即可。
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > result;
            if(!pRoot){
                return result;
            }
            queue<TreeNode*> Q;
            Q.push(pRoot);
            while(!Q.empty())
            {
                int size = Q.size();//重要！！！！！！！！！！
                vector<int> tmp_result;
                for(int i=0; i< size; ++i){//这里因为Q一直在pop，也就是在变，所以不能用Q.size()
                    TreeNode* tmp = Q.front();
                    tmp_result.push_back(tmp->val);
                    Q.pop();
                    if(tmp->left)
                        Q.push(tmp->left);
                    if(tmp->right)
                        Q.push(tmp->right);
                }
                result.push_back(tmp_result);
            }
            return result;
        }

};



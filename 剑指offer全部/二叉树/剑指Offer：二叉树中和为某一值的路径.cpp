/*
输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
深度优先搜索。使用前序遍历，使用两个全局变量result和tmp，result来存放最终结果，tmp用来存放临时结果。
每次遍历，我们先把root的值压入tmp，然后判断当前root是否同时满足：
与给定数值相减为0；
左子树为空；
右子树为空。
如果满足条件，就将tmp压入result中，否则，依次遍历左右子树。需要注意的是，遍历左右子树的时候，
全局变量tmp是不清空的，直到到了根结点才请空tmp。
核心：
这是求完全路径，比较简单，用递归回溯解决
每次遍历到某个节点，就将expectNumber减去该值，用来递归
*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        //vector<vector<int>> result这里由于用到递归每次都会初始化，因此输出为空，所以带递归的函数要把变量放在外面private
        //vector<int> tmp;//临时结果
        if(!root){
            return result;//递归结束条件，无root传入
        }
        tmp.push_back(root->val);//放入root
        if((expectNumber - root->val) == 0 && !root->left && !root->right){
            result.push_back(tmp);//符合题意，值正确并且到了叶子节点，将tmp存入result
        }
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);//左右递归遍历
        tmp.pop_back();//回溯
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> tmp;//临时结果
};

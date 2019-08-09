/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
    为了达到这样打印的效果，我们需要使用两个栈。我们在打印某一行结点时，把下一层的子结点保存到相应的栈里。
    如果当前打印的是奇数层（第一层、第三层等），则先保存左子树结点再保存右子树结点到第一个栈里。
    如果当前打印的是偶数层（第二层、第四层等），则则先保存右子树结点再保存左子树结点到第二个栈里。
    tmp_node栈用来存放临时节点，tmp_result用来存放当前结果
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(!pRoot){
            return result;
        }
        stack<TreeNode*> tmp_node[2];//声明两个用于存放临时节点
        tmp_node[0].push(pRoot);//其中tmp_node第1个存放的时左右也就是奇数行，第2个存放的是偶数行
        while(!tmp_node[0].empty() || !tmp_node[1].empty()){
            vector<int> tmp_result[2];//用来存放当前结果
            while(!tmp_node[0].empty()){//偶数行，先放左再放右，输出就是右左
                tmp_result[0].push_back(tmp_node[0].top()->val);//
                if(tmp_node[0].top()->left){
                    tmp_node[1].push(tmp_node[0].top()->left);
                }
                if(tmp_node[0].top()->right){
                    tmp_node[1].push(tmp_node[0].top()->right);
                }
                tmp_node[0].pop();
            }
            if(!tmp_result[0].empty()){//保存偶数行结果
                result.push_back(tmp_result[0]);
            }
            while(!tmp_node[1].empty()){//奇数行，先放右再放左，输出的就是左右
                tmp_result[1].push_back(tmp_node[1].top()->val);
                if(tmp_node[1].top()->right){
                    tmp_node[0].push(tmp_node[1].top()->right);
                }
                if(tmp_node[1].top()->left){
                    tmp_node[0].push(tmp_node[1].top()->left);
                }
                tmp_node[1].pop();
            }
            if(!tmp_result[1].empty()){//保存奇数行结果
                result.push_back(tmp_result[1]);
            }
        }
        return result;
    }
};

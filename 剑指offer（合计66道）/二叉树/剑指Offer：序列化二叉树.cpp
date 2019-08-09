/*
请实现两个函数，分别用来序列化和反序列化二叉树
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
这道题思路简单，使用前序遍历来序列化和发序列化即可。只要自己写的程序格式对应上即可。
可以使用$符号表示NULL，同时每个结点之间，需要添加逗号，即','进行分隔。
*/
class Solution {
public:
    char* Serialize(TreeNode *root) {    
        if(!root){
            return NULL;//树转字符串时，root为空返回NULL
        }
        string str;
        SerializeCore(root, str);//调用子函数，将树序列化为str类型
        // 把str流中转换为字符串返回,因为返回类型为字符串*，并在结尾附加一个\0结束符
        int len = str.length();
        char* res = new char[len+1];
        for(int i =0; i < len; i++){
            res[i] = str[i];
        }
        res[len] = '\0';
        return res;
    }
    TreeNode* Deserialize(char *str) {
       if(!str){
           return NULL;//字符串转树时，字符串为空返回NULL
       }
        TreeNode* res = DeserializeCore(&str);//这里传引用，递归保证不变性
        return res;
    }
    void SerializeCore(TreeNode* root, string& str){
        if(!root){//处理特殊情况，空指针我们记录为#
            str += '#';
            return;
        }
        string tmp = to_string(root->val);
        str += tmp;
        str += ',';// 用逗号， 分割树节点
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }
    TreeNode* DeserializeCore(char** str){// 递归时改变了str值使其指向后面的序列，因此要声明为char**
        if(**str == '#'){//这是到达叶子节点，**str指代内容，*str就是指针可以++
            (*str)++;
            return NULL;
        }
        int num = 0;
        while(**str != ',' && **str != '\0'){//将字符串转换为数值作为node的val
            num = num*10 + ((**str - '0'));
            (*str)++;
        }
        TreeNode* root = new TreeNode(num);
        if(**str == '\0'){//递归跳出条件，到达字符串结束符号，返回root
            return root;
        }
        else{//没结束就继续
            (*str)++;
        }
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }

};
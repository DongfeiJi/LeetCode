/*
二叉查找树/二叉排序树/二叉搜索树，对于一个node，左子树均小于等于node，右子树均大于等于node，等于只在一侧
中序遍历是排序好的的数据，对于二叉排序树有插入一个元素BST_insert和查找一个元素BST_search的操作
想法：将二叉排序树前序遍历存储到vector，再重新插入元素构造就可以得到和原来一模一样的树，
这里一定是前序遍历，因为中左右，还有插入元素算法的原理，才是先从root开始
本题思想：
编码：先画一个二叉搜索树，然后前序遍历形式，将整型数据转化为字符串并且用特殊符号连接。比如8#3#1#6#
解码：根据分隔符，将数字拆分出来，然后第一个数字作为root，在依次插入即可
补充整形转字符串：
对于12345，可以利用对10取余，可以逐个的将个位取出，然后添加到str中，直到该数字%10为0，最后str反转即可
补充字符串转数字：
对于123#456#，val=0，for循环i，val = val*10+str[i]-'0'，遇到#，打印val并且val清0
*/
#include <stdio.h>


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#include <string>
#include <vector>
//二叉排序树插入代码
void BST_insert(TreeNode *node, TreeNode *insert_node){
	if (insert_node->val < node->val){
		if (node->left){
			BST_insert(node->left, insert_node);
		}
		else{
			node->left = insert_node;
		}
	}
	else{
		if (node->right){
			BST_insert(node->right, insert_node);
		}
		else{
			node->right = insert_node;
		}
	}
}
//整形转字符串代码
void change_int_to_string(int val, std::string &str_val){
	std::string tmp;
	while(val){//val每次循环都/10，因此循环val
		tmp += val % 10 + '0';//这里是字符加减
		val = val / 10;
	}//遍历val，每次将val个位转换为字符，添加到tmp尾部
	for (int i = tmp.length() - 1; i >= 0; i--){
		str_val += tmp[i];
	}//逆序
	str_val += '#';//转换每个数后加一个#
}
//这是前序将树节点 整型转换为字符型 并且存入data
void BST_preorder(TreeNode *node, std::string &data){
	if (!node){
		return;
	}
	std::string str_val;
	change_int_to_string(node->val, str_val);
	data += str_val;
	BST_preorder(node->left, data);
	BST_preorder(node->right, data);
}

class Codec {
public:
    std::string serialize(TreeNode* root) {// Encodes a tree to a single string.
    	std::string data;
        BST_preorder(root, data);
        return data;
    }
	
    TreeNode *deserialize(std::string data) { // Decodes your encoded data to tree.
    	if (data.length() == 0){
	    	return NULL;
	    }//这是处理特殊情况，空树
    	std::vector<TreeNode *> node_vec;
    	int val = 0;//初始化node数组和val值
    	for (int i = 0; i < data.length(); i++){
	    	if (data[i] == '#'){
	    		node_vec.push_back(new TreeNode(val));//这里不用delete，在类外delete析构即可，因为有root
	    		val = 0;//node数组push并且val清0用于下次提取
	    	}
	    	else{
	    		val = val * 10 + data[i] - '0';//否则当前继续计算当前数字值
	    	}
	    }//这里和字符串转整形很像，用if-else，仅仅是将if里面的打印改为vector push了
	    for (int i = 1; i < node_vec.size(); i++){
    		BST_insert(node_vec[0], node_vec[i]);
    	}
    	return node_vec[0];
    }
};

void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}

int main(){
	TreeNode a(8);
	TreeNode b(3);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);	
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;	
	Codec solve;	
	std::string data = solve.serialize(&a);
	printf("%s\n", data.c_str());
	TreeNode *root = solve.deserialize(data);
	preorder_print(root, 0);	
	return 0;
}

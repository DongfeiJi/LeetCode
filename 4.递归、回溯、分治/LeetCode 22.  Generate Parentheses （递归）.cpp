/*
与子集题比较像，对于全部所有子集，再选取合法的组合
计算：n组括号，一共2n个字符串，由于每个括号要么是左括号要么是右括号，因此一共有2^2n个子集
1，对于递归生成所有子集，想象一个二叉递归树，1空   2（  3）  2.1（   2.2） 3.1（   3.2）
void generate(std::string item, int n, std::vector<std::string> &result){
    if(item.size() == 2*n){//这里要理解，递归不是循环，这只是递归终止条件，不是循环判断
        result.push_back(item);//item用来存储生成的括号字符串，完成递归再存入结果
        return;
    }
    generate(item+'(', n, result);//添加（并且递归
    generate(item+')', n, result); //添加）并且递归
    }
    其实这就是递归item由空字符串不断插入递归
2，本题对上述进行合法的子集筛选，其实即使改变递归限制条件
子集合法条件：1，左括号与右括号的数量不可以大于n，2，放一个左括号，才可以放右括号
合法条件可以理解为递归生成子集终止条件
因此递归终止条件为：1，左括号与右括号数量最多为n 2，当左括号数量小于右括号，不可进行放置右括号的递归
*************这里注意递归可以写成1，终止条件为0，那么递归函数n-1  2，终止条件为n，递归函数i+1
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generate("", n, n, result);
        return result;
    }
private:
    void generate(std::string item, int left, int right,//item存储生成字符串
                  std::vector<std::string>& result){//left表示当前还可以放置左括号的数量
        if(left == 0 && right == 0){//这里递归终止条件就是左右都放完了，不可以size=2n
            result.push_back(item);
            return;
        }
        if(left > 0){//左括号随便放，放了过后，别忘了left-1
            generate(item+'(', left - 1, right, result);
        }
        if(left < right){//右括号要在左括号较多时候才可以放，即left是剩余可以放的括号要较小
            generate(item+')', left, right - 1, result);
        }      
    }
};
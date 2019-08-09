/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case
等关键字及条件判断语句（A?B:C）。

递归实现

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        // &&就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算。即递归终止条件
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};
*/
class Solution {
public:
    int Sum_Solution(int n) {
        int res = n;
        if(n > 1){
            res += Sum_Solution(n - 1);
        }
        return res;
    }
};
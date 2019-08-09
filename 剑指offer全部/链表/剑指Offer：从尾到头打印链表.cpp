/**
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
通常，这种情况下，我们不希望修改原链表的结构。
返回一个反序的链表，这就是经典的“后进先出”，我们可以使用栈实现这种顺序。
每经过一个结点的时候，把该结点放到一个栈中。
当遍历完整个链表后，再从栈顶开始逐个输出结点的值，给一个新的链表结构，
这样链表就实现了反转。
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> nodes;
        vector<int> result;
        ListNode* node = head;
        while(node != NULL){
            nodes.push(node->val);
            node = node->next;
        }
        while(!nodes.empty()){
            result.push_back(nodes.top());
            nodes.pop();
        }
        return result;
    }
};
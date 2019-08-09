/*
输入两个链表，找出它们的第一个公共结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
方法一：

我们可以把两个链表拼接起来，一个pHead1在前pHead2在后，一个pHead2在前pHead1在后。
这样，生成了两个相同长度的链表，那么我们只要同时遍历这两个表，
就一定能找到公共结点。时间复杂度O(m+n)，空间复杂度O(m+n)。

方法二：

我们也可以先让把长的链表的头砍掉，让两个链表长度相同，这样，
同时遍历也能找到公共结点。此时，时间复杂度O(m+n)，空间复杂度为O(MAX(m,n))。
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int list1_len = get_length(pHead1);
        int list2_len = get_length(pHead2);
        if(list1_len < list2_len){
            pHead2 = forward(list2_len, list1_len, pHead2);
        }
        else{
            pHead1 = forward(list1_len, list2_len, pHead1);
        }
        while(pHead1 && pHead2){
            if(pHead1 == pHead2){
                return pHead1;
            }
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
private:
    int get_length(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* forward(int long_length, int short_length, ListNode* head){
        int delta_length = long_length - short_length;
        while(head && delta_length){
            head = head->next;
            delta_length--;
        }
        return head;
    }
};
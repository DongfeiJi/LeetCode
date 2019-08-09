/*
输入一个链表，反转链表后，输出新链表的表头。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
这个很简单，我们使用三个指针，分别指向当前遍历到的结点、
它的前一个结点以及后一个结点。
在遍历的时候，做当前结点的尾结点和前一个结点的替换。
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next){
            return pHead;
        }
        ListNode* newhead = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;
        return newhead;
    }
};

#include <stdio.h>

struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);//外排，设置新链表头节点
    	ListNode *pre = &temp_head;//外排，设置新链表头指针pre
    	while (l1 && l2){//l1与l2不同时为空
	    	if (l1->val < l2->val){
	    		pre->next = l1;
	    		l1 = l1->next;//谁小谁连到新链表pre
	    	}
	    	else{
	    		pre->next = l2;
	    		l2 = l2->next;
	    	}
	    	pre = pre->next;//pre不要忘记往后移动
	    }
	    if (l1){//如果l1有剩余
    		pre->next = l1;
    	}
    	if (l2){//如果l2有剩余
	    	pre->next = l2;
	    }
        return temp_head.next;//返回的是新链表头节点.next!!!!!!!!!
    }
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);
	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	Solution solve;
	ListNode *head = solve.mergeTwoLists(&a, &d);
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

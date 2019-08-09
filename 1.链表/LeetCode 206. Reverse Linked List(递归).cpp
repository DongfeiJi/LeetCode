//递归，前面非递归方式是从前面数1开始往后依次处理，而递归方式则恰恰相反，
//它先循环找到最后面指向的数5，然后从5开始处理依次翻转整个链表。 
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {//递归是一种到头到底再返回的感觉
        if(!head || !head->next){
			return head;//如果列表为空，就返回，!head->next是递归跳出条件
        }
        ListNode* new_head = reverseList(head->next);//递归逆序，递归入口是前面的下一个节点，一直循环到链尾
		head->next->next = head;//翻转链表的指向
        head->next = NULL;//当前节点指向空，否则有环了，此句一定在上一句后面，否则 head->next就丢失
        return new_head;//返回的是新的头      
    }
};

int main(){	
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution solve;	
	ListNode *head = &a;
	printf("Before reverse:\n");
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	head = solve.reverseList(&a);
	printf("After reverse:\n");
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

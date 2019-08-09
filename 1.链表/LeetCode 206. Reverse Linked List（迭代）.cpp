//迭代法
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head = NULL;
		while(head){
			ListNode *tmp = head->next;//保存head->next的指针地址
			head->next = new_head;
			//将当前节点的指针指向前一个节点，head->next指向前一个空间，前面最结尾就是new_head
			new_head = head;//将反转的list赋给new_head
			head = tmp;//head向后走，继续反转
		}
		return new_head;
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

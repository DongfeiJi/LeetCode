/*
思想就是新建两个虚拟节点（表示小于x与大于等于x），然后分别用两个新建的指针指向这两个虚拟节点，添加就是加到这个后面
*/
#include <stdio.h>
	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	ListNode less_head(0);
    	ListNode more_head(0);//设置两个临时头节点
    	ListNode *less_ptr = &less_head;
    	ListNode *more_ptr = &more_head;//设置指向这两个头结点的指针用来插入
        while(head){
        	if (head->val < x){
        		less_ptr->next = head;//小于x 插入到less指针后面
        		less_ptr = head;//less指针后移
			}
			else {
				more_ptr->next = head; //大于等于x 插入到more指针后面
				more_ptr = head;
			}
        	head = head->next;//遍历循环移动
        }
        less_ptr->next = more_head.next;//合并两个链表，即less指针指向more头节点的下一个节点 注意 此处 morehead是一个节点 因此用.
        more_ptr->next = NULL;//more指针指向NULL
        return less_head.next;//注意这里返回的是less头节点的下一个节点
    }
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;	
	Solution solve;
	ListNode *head = solve.partition(&a, 3);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

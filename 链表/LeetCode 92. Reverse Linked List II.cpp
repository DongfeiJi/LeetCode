#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;//定义反转的长度
        ListNode *pre_head = NULL;//定义一个空指针，用于保存前面没反转的尾巴节点
        ListNode *result = head;
        while(head && --m){//用于指针向后移动找到要从哪里开始反转
        	pre_head = head;
        	head = head->next;//此时pre_head指向未反转部分最后一个节点，head指向反转第一个节点
        }
        ListNode *modify_list_tail = head;//定义反转后的列表尾巴为此时head头节点
        
        ListNode *new_head = NULL;//声明一个新头节点
		while(head && change_len){//两两反转
			ListNode *next = head->next;//保存head->next镜象
			head->next = new_head;//将head下一个设置为新头节点
			new_head = head;//反向连接指针
			head = next;//head往后面移动，用于下次反转
			change_len--;
		}
		modify_list_tail->next = head;//此时head指向反转链表后面未反转部分的头节点
		
		if (pre_head){//如果前面有未反转部分
			pre_head->next = new_head;//将未反转的尾巴节点与反转部分头节点连接
		}
		else{
			result = new_head;//否则就是从第一个就开始反转了，返回反转部分头节点
		}
		return result;
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
	ListNode *head = solve.reverseBetween(&a, 2, 4);	
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

//方法二，快慢指针法，两个链表，就是求长度，让长的先走差值步，再一起走，当节点地址相同，就返回
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int get_list_length(ListNode *head){//链表长
	int len = 0;
	while(head){
		len++;
		head = head->next;
	}
	return len;
}

ListNode *forward_long_list(int long_len, int short_len, ListNode *head){//用于长链表先走len差值的距离
	int delta = long_len - short_len;
	while(head && delta){
		head = head->next;
		delta--;
	}
	return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   		int list_A_len = get_list_length(headA);
   		int list_B_len = get_list_length(headB);   		
   		if (list_A_len > list_B_len){
   			headA = forward_long_list(list_A_len, list_B_len, headA);
	   	}
	   	else{
	   		headB = forward_long_list(list_B_len, list_A_len, headB);
	   	}//分别求两个链表的长度，并让长的先走长度之差的距离		
        while(headA && headB){
        	if (headA == headB){//两个链表同时遍历，发现节点地址相同，那么返回
	        	return headA;
	        }
	        headA = headA->next;
	        headB = headB->next;
        }
        return NULL;
    }
};

int main(){
	ListNode a1(1);
	ListNode a2(2);
	ListNode b1(3);
	ListNode b2(4);
	ListNode b3(5);
	ListNode c1(6);
	ListNode c2(7);
	ListNode c3(8);
	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;	
	Solution solve;
	ListNode *result = solve.getIntersectionNode(&a1, &b1);
	printf("%d\n", result->val);
	return 0;
}

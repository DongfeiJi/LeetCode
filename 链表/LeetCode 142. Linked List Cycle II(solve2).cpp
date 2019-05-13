//快慢指针法则
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	ListNode *fast = head;
    	ListNode *slow = head;
    	ListNode *meet = NULL;//定义快慢指针
    	while(fast){//这块是让快慢指针向前走，计算meet
    		slow = slow->next;
    		fast = fast->next;
    		if (!fast){//因为fast较快，所以一旦fast指向空，就说明无环
		    	return NULL;
		    }
		    fast = fast->next;
		    if (fast == slow){//快慢指针相遇说明有环
    			meet = fast;
    			break;
    		}
	    }
	    if (meet == NULL){//如果meet为空就返回无环
    		return NULL;
    	}
    	while(head && meet){//此时head在起始点，meet在快慢指针相遇点
	    	if (head == meet){//让head和meet一起走，相遇处就是入环点
	    		return meet;
	    	}
	    	head = head->next;
	    	meet = meet->next;
	    }
        return NULL;
    }
};

int main(){
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;
	Solution solve;
	ListNode *node = solve.detectCycle(&a);
	if (node){
		printf("%d\n", node->val);
	}
	else{
		printf("NULL\n");
	}
	return 0;
}

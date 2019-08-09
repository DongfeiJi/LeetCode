//方法一：set实现
#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include <set>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   		std::set<ListNode*> node_set;
		while(headA){
			node_set.insert(headA);
			headA = headA->next;
        }
        while(headB){
        	if (node_set.find(headB) != node_set.end()){//遍历链表B发现，B的节点在集合中找到了
	        	return headB;
	        }
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

#include <stdio.h>
/*
方法一：两两合并，时间复杂度为（n+n）+（2n+n）+（（k-1）n+n）
方法二：将k*n个节点存入vector，再调用std：：sort，再连接。时间复杂度为：kN（logN）+KN
方法三：分治，两两合并2N*k/2+4N*k/4+...+logK*N*K/logK=Nk*logK
将一个问题分解为与原问题相似但规模更小的若干子问题，递归地解这些子问题,
然后将这些子问题的解结合起来构成原问题的解。这种方法在每层递归上均包括三个步骤：
divide（分解）：将问题划分为若干个子问题
(这里是两两合并，即logK个子问题，循环拆解，直至最小拆解到两两合并)
conquer（求解）：递归地解这些子问题；若子问题Size足够小，则直接解决之
（求解最小子问题方法为mergeTwoLists，两两链表合并问题，记得做过这道题）
Combine（组合）：将子问题的解组合成原问题的解
（返回的是两两最小解）
 */
struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode temp_head(0);
    	ListNode *pre = &temp_head;
    	while (l1 && l2){
	    	if (l1->val < l2->val){
	    		pre->next = l1;
	    		l1 = l1->next;
	    	}
	    	else{
	    		pre->next = l2;
	    		l2 = l2->next;
	    	}
	    	pre = pre->next;
	    }
	    if (l1){
    		pre->next = l1;
    	}
    	if (l2){
	    	pre->next = l2;
	    }
        return temp_head.next;
    }	//这是合并两个链表，就是本题最小子问题
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    	if (lists.size() == 0){
        	return NULL;//如果lists为空，返回NULL
        }
    	if (lists.size() == 1){
	    	return lists[0];//如果只有一个链表，直接返回
	    }
	    if (lists.size() == 2){//如果两个列表，直接求解
    		return mergeTwoLists(lists[0], lists[1]);
    	}
    	int mid = lists.size() / 2;//算出划分值
    	std::vector<ListNode*> sub1_lists;
    	std::vector<ListNode*> sub2_lists;//这两个用于拆分原问题为两个子问题，即lists拆为两个list
    	for (int i = 0; i < mid; i++){
	    	sub1_lists.push_back(lists[i]);//左子lists存入vec
	    }
	    for (int i = mid; i < lists.size(); i++){
    		sub2_lists.push_back(lists[i]);//右子lists存入vec
    	}
    	ListNode *l1 = mergeKLists(sub1_lists);//左子lists不断递归拆
    	ListNode *l2 = mergeKLists(sub2_lists);//直至全部拆到最小问题，就是two lisits，再求解返回
    	return mergeTwoLists(l1, l2);//返回最小值解，递归合并为原问题解，就是分治思想
    }
};

int main(){
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);
	ListNode g(2);
	ListNode h(3);
	a.next = &b;
	b.next = &c;	
	d.next = &e;
	e.next = &f;	
	g.next = &h;
	Solution solve;	
	std::vector<ListNode *> lists;
	lists.push_back(&a);
	lists.push_back(&d);
	lists.push_back(&g);	
	ListNode *head = solve.mergeKLists(lists);
	while(head){
		printf("%d\n", head->val);
		head = head->next;
	}
	return 0;
}

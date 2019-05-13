#include <stdio.h>
/*
 方法一：两两合并，时间复杂度为（n+n）+（2n+n）+（（k-1）n+n）
 方法二：将k*n个节点存入vector，再调用std：：sort，再连接。时间复杂度为：kN（logN）+KN
 方法三：分治，两两合并2N*k/2+4N*k/4+...+logK*N*K/logK=Nk*logK
 */
struct ListNode {
 	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

#include <vector>
#include <algorithm>

bool cmp(const ListNode *a, const ListNode *b){
	return a->val < b->val;
}//用于sort自定义排序，由于存入的是指针地址，所以要对值进行排序

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::vector<ListNode *> node_vec;        
        for (int i = 0; i < lists.size(); i++){
			//思想是将k个链表全部添加值node_vec，因此采用全部链表的head指针，先读取全部head，
			//再用head遍历，这里注意是一个一个链表添加
        	ListNode *head = lists[i];
        	while(head){
        		node_vec.push_back(head);//将链表指针地址pushback到vec
	        	head = head->next;
	        }
        }
        if (node_vec.size() == 0){
        	return NULL;//判断异常 如果列表为空 返回NULL
        }        
        std::sort(node_vec.begin(), node_vec.end(), cmp);//由于vec存入的是指针，这里是对值排序，因此用到cmp自定义排序
        for (int i = 1; i < node_vec.size(); i++){//这里i=1开始是担心最后i+1，会越界
        	node_vec[i-1]->next = node_vec[i];//连接最后一个节点 到NULL
        }
        node_vec[node_vec.size()-1]->next = NULL;
        return node_vec[0];//返回的是头节点指针地址  
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

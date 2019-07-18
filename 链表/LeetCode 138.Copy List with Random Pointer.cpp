/*
建立映射关系，一个node_vec用于存储，下标--节点，一个map用于存储指针与下标
*/	
#include <stdio.h>
		
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

#include <map>
#include <vector>

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	std::map<RandomListNode *, int> node_map;//地址到节点序号的map
    	std::vector<RandomListNode *> node_vec;//序号到新地址的数组map
    	RandomListNode *ptr = head;
    	int i = 0;//用于记录序号
    	while (ptr){//第一次遍历就是建立map1与map2
	    	node_vec.push_back(new RandomListNode(ptr->label));//将原链表存于vec，vec下标就是序号
	    	node_map[ptr] = i;//建立原链表指针和下标的映射
	    	ptr = ptr->next;
	    	i++;
	    }
	node_vec.push_back(0);//用于省略处理列表最后面的NULL
	ptr = head;
	i = 0;
	while(ptr){//第二次遍历用于深拷贝，连接vec中的各种指针
            node_vec[i]->next = node_vec[i+1];//vec就是代表新链表，这是连接next指针
    	    if (ptr->random){//如果random指针存在
    		int id = node_map[ptr->random];//id从map中查找映射过来，就是java中的get
		node_vec[i]->random = node_vec[id];//在vec中将第i个序号与id连接
	    }
            ptr = ptr->next;
    	    i++;
    	}
    	return node_vec[0];//vec就是深拷贝的新链表，指针连接好了
    }
};

int main(){
	RandomListNode a(1);
	RandomListNode b(2);
	RandomListNode c(3);
	RandomListNode d(4);
	RandomListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;	
	a.random = &c;
	b.random = &d;
	c.random = &c;
	e.random = &d;	
	Solution solve;
	RandomListNode *head = solve.copyRandomList(&a);	
	while(head){
		printf("label = %d ", head->label);
		if (head->random){
			printf("rand = %d\n", head->random->label);
		}
		else{
			printf("rand = NULL\n");
		}
		head = head->next;
	}
	return 0;
}

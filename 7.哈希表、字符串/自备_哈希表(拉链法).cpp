//由于采用对哈希表len取余这个哈希函数会对同一个key产生多个value，因此采用拉链法
//拉链法哈希法包括：1，链表数据结构 2，哈希对len取余哈希函数 3，插入节点采用头插法 4，查找节点先找key，再遍历属于这个key的链表
#include <stdio.h>
#include <vector>

struct ListNode {//链表数据结构
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int hash_func(int key, int table_len){//哈希函数key对哈希表len取余
	return key % table_len;
}

void insert(ListNode *hash_table[], ListNode *node, int table_len){//插入节点子函数，头插法插入新节点，
	int hash_key = hash_func(node->val, table_len);//先求哈希key
	node->next = hash_table[hash_key];
	hash_table[hash_key] = node;//即node->next指向原始key，然后将node设置为key
}

bool search(ListNode *hash_table[], int value, int table_len){//查找某个节点，传入的是哈希表，查找值，哈希表len
	int hash_key = hash_func(value, table_len);//求key
	ListNode *head = hash_table[hash_key];//定义头指针，用来遍历key这个链表
	while(head){
		if (head->val == value){
			return true;
		}
		head = head->next;
	}
	return false;
}

int main(){
	const int TABLE_LEN = 11;
	ListNode *hash_table[TABLE_LEN] = {0};//这个是用来存哈希表key的链表结构
	std::vector<ListNode *> hash_node_vec;//这是用来存节点的，因为给定数据是list，但是定义insert支持的是ListNode型数据结构
	int test[8] = {1, 1, 4, 9, 20, 30, 150, 500};
	for (int i = 0; i < 8; i++){
		hash_node_vec.push_back(new ListNode(test[i]));//将list数据类型转为ListNode*，这样才可调用insert子函数
	}	
	for (int i = 0; i < hash_node_vec.size(); i++){
		insert(hash_table, hash_node_vec[i], TABLE_LEN);//创建哈希表，调用insert插入到哈希表
	}	
	printf("Hash table:\n");
	for (int i = 0; i < TABLE_LEN; i++){
		printf("[%d]:", i);
		ListNode *head = hash_table[i];
		while(head){
			printf("->%d", head->val);
			head = head->next;
		}
		printf("\n");//打印哈希表，先遍历全部key，再循环head遍历全部拉链法节点
	}
	printf("\n");	
	printf("Test search:\n");
	for (int i = 0; i < 10; i++){//这是查找某value，遍历全部key，再遍历全部拉链法节点
		if (search(hash_table, i, TABLE_LEN)){
			printf("%d is in the hash table.\n");
		}
		else{
			printf("%d is not in the hash table.\n");
		}
	}
	return 0;
}

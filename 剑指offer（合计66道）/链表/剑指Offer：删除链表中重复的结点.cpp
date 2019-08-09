/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

删除重复结点，只需要记录当前结点前的最晚访问过的不重复结点pPre、
当前结点pCur、指向当前结点后面的结点pNext的三个指针即可。
如果当前节点和它后面的几个结点数值相同，那么这些结点都要被剔除，
然后更新pPre和pCur；如果不相同，则直接更新pPre和pCur。

需要考虑的是，如果第一个结点是重复结点我们该怎么办？
这里我们分别处理一下就好，如果第一个结点是重复结点，
那么就把头指针pHead也更新一下。
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(!pHead){
            return NULL;
        }
        ListNode* pPre = NULL;//指向前面不重复的最后一个节点
        ListNode* pCur = pHead;//正在访问的节点指针
        ListNode* pNext = NULL;//用于滑动窗口的判断相同值的指针
        while(pCur){
            if(pCur->next && pCur->val == pCur->next->val){//遇到重复值的情况
                pNext = pCur->next;
                while(pNext->next && pNext->next->val == pCur->val){
                    pNext = pNext->next;//滑动窗口仍然重复
                }
                if(pCur == pHead){
                    pHead = pNext->next;//这是从头节点就开始重复的情况
                }
                else{
                    pPre->next = pNext->next;//这是从非头节点就开始重复的情况
                }
                pCur = pNext->next;
            }
            else{//遇到不重复值的情况
                pPre = pCur;
                pCur = pCur->next;
            }
        }
        return pHead;
    }
};
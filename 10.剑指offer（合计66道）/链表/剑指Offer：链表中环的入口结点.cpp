/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
可以用两个指针来解决这个问题。先定义两个指针P1和P2指向链表的头结点。
如果链表中的环有n个结点，指针P1先在链表上向前移动n步，
然后两个指针以相同的速度向前移动。当第二个指针指向的入口结点时，
第一个指针已经围绕着揍了一圈又回到了入口结点。

以下图为例，指针P1和P2在初始化时都指向链表的头结点。
由于环中有4个结点，指针P1先在链表上向前移动4步。
接下来两个指针以相同的速度在链表上向前移动，直到它们相遇。
它们相遇的结点正好是环的入口结点。

现在，关键问题在于怎么知道环中有几个结点呢？
可以使用快慢指针，一个每次走一步，一个每次走两步。
如果两个指针相遇，表明链表中存在环，并且两个指针相遇的结点一定在环中。
随后，我们就从相遇的这个环中结点出发，一边继续向前移动一边计数，
当再次回到这个结点时，就可以得到环中结点数目了。
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead){
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        ListNode* meet = NULL;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(!fast) return NULL;
            fast = fast->next;
            if(fast == slow){
                meet = fast;
                break;
            }
        }
        while(pHead && meet){
            if(pHead == meet){
                return meet;
            }
            pHead = pHead->next;
            meet = meet->next;
        }
        return NULL;
    }
};
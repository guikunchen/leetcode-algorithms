#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/linked-list-cycle-ii/

// 先找到环，再求出环的节点数目n，然后两个指针指向链表第一个元素
// 其中一个从头指针走n步，等两个指针重新相遇就是所求节点。


/*
1.先判断是否存在环
2.当第一次快慢指针相遇时，说明存在环，此时相遇点在圆内，此时慢指针走过的距离是x+y，快指针走过的距离是x+y+z+y，因为快指针走过的距离是慢指针的2倍，所以得到等式2（x+y）= x+y+z+y,所以x = z
3.接下来，令p = head，让p和slow同时再走一段距离为x的路程，二者就在环入口相遇
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head, *p = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)            //如果链表存在环
            {
                while(p != slow)
                {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
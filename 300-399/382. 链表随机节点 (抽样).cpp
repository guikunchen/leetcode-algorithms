// https://leetcode-cn.com/problems/linked-list-random-node/
// https://www.cnblogs.com/snowInPluto/p/5996269.html
// 蓄水池抽样算法，设容量为k，把前k个元素放入数组，从k+1个元素开始，假设为j，被选中的概率是 k / j
// 对第j个数（j > k），被选中的概率为 k / j
// 可以理解为前面总共有j个数需要选一个淘汰，看能不能选到水池其中的一个
class Solution {// 下面是k = 1的情况
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head): head(head) {

    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int i = 2;
        ListNode* cur = head->next;
        int val = head->val;
        while(cur != nullptr) {
            if(rand() % i == 0) val = cur->val; //第 i 节点以 1/i 概率替换当前值
            i++;
            cur = cur->next;
        }
        return val;
    }
private:
    ListNode* head;
};
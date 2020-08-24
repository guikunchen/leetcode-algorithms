#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 用双指针解就可以了，如果翻倍遍历可能会快一点，但是最后要做逻辑判断，O(n/2)仍然是O(n)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *prev = preHead;

        ListNode *tail = head;
        while(n != 0){
            tail = tail->next;
            n--;
        }

        while(tail != nullptr){
            tail = tail->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;
        return preHead->next;
    }
};
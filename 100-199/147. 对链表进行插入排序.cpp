#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/insertion-sort-list/

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
    // 直接写个插入排序是没什么难度的
    // 优化一下的话，就是下个元素如果比上个元素大，就可以不从链表头开始比。
    ListNode* insertionSortList(ListNode* head) {
        ListNode preHead(0);
        ListNode *p = head;
        ListNode *nextBegin = nullptr;
        while(p){
            ListNode *insert = nextBegin == nullptr ? &preHead : nextBegin;
            while(insert->next != nullptr && insert->next->val < p->val){
                insert = insert->next;
            }
            ListNode *succeed = insert->next;
            insert->next = p;
            p = p->next;
            if(p != nullptr && p->val >= insert->next->val){
                nextBegin = insert;
            }
            else{
                nextBegin = nullptr;
            }
            insert->next->next = succeed;
        }
        return preHead.next;
    }

    // 参考了别人的写法，思路和优化后的思路是一样的
    ListNode* insertionSortList(ListNode* head) {
        ListNode preHead(0);
        ListNode *pre = &preHead;

        for(ListNode* node = head; node != nullptr;){
            ListNode* cur = node;
            node = node->next;

            if(cur->val < pre->val){
                pre = &preHead;
            }

            while(pre->next != nullptr && cur->val > pre->next->val){
                pre = pre->next;
            }

            cur->next = pre->next;
            pre->next = cur;
        }

        return preHead.next;
    }
};
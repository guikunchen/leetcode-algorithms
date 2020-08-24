#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/rotate-list/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k <= 0 || head == nullptr) return head;

        int n = 1;
        ListNode *old_tail = head;
        for(; old_tail->next != nullptr; n++) {
            old_tail = old_tail->next;
        }
        old_tail->next = head;// 闭环

        ListNode *new_tail = head;
        for(int i = 0; i < n - (k % n) - 1; i++) {
            new_tail = new_tail->next;
        }
        
        ListNode *new_head = new_tail->next;
        new_tail->next = nullptr;// 拆环
        return new_head;
    }
};
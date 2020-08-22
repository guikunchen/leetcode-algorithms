#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {// 普通操作
        int ans = head->val;
        ListNode *p = head->next;
        while(p){
            ans = ans * 2 + p->val;
            p = p->next;
        }
        return ans;
    }
    int getDecimalValue(ListNode* head) {// 换成移位和"或"运算
        int ans = head->val;
        ListNode *p = head->next;
        while(p){
            ans <<= 1;
            ans |= p->val;
            p = p->next;
        }
        return ans;
    }
};
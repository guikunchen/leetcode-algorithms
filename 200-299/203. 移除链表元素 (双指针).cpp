#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/remove-linked-list-elements/


/**
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead = head;
        while(newHead && newHead->val == val){
            newHead = newHead->next;
        }
        ListNode* current = newHead;
        while(current && current->next){
            if(current->next->val == val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};
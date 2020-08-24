#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

/**
输入: 1->1->2->3->3
输出: 1->2->3
 */

// 这么写应该是最简单的了，在用指针的时候就直接比较，但是省略了内存释放
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while(current && current->next){
            if(current->val == current->next->val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};

// 下面显得很冗余，但是思想是一样的，注意题目给的是有序数组
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *p = head;
        int current = head->val;
        while(p->next){
            if(p->next->val == current){
                p->next = p->next->next;
            }
            else{
                p = p->next;
                current = p->val;
            }
        }
        return head;
    }
};

// 无序的才要这么写
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        set<int> vals;
        ListNode *prev = head, *p = head->next;
        vals.insert(head->val);
        while(p->next != NULL){
            if(vals.count(p->val)){
                p->val = p->next->val;
                p->next = p->next->next;
            } else {
                vals.insert(p->val);
                prev = p;
                p = p->next;
            }
        }
        if(vals.count(p->val)){
            prev->next = NULL;
        }
        return head;
    }
};


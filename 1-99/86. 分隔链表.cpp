#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/partition-list/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    	if(head == nullptr) return head;

        ListNode before_head(0), after_head(0);
        ListNode *before = &before_head, *after = &after_head;

        while(head != nullptr) {
        	if(head->val < x) {
        		before->next = head;
        		before = before->next;
        	} else {
        		after->next = head;
        		after = after->next;
        	}
        	head = head->next;
        }

        after->next = nullptr;
        before->next = after_head.next;
        return before_head.next;
    }
};
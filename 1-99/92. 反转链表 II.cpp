#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/reverse-linked-list-ii/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = nullptr, *cur = head;
        while(m > 1) {
        	prev = cur;
        	cur = cur->next;
        	m--;
        	n--;
        }

        ListNode *conn = prev, *tail = cur;
        while(n > 0) {
        	ListNode *third = cur->next;
        	cur->next = prev;
        	prev = cur;
        	cur = third;
        	n--;
        }

        if(conn == nullptr) {
        	head = prev;
        } else {
        	conn->next = prev;
        }

        tail->next = cur;
        return head;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
    	ListNode *slow = head, *fast = head;
    	while(fast && fast->next){
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	return slow;
    }
};

// 快慢指针
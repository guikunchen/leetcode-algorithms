#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/palindrome-linked-list/


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
    bool isPalindrome(ListNode* head) {// 时间n，空间1。也可以用栈实现，时间n空间n。
    	ListNode *fast = head, *slow = head;
    	ListNode *frontHalfFirst = NULL;
    	while(fast && fast->next){
    		fast = fast->next->next;
    		ListNode *tmp = slow->next;
    		slow->next = frontHalfFirst;
    		frontHalfFirst = slow;
    		slow = tmp;
    	}
    	ListNode *behindHalfFirst = fast? slow->next: slow;

    	while(frontHalfFirst && behindHalfFirst){
    		if(frontHalfFirst->val != behindHalfFirst->val) return false;
    		frontHalfFirst = frontHalfFirst->next;
    		behindHalfFirst = behindHalfFirst->next;
    	}
    	return true;
    }
};

//在快慢指针遍历的同时，把前面一半的链表倒置，最后没有把链表倒置回去（这一步应该是必要的）
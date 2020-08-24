#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/merge-two-sorted-lists


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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {// 递归，时间m+n，空间m+n
        if(l1 == NULL){
        	return l2;
        }
        else if(l2 == NULL){
        	return l1;
        }
        else if(l1->val < l2->val){
        	l1->next = mergeTwoLists(l1->next, l2);
        	return l1;
        }
        else{
        	l2->next = mergeTwoLists(l1, l2->next);
        	return l2;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {// 迭代，时间m+n，空间1
        ListNode* preHead = new ListNode(0);
        ListNode* prev = preHead;
        while(l1 != NULL && l2 != NULL){
        	if(l1->val < l2->val){
        		prev->next = l1;
        		l1 = l1->next;
        	}
        	else{
        		prev->next = l2;
        		l2 = l2->next;
        	}
        	prev = prev->next;
        }
        if(l1 != NULL){
        	prev->next = l1;
        }
        else{
        	prev->next = l2;
        }
        return preHead->next;
    }
};
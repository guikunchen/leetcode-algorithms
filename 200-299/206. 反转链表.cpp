#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == NULL || head->next == NULL)// 边界条件
    	{
    		return head;
    	}

    	ListNode newHead = reverseList(head->next);// 缩小问题
    	head->next->next = head;// 第一个节点会变成最后一个节点
    	head->next = NULL;// 指向NULL
    	return newHead;
    }
};

// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if (head == NULL || head->next == NULL)
    	{
    		return head;
    	}

    	ListNode *newHead = NULL;
    	while(head){
    		ListNode *tmp = head;// 每次把原链表的第一个拿出来作为新链表的第一个
    		head = head->next;
    		tmp->next = newHead;
    		newHead = tmp;
    	}
    	return newHead;
    }
};
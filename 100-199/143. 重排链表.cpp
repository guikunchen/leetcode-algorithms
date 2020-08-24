#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/reorder-list/

// 先把链表分成奇链和偶链，再把偶链逆序，最后把奇链和偶链按大小组合在一起
// 将链表从中间分成两个链表，倒序后面的链表，依次按奇偶插入链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *fast = head, *slow = head;
        ListNode *secondHalf = findSecondHalf(fast, slow); // 找到链表的中间结点
        ListNode *secondHalfReversed = reverse(secondHalf); // 翻转后半部分链表

        while(secondHalfReversed) // 这里的判断条件不可以加上 secondHalfReversed->next ！！！
        {
            ListNode *headNext = head -> next, *secondNext = secondHalfReversed -> next; // 找到头结点和后半部分头结点各自的后面一个结点
            head -> next = secondHalfReversed;
            secondHalfReversed -> next = headNext;
            head = headNext;
            secondHalfReversed = secondNext;
        }
    }
    ListNode* findSecondHalf(ListNode *fast, ListNode *slow)
    {
        // 奇数个数的话，如1-2-3-4-5，后半部分为4-5；偶数个数的话，如1-2-3-4-5-6，后半部分为4-5-6
        while(fast && fast->next && fast->next->next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode *newHead = slow -> next;
        slow -> next = nullptr; // 这一步很重要！断开前后两部分的链表
        return newHead;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr, *curr = head;
        while(curr)
        {
            ListNode *nextptr = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode *last = headB;
        while(last->next){
            last = last->next;
        }
        last->next = headB;// 线程不安全的！
        ListNode *slow = headA;
        ListNode *fast = headA;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = headA;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                last->next = NULL;
                return slow;
            }
        }
        last->next = NULL;
        return NULL;
    }// 手动构造一个环，内层while循环可通过数学证明得出，必得到第一个交点（画图）
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        int lenA = 0, lenB = 0;
        for(ListNode *p = headA; p; p = p->next){
            lenA++;
        }
        for(ListNode *p = headB; p; p = p->next){
            lenB++;
        }
        ListNode *newA = headA, *newB = headB;
        if(lenB >= lenA){
            while(--lenB >= lenA){
                newB = newB->next;
            }
        }
        else{
            while(--lenA >= lenB){
                newA = newA->next;
            }
        }
        while(newA && newB){
            if(newA == newB) return newA;
            newA = newA->next;
            newB = newB->next;
        }
        return NULL;
    }// 先计算长度，把更长的那个链表往后面推动一点。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode *pA = headA, *pB = headB;
        while(pA != pB){
            pA = pA == NULL? headB: pA->next;
            pB = pB == NULL? headA: pB->next;
        }
        return pA;
    }// 两条链表长度相等，如果有交点则第一轮while循环在[0,n]某一处就会返回交点，没有交点就会在n处同时为NULL然后返回;
    // 两条链表长度不等，第一轮遍历完换到另一个链表的表头，如果有交点则在[max(n,m), n+m]某一处返回交点，没有交点就会在n+m处同时为NULL然后返回;

};
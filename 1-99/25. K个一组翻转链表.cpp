#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

class Solution {
public:
    void myReverse(ListNode *begin, ListNode *end){
        ListNode *prev = end->next;
        ListNode *p = begin;
        while(prev != end){
            ListNode *next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode *pre = preHead;

        while(head != nullptr){
            ListNode *tail = pre;
            for(int i = 0; i < k; i++){
                tail = tail->next;
                if(tail == nullptr) return preHead->next;
            }
            myReverse(head, tail);// 链表反转
            pre->next = tail;// tail 是第一个节点
            pre = head;// head是最后一个节点
            head = head->next;// 进行下一组
        }

        return preHead->next;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/linked-list-cycle/


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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode *slow = head, *fast = head->next;
        while(slow && fast){
            if(slow == fast){
                return true;
            }
            slow = slow? slow->next: NULL;
            fast = (fast && fast->next)? fast->next->next: NULL;
        }
        return false;
    }
};

// 快慢指针，一个走一步一个走两步，相遇便存在环
// 链表要特别考虑到空和只有一个节点的情况

// 上面写得不够好，快慢指针考虑快的就好了，注意快指针这里是走两步（走三步不稳定，走两步一定会和慢指针相遇）
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head? head->next: NULL;
        while(fast && fast->next){
            if(slow == fast){
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};

// 也可以这么写，快慢指针可以初始化在同一个地方，一般也是初始化在同一个地方
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
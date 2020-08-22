#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/line-reflection
/*用一个 非空 单链表来表示一个非负整数，然后将这个整数加一。

你可以假设这个整数除了 0 本身，没有任何前导的 0。

这个整数的各个数位按照 高位在链表头部、低位在链表尾部 的顺序排列。

示例:
输入: [1,2,3]
输出: [1,2,4]*/

class Solution {// 递归钻到最后面再往回加
public:
    ListNode* plusOne(ListNode* head) {
        int carry = 1;
        dfs(head, carry);
        if(carry) {// 999..99加1，进位了，要多一个节点
            ListNode* newhead = new ListNode(carry);
            newhead->next = head;
            return newhead;
        }
        return head;
    }
    void dfs(ListNode* head, int& carry)
    {
        if(!head) return;
        dfs(head->next, carry);
        int sum = head->val+carry;
        head->val = sum%10;
        carry = sum/10;
    }
};
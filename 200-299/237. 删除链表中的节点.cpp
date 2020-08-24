#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/delete-node-in-a-linked-list/

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        // 内存没有被释放，因为不知道要写free还是delete
    }
};

// 因为要删除的节点不是最后一个节点，所以可以这么写
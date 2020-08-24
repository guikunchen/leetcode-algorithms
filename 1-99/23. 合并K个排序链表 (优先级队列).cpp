#include<iostream>
#include<vector>
#include<set>
using namespace std;


// https://leetcode-cn.com/problems/merge-k-sorted-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {// 顺序合并，时间k²n，空间1
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size() == 0) return nullptr;
        ListNode headNode(0);
        headNode.next = lists[0];
        int times = lists.size() - 1;
        for(int i = 0; i < times; i++) {
        	ListNode *prev = &headNode;
        	ListNode *l1 = prev->next, *l2 = lists[i + 1];
        	while(l1 != nullptr && l2 != nullptr) {
        		if(l1->val > l2->val) {
        			prev->next = l2;
        			l2 = l2->next;
        		} else {
        			prev->next = l1;
        			l1 = l1->next;
        		}
        		prev = prev->next;
        	}
        	prev->next = l1 ? l1 : l2;
        }
        return headNode.next;
    }
};


class Solution { // 分治，时间，nklogk，空间 logk
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

class Solution { // 最小堆维护k个链表的第一个节点，时间：nklogk，空间：k
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
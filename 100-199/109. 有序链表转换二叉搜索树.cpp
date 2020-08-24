#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/

// 通过快慢指针将链表从中间分为两部分，
class Solution {
public:
    ListNode* findMiddleElement(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != nullptr) {// 防止只有一个节点
            prev->next = nullptr;// 断开链接
        }

        return slow;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode *mid = findMiddleElement(head);
        TreeNode *node = new TreeNode(mid->val);
        if(head == mid) {
            return node;
        }

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        return node;
    }
};

// 方法二直接用一个数组存值

// 方法三，递归自底向上构建树,二分就可以划分出左子树右子树的索引范围
class Solution {
public:
    ListNode *head;
    int findSize(ListNode *head) {
        ListNode *p = head;
        int c = 0;
        while(p != nullptr) {
            p = p->next;
            c++;
        }
        return c;
    }

    TreeNode* convertListToBST(int l, int r) {
        if(l > r) return nullptr;

        int mid = l + ((r- l) >> 1);

        // First step of simulated inorder traversal. Recursively form the left half
        TreeNode *left = convertListToBST(l, mid - 1);
        // Once left half is traversed, process the current node
        TreeNode *node = new TreeNode(this->head->val);
        node->left = left;
        // Maintain the invariance mentioned in the algorithm
        this->head = this->head->next;
        // Recurse on the right hand side and form BST out of them
        node->right = convertListToBST(mid + 1, r);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;

        int size = findSize(head);
        this->head = head;
        return convertListToBST(0, size - 1);
    }
};
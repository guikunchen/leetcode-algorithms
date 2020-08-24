#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/symmetric-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isMirror(TreeNode* node1, TreeNode* node2) {
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;
        return (node1->val == node2->val)
            && isMirror(node1->left, node2->right)
            && isMirror(node2->left, node1->right); 
    }
    bool isSymmetric(TreeNode* root) {// 递归
        if(root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    bool isSymmetric(TreeNode* root) {// 迭代,宽度优先搜索
        // 这里用到一个技巧，从队列中每次取两个节点比较是否相等，这两个节点是镜像节点
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode *node1 = q.front(); q.pop();
            TreeNode *node2 = q.front(); q.pop();
            if(node1 == nullptr && node2 == nullptr) continue;
            if(node1 == nullptr || node2 == nullptr) return false;
            if(node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};
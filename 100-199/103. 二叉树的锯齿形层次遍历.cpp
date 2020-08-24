#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        deque<TreeNode*> q;
        q.push_front(root);
        bool is_order_left = true;//此时是奇数行
        while(!q.empty()){
            vector<int> layer;
            for(int i = q.size() - 1; i>=0; --i) {
                TreeNode* cur;
                if(is_order_left) {//奇数行从前往后取节点 孩子自左向右压入双端队列尾
                    cur = q.front(); q.pop_front();
                    layer.push_back(cur->val);
                    if(cur->left) q.push_back(cur->left); 
                    if(cur->right) q.push_back(cur->right);
                }
                else {//偶数行 从后往前取节点 孩子自右向左压入双端队列头
                    cur = q.back(); q.pop_back();
                    layer.push_back(cur->val);
                    if(cur->right) q.push_front(cur->right);
                    if(cur->left) q.push_front(cur->left); 
                }  
            }
            is_order_left = !is_order_left;
            res.push_back(layer);
        }
        return res;
    }
};
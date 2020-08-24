#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/


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
	int maxDepth(TreeNode* root) {// 递归
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int maxDepth(TreeNode* root) {// 迭代，一层遍历完时可通过quene的size得到下一层的数量
        if(root == NULL) return 0;
        
        std::queue<TreeNode *> q;
        q.push(root);
        int left = 1;
        int depth = 0;
        while(!q.empty()){
            TreeNode *tmp = q.front(); q.pop();
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
            if(--left == 0){
                depth++;
                left = q.size();
            }
        }
        return depth;
    }
};
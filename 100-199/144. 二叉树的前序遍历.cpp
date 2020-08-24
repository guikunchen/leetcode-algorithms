#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/


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
    vector<int> preorderTraversal(TreeNode* root) {// 自己0手写的
        vector<int> ans;
        if(root == NULL) return ans;

        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode *tmp = s.top();
            s.pop();
            ans.push_back(tmp->val);
            // 要先让右边的进栈，再让左边的进栈，这样左边的先访问
            if(tmp->right != NULL) s.push(tmp->right);
            if(tmp->left != NULL) s.push(tmp->left);
        }
        return ans;
    }

    vector<int> preorderTraversal(TreeNode* root){// 参考别人的思路，个人认为还不如我自己写的
        vector<int> ans;
        TreeNode *p = root;
        stack<TreeNode*> s;
        while(p || !s.empty()){
            while(p){
                ans.push_back(p->val);
                // if(p->right != NULL) s.push(p->right);
                s.push(p->right);// 这里不可以加if，因为栈空了再出栈会报错
                p = p->left;
            }
            p = s.top(); s.pop();
        }
        return ans;
    }
};
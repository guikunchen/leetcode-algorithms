#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/


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
    void flatten(TreeNode* root) {// 先序遍历解决
        if(root == nullptr) return;

        TreeNode* node = root;
        stack<TreeNode*> s;
        if(root->right != nullptr) s.push(root->right);
        if(root->left != nullptr) s.push(root->left);
        while(!s.empty()){
            TreeNode* tmp = s.top(); s.pop();
            if(tmp->right != nullptr) s.push(tmp->right);
            if(tmp->left != nullptr) s.push(tmp->left);
            node->right = tmp;
            node->left = nullptr;
            node = node->right;
        }
    }

    void flatten(TreeNode* root) { //每次把右子树接到左子树的最右下角
        TreeNode *node = root;
        while(node != nullptr){
            if(node->left == nullptr){
                node = node->right;
            }
            else{
                TreeNode *left = node->left;
                while(left->right != nullptr){// 找到左子树的最右下角
                    left = left->right;
                }
                left->right = node->right;// 接在左子树的最右下角
                node->right = node->left;// 左子树替换右子树
                node->left = nullptr;// 清空左子树
                node = node->right;
            }
        }
    }
};
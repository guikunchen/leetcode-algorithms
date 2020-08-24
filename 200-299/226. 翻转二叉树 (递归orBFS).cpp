#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/invert-binary-tree/


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
    TreeNode* invertTree(TreeNode* root) {// 递归，相当于前序遍历
        if(root == NULL) return root;
        TreeNode *tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {// 迭代,层次遍历
        if(root == NULL) return root;

        std::queue<TreeNode *> q;
		q.push(root);
		while(!q.empty()){
			TreeNode *node = q.front();
			q.pop();
			TreeNode *tmp = node->left;
			node->left = node->right;
			node->right = tmp;
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);
		}
		return root;
    }
};
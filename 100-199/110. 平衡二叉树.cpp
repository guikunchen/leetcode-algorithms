#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/balanced-binary-tree/


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
	int height(TreeNode* root){
		if(root == nullptr) return 0;
		return 1 + max(height(root->left), height(root->right));
	}
    bool isBalanced(TreeNode* root) {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return abs(leftHeight - rightHeight) <= 1;
    }
};
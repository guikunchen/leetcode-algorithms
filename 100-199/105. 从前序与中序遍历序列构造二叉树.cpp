#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    // 跟106几乎一样，改个参数就好了
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int preBegin, int inBegin, int size){
        if(size == 0) return nullptr;

        int rootVal = preorder[preBegin];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = inBegin;
        while(inorder[rootIndex] != rootVal) rootIndex++;// 肯定能找到
        int leftSize = rootIndex - inBegin;
        root->left = helper(preorder, inorder, preBegin + 1, inBegin, leftSize);
        root->right = helper(preorder, inorder, preBegin + leftSize + 1, inBegin + leftSize + 1, size - leftSize - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, inorder.size());
    }
};


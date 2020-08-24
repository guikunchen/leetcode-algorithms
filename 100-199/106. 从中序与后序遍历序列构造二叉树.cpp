#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    // 思路很简单，写起来bug特别多
    TreeNode *helper(vector<int>& inorder, vector<int>& postorder, int inBegin, int postBegin, int size){
        if(size == 0) return nullptr;

        int rootVal = postorder[postBegin + size - 1];
        TreeNode *root = new TreeNode(rootVal);
        int rootIndex = inBegin;
        while(inorder[rootIndex] != rootVal) rootIndex++;// 肯定能找到
        int leftSize = rootIndex - inBegin;
        root->left = helper(inorder, postorder, inBegin, postBegin, leftSize);
        root->right = helper(inorder, postorder, inBegin + leftSize + 1, postBegin + leftSize, size - leftSize - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, 0, inorder.size());
    }
};


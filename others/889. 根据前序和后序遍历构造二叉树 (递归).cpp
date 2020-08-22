#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    TreeNode *helper(vector<int>& pre, vector<int>& post, int preBegin, int postBegin, int size){
        if(size == 0) return nullptr;

        TreeNode *root = new TreeNode(pre[preBegin]);
        if(size == 1) return root;// 这里是不同的点
        int leftRootVal = pre[preBegin + 1];// 若只有一侧，把该侧视为左子树
        int leftRootIndex = postBegin;
        while(post[leftRootIndex] != leftRootVal) leftRootIndex++;
        int leftSize = leftRootIndex - postBegin + 1;
        root->left = helper(pre, post, preBegin + 1, postBegin, leftSize);
        root->right = helper(pre, post, preBegin + leftSize + 1, postBegin + leftSize, size - leftSize - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return helper(pre, post, 0, 0, pre.size());
    }
};


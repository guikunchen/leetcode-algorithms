#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/find-the-duplicate-number/
/*给你一棵指定的二叉树，请你计算它最长连续序列路径的长度。

该路径，可以是从某个初始结点到树中任意结点，通过「父 - 子」关系连接而产生的任意路径。

这个最长连续的路径，必须从父结点到子结点，反过来是不可以的。
示例 1：
输入:

   1
    \
     3
    / \
   2   4
        \
         5

输出: 3
解析: 当中，最长连续序列是 3-4-5，所以返回结果为 3

示例 2：
输入:

   2
    \
     3
    / 
   2    
  / 
 1

输出: 2 
解析: 当中，最长连续序列是 2-3。注意，不是 3-2-1，所以返回 2。*/
class Solution {
    int maxlen = 1;
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return maxlen;
    }
    void dfs(TreeNode* root, int len)
    {
        if(!root) return;// 为空直接返回
        maxlen = max(maxlen, len);
        if(root->left) {
            if(root->val+1 == root->left->val)
                dfs(root->left, len+1);//满足连续，长度+1
            else
                dfs(root->left, 1);//不满足，重新开始
        }
        if(root->right) {
            if(root->val+1 == root->right->val)
                dfs(root->right, len+1);//满足连续，长度+1
            else
                dfs(root->right, 1);//不满足，重新开始
        }
    }
};
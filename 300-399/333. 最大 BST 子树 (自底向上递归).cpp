#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/largest-bst-subtree
/*给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，
其中最大指的是子树节点数最多的。
注意:
子树必须包含其所有后代。*/
class Solution {// 自底向上dfs
    int maxNode = 1;
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return maxNode;
    }

    vector<int> dfs(TreeNode* root)//返回子树min,max,node个数,是bst？
    {                               //       0   1    2       3
        if(!root) 
            return {INT_MAX, INT_MIN, 0, 1};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        bool bst = (l[3] && r[3] && l[1] < root->val && root->val < r[0]);
        //                           大于左闭的最大值     小于左边的最小值
        int node = l[2]+r[2]+1;
        int MAX = !root->right ? root->val : r[1],
            MIN = !root->left ? root->val : l[0];
        if(bst)
            maxNode = max(maxNode, node);
        return {MIN, MAX, node, bst};
    }
};
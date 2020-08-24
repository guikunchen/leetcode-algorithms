#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
/*给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25. */
class Solution {
public:
    // 修改了树的值，如果不允许修改的话可以用两个队列。
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        while(q.size())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left==NULL && cur->right==NULL) ans += cur->val;
            if(cur->left)
            {
                cur->left->val = cur->val * 10 + cur->left->val;
                q.push(cur->left);
            }
            if(cur->right)
            {
                cur->right->val = cur->val * 10 + cur->right->val;
                q.push(cur->right);                
            }
        }
        return ans;
    }
};
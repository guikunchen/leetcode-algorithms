#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/maximum-width-of-binary-tree/


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
    int widthOfBinaryTree(TreeNode* root) {// 宽度优先（层次遍历）
        if (root == nullptr) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;// 右边用无符号长整数是为了防止溢出，也可用double
        int ans = 1;
        q.push({root, 1});// 第一个节点编号为1
        while (!q.empty()) {
            int curLevelSize = q.size();
            ans = max(int(q.back().second - q.front().second + 1), ans);// 编号相减再加1
            for (int i=0; i < curLevelSize; i++) {
                TreeNode *node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();
                if (node->left) q.push({node->left, 2 * pos});
                if (node->right) q.push({node->right, 2 * pos + 1});
            }
        }
        return ans;
    }

    int widthOfBinaryTree(TreeNode* root) {// 深度优先
        if (root == nullptr) return 0;

        int ans = 1;
        map<int, unsigned long long> m;
        dfs(root, 1, 1, ans, m);
        return ans;
    }
    void dfs(TreeNode* node, int depth, unsigned long long pos, int &ans, map<int, unsigned long long> &m){
        if(node == nullptr) return;

        // insert只能插一次，如果已存在key不会覆盖
        m.insert(pair<int, unsigned long long>(depth, pos));// 记录每层最左的节点编号
        ans = max(ans, (int)(pos - m[depth] + 1));
        dfs(node->left, depth + 1, pos * 2, ans, m);
        dfs(node->right, depth + 1, pos * 2 + 1, ans, m);
    }
};
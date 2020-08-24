#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }

    // 前序遍历序列转化为字符串
    void dfs_s(TreeNode* root, string& res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs_s(root->left, res);
        dfs_s(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // 开始遍历索引
        int u = 0;
        return dfs_d(data, u);
    }

    TreeNode* dfs_d(string& data, int& u) {
        if (u >= data.size()) return NULL;
        if (data[u] == '#') {
            u += 2;
            return NULL;
        }
        int val = 0, sign = 1;
        if (data[u] == '-') sign = -1, u ++ ;
        while(data[u] != ','){val = val * 10 + data[u] - '0'; u++;}
        val *= sign; // 计算节点值
        u = u + 1 ;// 跳过逗号

        auto root = new TreeNode(val);
        root->left = dfs_d(data, u);// 先左后右，按前序遍历的顺序
        root->right = dfs_d(data, u);

        return root;
    }
};
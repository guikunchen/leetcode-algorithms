#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
// 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        vector<int> line;
        int left = 1;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front(); q.pop();
            line.push_back(tmp->val);
            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);
            if(--left == 0){
                // ans.insert(ans.begin(), line);// 可以直接在最前面插入
                ans.push_back(line);
                line.clear();
                left = q.size();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/path-sum-ii/
// 找到根节点到叶子节点的路径和为target

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    void findPath(TreeNode* root,int sum){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val==sum) ans.push_back(path);
        findPath(root->left,sum-root->val);
        findPath(root->right,sum-root->val);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findPath(root,sum);
        return ans;
    }
};
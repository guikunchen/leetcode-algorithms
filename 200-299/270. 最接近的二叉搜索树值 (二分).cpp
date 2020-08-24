#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/closest-binary-search-tree-value
/*给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的数值。
*/
class Solution {
    int ans = INT_MAX;
    double diff = LONG_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        if(!root) return 0;
        if(fabs(double(root->val) - target) < diff)
        {
            diff = fabs(double(root->val)-target);
            ans = root->val;
        }
        if(root->val > target)
            closestValue(root->left, target);
        else
            closestValue(root->right, target);
        return ans;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/house-robber-iii/ 第二题213 第一题198

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = dp(root);
        return max(res[0], res[1]);
    }
/* 返回一个大小为 2 的数组 arr
arr[0] 表示不抢 root 的话，得到的最大钱数
arr[1] 表示抢 root 的话，得到的最大钱数 */
    vector<int> dp(TreeNode* root) {
        if(!root) return {0, 0};

        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);

        int rob = left[0] + right[0] + root->val;// 抢，下家就不能抢了
        int noRob = max(left[0], left[1]) + max(right[0], right[1]);// 不抢，下家可抢可不抢，取决于收益大小

        return {noRob, rob}; 
    }
};
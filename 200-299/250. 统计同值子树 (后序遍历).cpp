#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/count-univalue-subtrees
/*给定一个二叉树，统计该二叉树数值相同的子树个数。
同值子树是指该子树的所有节点都拥有相同的数值。*/
class Solution {
    int count = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
    }
    bool dfs(TreeNode* root)// 后序遍历
    {
        if(!root) return true;
        bool l = dfs(root->left);//左子树都一样吗？
        bool r = dfs(root->right);
        if(!l || !r || (root->left && root->val != root->left->val) 
            ||(root->right && root->val != root->right->val))       
            return false;//左右子树有不一样 or root值跟左右不相等
        count++;
        return true;
    }

    int countUnivalSubtrees(TreeNode* root) {
        if(root == nullptr) return 0;

        helper(root, root->val);// 用后序遍历来求
        return count;
    }
    bool helper(TreeNode* root, int &val) {
        if(root->left == nullptr && root->right == nullptr) {
            val = root->val;
            count++;
            return true;
        } else if(root->left && root->right) {
            int left = 0, right = 1;
            bool same = helper(root->left, left) 
                && helper(root->right, right)
                && left == right 
                && root->val == left;
            if(same) {
                val = root->val;
                count++;
                return true;
            }
            return false;
        } else if(root->left) {
            int left = 0;
            bool same = helper(root->left, left) && left == root->val;
            if(same) {
                val = root->val;
                count++;
                return true;
            }
            return false;
        } else if(root->right) {
            int right = 0;
            bool same = helper(root->right, right) && right == root->val;
            if(same) {
                val = root->val;
                count++;
                return true;
            }
            return false;
        }
    }
};
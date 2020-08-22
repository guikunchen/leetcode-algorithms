// https://leetcode-cn.com/problems/sum-of-left-leaves/
// 递归或者BFS都可以
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=0;
        if(root->left!=NULL){
            if(root->left->left==NULL&&root->left->right==NULL)ans+=root->left->val;
            else ans+=sumOfLeftLeaves(root->left);
        }
        if(root->right!=NULL){
            ans+=sumOfLeftLeaves(root->right);
        }
        return ans;
    }
};
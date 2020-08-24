#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(true) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(--k == 0) return root->val;
            root = root->right;
        }
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/binary-search-tree-iterator/

class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        ldfs(root);
    }

    void ldfs(TreeNode* root) {
        while (root) {
            st.emplace(root);
            root = root->left;
        }
    }

    int next() {// 均摊复杂度只有O(1)
        TreeNode* root = st.top(); st.pop();
        ldfs(root->right);
        return root->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
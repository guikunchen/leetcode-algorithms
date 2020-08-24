#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// 节点可以作为自身的祖先节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* node = root;
        while(node != nullptr) {
        	if(p->val < node->val && q->val < node->val) {
        		node = node->left;
        	} else if(p->val > node->val && q->val > node->val) {
        		node = node->right;
        	} else {
        		return node;
        	}
        }
        return nullptr;
    }
};
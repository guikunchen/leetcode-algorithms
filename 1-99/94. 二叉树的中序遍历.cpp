#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){// 参考的，和前序遍历的循环条件是统一的
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {// 自己写的，有点笨，加了个flag控制
    	vector<int> ans;
    	if(root == NULL) return ans;

    	stack<TreeNode*> s;
    	s.push(root);
        bool flag = false;
    	while(!s.empty()){
    		TreeNode *tmp = s.top();
            if(tmp->left == NULL || flag){
                ans.push_back(tmp->val);
                s.pop();
                if(tmp->right != NULL){
                    s.push(tmp->right);
                    flag = false;
                }
                else{
                    flag = true;
                }
            }
    		else{
                while(tmp->left != NULL){
                    s.push(tmp->left);
                    tmp = tmp->left;
                }
            }
    	}
    	return ans;
    }
};
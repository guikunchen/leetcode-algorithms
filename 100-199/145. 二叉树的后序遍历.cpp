#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/


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
    vector<int> postorderTraversal(TreeNode* root) {// 以根、右子树、左子树的顺序遍历
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode *p = root;
        while(p || !s.empty()){
            while(p){
                ans.push_back(p->val);
                s.push(p->left);
                p = p->right;
            }
            p = s.top(); s.pop();
        }
        reverse(ans.begin(), ans.end());// 最后倒置
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root){// 空指针把父节点压住
        vector<int> ans;
        if(root == nullptr) return ans;

        TreeNode *p = root;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode *tmp = s.top();
            if(tmp == nullptr){
                s.pop();
                ans.push_back(s.top()->val);
                s.pop();
                continue;
            }
            s.push(nullptr);
            if(tmp->right != NULL) s.push(tmp->right);
            if(tmp->left != NULL) s.push(tmp->left);
        }
        
        return ans;
    }

    // TODO: 使用队列实现后序遍历

    // 还有一种方法是使用两个栈，一个栈以根、右、左的顺序进行访问，存到另一个栈中，跟逆序那个可以说是一样的。
};
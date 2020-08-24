#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/


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
	// [[3],[9,20],[7,8,15,7]]，这题需要vector嵌套vector，所以多了点步骤，但还是层次遍历。
	// 不需要nextLineSum记录，直接用quene.size即可。
    vector<vector<int>> levelOrder(TreeNode* root) {
    	vector<vector<int>> ans;
    	vector<int> curLine;
    	if(root == nullptr) return ans;
        queue<TreeNode*> q;
        int curLinesum = 1;
        int nextLinesum = 0;
        q.push(root);
        while(!q.empty()){
        	TreeNode* tmp = q.front(); q.pop();
        	curLine.push_back(tmp->val);
        	if(tmp->left != nullptr){
        		nextLinesum++;
        		q.push(tmp->left);
        	}
        	if(tmp->right != nullptr){
        		nextLinesum++;
        		q.push(tmp->right);
        	}
        	if(--curLinesum == 0){
        		ans.push_back(curLine);
        		curLine.clear();
        		curLinesum = nextLinesum;
        		nextLinesum = 0;
        	}
        }
        return ans;
    }
};
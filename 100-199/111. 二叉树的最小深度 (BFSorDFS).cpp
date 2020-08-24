#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

// 递归		
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;

        int ans = INT_MAX;
        if(root->left != nullptr) {
        	ans = min(minDepth(root->left), ans);
        }
        if(root->right != nullptr) {
        	ans = min(minDepth(root->right), ans);
        }
        return ans + 1;
    }
};

// 深度遍历或广度遍历，迭代求解

class Solution {
public:// BFS
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*, int> > queue;
        queue.push(make_pair(root, 1));
        while(!queue.empty()){
            TreeNode* node = queue.front().first;
            int depth = queue.front().second;
            queue.pop();
            if(!node->left && !node->right)
                return depth;
            if(node->left)
                queue.push(make_pair(node->left, depth + 1));
            if(node->right)
                queue.push(make_pair(node->right, depth + 1));
        }
        return 0;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/binary-tree-vertical-order-traversal/
// DFS和BFS都可以，最重要的是把横坐标当作key，所有深度放在vector里当作value

class Solution {// 只需记录x横坐标，存入map，从顶向下BFS层次遍历（保证从上到下的顺序）
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> q;
        int size, x, val;
        TreeNode *cur;
        q.push({root, 0});
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                cur = q.front().first;
                val = cur->val;
                x = q.front().second;
                q.pop();
                m[x].push_back(val);
                if(cur->left)
                    q.push({cur->left, x-1});
                if(cur->right)
                    q.push({cur->right, x+1});
            }
        }
        for(auto& mi : m)
            res.push_back(mi.second);
        return res;
    }
};
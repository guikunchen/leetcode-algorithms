#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/find-leaves-of-binary-tree 类似题156
/*给你一棵二叉树，请按以下要求的顺序收集它的全部节点：
依次从左到右，每次收集并删除所有的叶子节点
重复如上过程直到整棵树为空
示例:
输入: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    
输出: [[4,5,3],[2],[1]]
解释:
1. 删除叶子节点 [4,5,3] ，得到如下树结构：
          1
         / 
        2          
2. 现在删去叶子节点 [2] ，得到如下树结构：
          1          
3. 现在删去叶子节点 [1] ，得到空树：
          []         */

class Solution {// 按照树的高度（2侧子树的最大高度 + 1自己）来分组
    vector<vector<int>> ans;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root)
    {
        if(!root) return -1;
        int hl = dfs(root->left);
        int hr = dfs(root->right);
        int hcur = max(hl, hr) + 1;
        if(ans.size() <= hcur)
            ans.push_back({});
        ans[hcur].push_back(root->val);
        return hcur;
    }
};

class Solution {// 上下翻转二叉树再BFS
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    unordered_map<TreeNode*, int> map;//父节点底下挂着几个子节点
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        reverse(root);//上下翻转二叉树
        while(!q.empty())
        {
            int size = q.size(), i = 0;
            vector<int> lv(size);
            while(size--)
            {
                TreeNode *cur = q.front();
                q.pop();
                map[cur->left]--;//原父节点的子节点计数-1
                lv[i++] = cur->val;//当前值写入答案
                if(cur->left && map[cur->left]==0)//父节点计数为0，可以入队
                    q.push(cur->left);
            }
            ans.push_back(lv);
        }
        return ans;
    }
    TreeNode* reverse(TreeNode* root)
    {
        if(!root) return NULL;
        auto l = root->left;
        auto r = root->right;
        if(!l && !r)
            q.push(root);//叶子节点加入队列
        map[root] += (l?1:0) + (r?1:0);//记得加括号，子节点个数
        root->left = NULL;//断开子节点
        root->right = NULL;
        auto lc = reverse(l);
        auto rc = reverse(r);
        if(lc)
            lc->left = root;//子节点的left指向父节点
        if(rc)
            rc->left = root;
        return root;
    }
};
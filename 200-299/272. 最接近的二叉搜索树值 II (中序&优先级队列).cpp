#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/closest-binary-search-tree-value-ii/
/*给定一个不为空的二叉搜索树和一个目标值 target，请在该二叉搜索树中找到最接近目标值 target 的 k 个值。
注意：
给定的目标值 target 是一个浮点数
你可以默认 k 值永远是有效的，即 k ≤ 总结点数
题目保证该二叉搜索树中只会存在一种 k 个值集合最接近目标值
*/
struct cmp
{
    bool operator()(vector<double>& a, vector<double>& b)
    {
        return a[0] < b[0];//差值大的在上
    }
};
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> s;
        priority_queue<vector<double>, vector<vector<double>>, cmp> q;// 最大堆
        TreeNode* cur;
        while(root || !s.empty()) {// 使用stack，中序遍历bst，是有序的
            while(root) {
                s.push(root);
                root = root->left;
            } cur = s.top();
            s.pop();
            root = cur->right;
            if(q.size() < k)// 将差值最小的k个元素的<差值，自身值>插入优先队列
                q.push({fabs(cur->val - target), double(cur->val)});
            else if(q.size()==k && q.top()[0] > fabs(cur->val-target)) {
                //有更小的差值
                q.pop();
                q.push({fabs(cur->val-target), double(cur->val)});
            }
            if(q.size()==k && cur->val - target >= q.top()[0]) {
                // 队列满了k个，且差值大于堆顶，可以提前结束
                break;
            }
        }
        vector<int> ans(k);// 接下来从优先级队列里取出答案
        int i = 0;
        while(!q.empty())
        {
            ans[i++] = q.top()[1];
            q.pop();
        }
        return ans;
    }
};
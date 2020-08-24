#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/verify-preorder-sequence-in-binary-search-tree
/*给定一个整数数组，你需要验证它是否是一个二叉搜索树正确的先序遍历序列。
*/ // 也可以递归，序列划分为 根节点 左子树 右子树 三个部分  右边第一个大于根节点开始就是右子树

class Solution {// 单调栈
public:
    bool verifyPreorder(vector<int>& preorder) {
        if(preorder.size() <= 2) return true;
        int MIN = INT_MIN;
        stack<int> s;
        for(int i = 0; i < preorder.size(); ++i)
        {
            if(preorder[i] < MIN)
                return false;
            while(!s.empty() && s.top() < preorder[i])//遇到大的了，右分支
            {
                MIN = s.top();//记录弹栈的栈顶为最小值
                s.pop();
            }
            s.push(preorder[i]);
        }
        return true;
    }
};
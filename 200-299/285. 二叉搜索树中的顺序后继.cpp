#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/inorder-successor-in-bst
/*给你一个二叉搜索树和其中的某一个结点，请你找出该结点在树中顺序后继的节点。
结点 p 的后继是值比 p.val 大的结点中键值最小的结点。
*/
// 如果有右子树，右子树的最左边就是下一个节点。
// 如果没有，且该节点是父节点的左孩子，那答案就是父节点，如果是父节点的右孩子，那一直往上找，找到第一个节点的连接左孩子，就是答案。
class Solution {
public:// 循环版中序遍历，找到p节点后的下一个即是答案
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        stack<TreeNode*> stk;
        TreeNode *cur;
        bool found = false;
        while(root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            cur = stk.top();
            if(found)
                return cur;
            stk.pop();
            root = cur->right;
            if(cur == p)
                found = true;
        }
        return NULL;
    }
};
#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/validate-binary-search-tree/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;// 第一个数可能是INT_MIN，只能找更小的数，多增加判断会减少代码可读性

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树，严格单增不能相等！
            if (root -> val <= inorder) return false;
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};